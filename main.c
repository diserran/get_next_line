/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:39:17 by diserran          #+#    #+#             */
/*   Updated: 2022/09/04 02:28:34 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	//fd = open("test_files/alternate_line_nl_no_nl", O_RDONLY);
	fd = open("test_files/43_no_nl", O_RDONLY);
	line = "";
	i = 1;
	while (line != NULL)
	{
		line = get_next_line(fd);
		//printf("----------------------------------------");
		printf("Line %d %s", i++, line);
	}
	fd = close(fd);
	return (0);
}
