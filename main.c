/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diserran <diserran@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:39:17 by diserran          #+#    #+#             */
/*   Updated: 2022/09/01 22:11:43 by diserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test_files/alternate_line_nl_no_nl", O_RDONLY);
	//fd = open("test_files/43_no_nl", O_RDONLY);
	line = "";
	//while (line != NULL)
	//{
		line = get_next_line(fd);
		printf("%s", line);
	//}
	fd = close(fd);
	return (0);
}
