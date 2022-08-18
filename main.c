/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:39:17 by diserran          #+#    #+#             */
/*   Updated: 2022/08/18 12:50:28 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test_files/42_no_nl", O_RDONLY);
	//printf("File descriptor: %d\n", fd);
	//printf("Buffer: %d\n", BUFFER_SIZE);
	str = get_next_line(fd);
	//printf("Readed line: %s\n", str);
	close(fd);
	return (0);
}
