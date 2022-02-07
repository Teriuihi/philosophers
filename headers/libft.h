/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 21:30:42 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 21:30:42 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>

size_t	ft_strlen(const char *c);
char	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
int		ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str, int *success);
int		ft_isdigit(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char const *s, char c);
#endif
