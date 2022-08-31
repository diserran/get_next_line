/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:35:44 by diserran          #+#    #+#             */
/*   Updated: 2022/08/31 23:16:09 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen(s1);
	str = malloc(sizeof(*s1) * ((len_s1 + ft_strlen(s2)) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[len_s1] = s2[i];
		i++;
		len_s1++;
	}
	str[len_s1] = '\0';
	return (str);
}

char	*ft_read_fd(int fd)
{
	int		reader;
	int		i;
	int		byte_num;
	char	*buffer;
	char	*saved;

	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE));
	saved = (char *) malloc(sizeof(char) * (BUFFER_SIZE));
	if (!buffer || !saved)
		return (NULL);
	reader = 1;
	byte_num = 0;
	i = 0;
	while (reader != 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		byte_num += reader;
		if (reader == -1)
		{
			free(buffer);
			return (NULL);
		}
		saved = ft_strjoin(saved, buffer);
		while (saved[i])
		{
			if (saved[i] == '\n')
				return (ft_handle_line(saved, byte_num));
			i++;
		}
	}
	return (ft_handle_line(saved, byte_num));
}

char	*ft_handle_line(char *str, int byte_num)
{
	int		i;
	char	*result;

	result = (char *) malloc(sizeof(char) * byte_num);
	if (!str || !byte_num || !result)
		return (NULL);
	i = 0;
	while (i < byte_num)
	{
		result[i] = str[i];
		i++;
	}
	return (result);
}
