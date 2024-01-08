/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:17:55 by tclaereb          #+#    #+#             */
/*   Updated: 2024/01/08 16:42:20 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_new_line(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i] && ptr[i] != '\n')
		i++;
	if (ptr[i] != '\n')
		i = -1;
	return (i);
}

char	*get_new_line(int nl, char	**ptr)
{
	char	*new_line;

	new_line = ft_calloc(nl + 1, sizeof(char));
}

int	read_file(int fd, char **ptr)
{
	char	*ptread;
	char	*buffer;
	int		i;

	ptread = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!ptread)
		return (-1);
	i = read(fd, ptread, BUFFER_SIZE);
	if (i == -1)
		return(free(ptread), i);
	buffer = ft_strjoin(*ptr, ptread);
	if (!buffer)
		return (free(ptread), -1);
	*ptr = buffer;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	int 		nl;
	int			rd;

	if (!ptr)
	{
		ptr = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!ptr)
			return (NULL);
	}
	while (1)
	{
		nl = find_new_line(ptr);
		if (nl == -1)
		{
			rd = read_file(fd, &ptr);
			if (rd == -1)
				return (free(ptr), NULL);
		}
		else
			break ;
	}
	return (ptr);
}
