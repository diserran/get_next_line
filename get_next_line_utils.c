/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:35:44 by diserran          #+#    #+#             */
/*   Updated: 2022/08/16 13:13:27 by diserran         ###   ########.fr       */
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


char	*ft_read_fd(int fd, char *result)
{
	int		reader;
	char	*buffer;

	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	reader = read(fd, buffer, BUFFER_SIZE);
	if (reader == -1)
	{
		free(buffer);
		return (NULL);
	}
	ft_strjoin(result, buffer);
	return (buffer);
}
