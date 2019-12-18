/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:22:06 by alebross          #+#    #+#             */
/*   Updated: 2019/12/18 14:16:23 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnew(size_t size)
{
	char	*s;

	if (!(s = (char *)ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	s[size] = '\0';
	return (s);
}

char	*ft_strdup(char *src)
{
	char	*dest;

	if (!(dest = malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (0);
	dest = ft_strcpy(dest, src);
	return (dest);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*res;
	size_t		i;

	i = size * nmemb;
	if (!(res = malloc(i)))
		return (NULL);
	if (i == 0)
		return (res);
	while (i)
	{
		--i;
		*((unsigned char*)res + i) = 0;
	}
	return (res);
}
