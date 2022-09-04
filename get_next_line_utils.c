/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:35:44 by diserran          #+#    #+#             */
/*   Updated: 2022/09/04 02:26:54 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
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

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned int	i;

	str = (char *) s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	if (str[i] == (unsigned char)c)
		return (&str[i]);
	return (NULL);
}

char	*ft_read_fd(int fd)
{
	int		reader;
	char	*buffer;
	char	*saved;

	saved = (char *) malloc(sizeof(char) * (BUFFER_SIZE));
	if (!saved)
		return (NULL);
	reader = 1;
	while (reader != 0)
	{
		buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE));
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buffer);
			return (NULL);
		}
		saved = ft_strjoin(saved, buffer);
		if (ft_strchr(saved, '\n'))
			return (saved);
		free(buffer);
	}
	return (saved);
}

char	*ft_handle_line(char *str)
{
	char	*line;
	int		str_len;
	int		i;

	str_len = ft_strlen(str);
	i = 0;
	line = (char *) malloc(sizeof(char) * str_len);
	while (i < str_len)
	{
		line[i] = str[i];
		if (line[i] == '\n')
			return (line);
		i++;
	}
	return (line);
}
