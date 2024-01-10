/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:17:52 by tclaereb          #+#    #+#             */
/*   Updated: 2024/01/10 16:35:36 by tclaereb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*new_s;
	int		i;

	new_s = ft_calloc(len - start + 1, sizeof(char));
	if (!new_s)
		return (NULL);
	i = 0;
	while (start < len && s[start])
	{
		new_s[i] = s[start];
		i++;
		start++;
	}
	return (new_s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	ls1;
	size_t	ls2;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (s2);
	else if (!s2)
		return (s1);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	s = ft_calloc(ls1 + ls2 + 1, sizeof(char));
	if (!s)
		return (NULL);
	while (*s1)
		*s++ = *s1++;
	while (*s2)
		*s++ = *s2++;
	free(s1 - ls1);
	free(s2 - ls2);
	return (s - ls1 - ls2);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	size_max;
	size_t	i;

	size_max = (size_t)-1;
	if (nmemb == 0 || size == 0)
		return (NULL);
	if (size != 0)
		if (nmemb > size_max / size)
			return (NULL);
	ptr = (char *)malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
		ptr[i++] = '\0';
	return (ptr);
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
