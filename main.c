/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:09:07 by tclaereb          #+#    #+#             */
/*   Updated: 2024/01/12 16:56:40 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>

int	main(void)
{
	int		loop;
	int		fd;
	char	*line;

	fd = open("./test.txt", O_RDONLY);
	loop = 15;
	while (loop != 0)
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("%s\n", line);
			free(line);
		}
		loop--;
	}
	close(fd);
	return (0);
}
