/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:20:11 by alebross          #+#    #+#             */
/*   Updated: 2019/12/18 10:34:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	char *str;

	str = (char*)s;
	while (*str)
	{
		if ((char)c == *str)
			return (str);
		str++;
	}
	if ((char)c == '\0')
		return (str);
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;

	dest = ft_strnew(len);
	if (!s || !dest)
		return (NULL);
	i = 0;
	while (i < (unsigned int)len && s[start + i])
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	dest = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!dest)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[++j])
		dest[i + j] = s2[j];
	dest[i + j] = '\0';
	return (dest);
}

char	*get_next_line2(int fd, char **line, char *stock, t_gnl *gnl)
{
 	gnl->i = 0;
	while (stock[gnl->i] && stock[gnl->i] != '\n')
		gnl->i++;
	*line = ft_substr(stock, 0, gnl->i);
	if (stock[0])
	{
		gnl->tmp = stock;
		stock = ft_strdup(stock + gnl->i + 1);
		free(gnl->tmp);
	}
	gnl->retval = !ft_strlen(stock) && !read(fd, gnl->buff, 1) ? 0 : 1;
	free(gnl->buff);
	return (stock);
}

int		get_next_line(int fd, char **line)
{
	static char		*stock;
	t_gnl			gnl;

	if (fd <= 0 || !line || !(gnl.buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	gnl.ret = 1;
	gnl.buff[0] = 0;
	if (!stock)
	{
		if (!(stock = malloc(sizeof(char))))
			return (-1);
		stock[0] = 0;
	}
	while (!ft_strchr(stock, '\n') && (gnl.ret = read(fd, gnl.buff, BUFFER_SIZE)))
	{
		gnl.buff[gnl.ret] ='\0';
		if(stock)
			gnl.tmp = stock;
		stock = ft_strjoin(stock, gnl.buff);
		if (gnl.tmp)
			free(gnl.tmp); 
	}
	stock = get_next_line2(fd, line, stock, &gnl);
	if (!gnl.retval)
		free(stock);
	return (gnl.retval);
}
