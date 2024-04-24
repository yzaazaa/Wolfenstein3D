/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:25:53 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/04/09 04:23:19 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

void	puterr(char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char const *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim_free(char const *s1, char const *set);
char	*str_empty(void);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(char *s1);
int		is_empty_line(char *str);
int		get_r(int rgb);
int		get_g(int rgb);
int		get_b(int rgb);

#endif