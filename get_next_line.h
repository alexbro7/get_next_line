/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:22:19 by alebross          #+#    #+#             */
/*   Updated: 2019/12/10 00:38:03 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strcpy(char *dest, char const *src);
int 	ft_strlen(char  const *str);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char const *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);

#endif
