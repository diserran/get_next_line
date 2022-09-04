/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:35:29 by diserran          #+#    #+#             */
/*   Updated: 2022/09/04 02:23:46 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*line;
	char		*result;
	size_t		line_len;
	size_t		i;
	size_t		j;

	if (fd == -1 || BUFFER_SIZE < 0)
		return (NULL);
	if (!line)
		line = ft_read_fd(fd);
	if (!ft_strchr(line, '\n'))
		line = ft_strjoin(line, ft_read_fd(fd));
	result = ft_handle_line(line);
	i = ft_strlen(result);
	j = 0;
	line_len = ft_strlen(line);
	if (line_len == 0)
		return (NULL);
	while (i < line_len)
		line[j++] = line[i++];
	line[j] = '\0';
	return (result);
}
