/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   not_libft.h                                            :+:    :+:            */
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
# include <zconf.h>

size_t	ft_strlen(const char *c);
char	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
int		ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str, int *success);
int		ft_isdigit(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char const *s, char c);
int		ft_putnbr_fd(long n, int fd);
int		ft_printf_va(int fd, const char *str, va_list ap);
int		ft_printf(int fd, pthread_mutex_t *mutex, const char *str, ...);
char	*ft_itoa(long n);
int		ft_putchar_fd(char c, int fd);
#endif
