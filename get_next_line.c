/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:17:55 by tclaereb          #+#    #+#             */
/*   Updated: 2024/01/18 18:06:00 by tclaereb         ###   ########.fr       */
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
	char	*new_ptr;
	char	*new_line;
	int		len;

	if (!*ptr)
		return (NULL);
	if (nl == -1)
		nl = ft_strlen(*ptr) - 1;
	len = ft_strlen(*ptr);
	new_line = ft_substr(*ptr, 0, nl + 1);
	if (!new_line)
		return (free(*ptr), NULL);
	new_ptr = ft_substr(*ptr, nl + 1, len);
	if (!new_ptr)
		return (free(*ptr), free(new_line), NULL);
	else if (len - nl <= 1)
	{
		free(new_ptr);
		free(*ptr);
		*ptr = NULL;
		return (new_line);
	}
	free(*ptr);
	*ptr = new_ptr;
	return (new_line);
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
		return (free(ptread), free(*ptr), -1);
	free(*ptr);
	free(ptread);
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
			if ((rd <= 0 && ft_strlen(ptr) < 1) || rd == -1)
			{
				free(ptr);
				ptr = NULL;
				return (NULL);
			}
			else if (rd <= 0 && ft_strlen(ptr) >= 1)
				break ;
		}
		else
			break ;
	}
	return (get_new_line(nl, &ptr));
}
