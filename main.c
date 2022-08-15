/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:39:17 by diserran          #+#    #+#             */
/*   Updated: 2022/08/15 20:32:44 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		buffer_size = 42;
	char	*str;
	
	str = (char *) malloc(sizeof(char) * buffer_size);
	fd = open("42", O_RDONLY);
	printf("File descriptor: %d\n", fd);
	printf("Buffer: %d\n", buffer_size);
	read(fd, str, buffer_size);
	printf("Archivo: %s\n", str);
	return (0);
}
