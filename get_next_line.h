/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:22:19 by alebross          #+#    #+#             */
/*   Updated: 2019/12/20 16:25:53 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef	struct	s_gnl
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	int		ret;
	int		i;
	int		retval;
}				t_gnl;

int				ft_strlen(char *str);
int				get_next_line(int fd, char **line);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strnew(size_t size);
char			*ft_strchr(char *s, int c);
char			*ft_strdup(char *src);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
char			*get_next_line2(int fd, char **line, char *stock, t_gnl *gnl);
void			*ft_calloc(size_t nmemb, size_t size);

#endif
