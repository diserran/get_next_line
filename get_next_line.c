/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:35:29 by diserran          #+#    #+#             */
/*   Updated: 2022/08/16 13:14:08 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*result;
	char		*line;

	if (fd == -1 || BUFFER_SIZE < 0)
		return (NULL);
	ft_read_fd(fd, result);
	line = result;
	return (line);
}
