/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:35:29 by diserran          #+#    #+#             */
/*   Updated: 2022/09/02 14:12:47 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*line;
	char		*result;

	if (fd == -1 || BUFFER_SIZE < 0)
		return (NULL);
	if (!line)
	{
		line = ft_read_fd(fd);
		result = ft_handle_line(fd);
	}
	else
	{
		result = (char *) malloc(sizeof(char) * ft_strlen(line));
		if (!result)
			return (NULL);
		//result = ft_handle_line(line);
	}
	result = ft_handle_line(line);
	return (result);
}
