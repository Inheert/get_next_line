/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:09:07 by tclaereb          #+#    #+#             */
/*   Updated: 2024/01/18 17:58:57 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("./nl", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (line)
		{
			printf("%s", line);
			free(line);
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
