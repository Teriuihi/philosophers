/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 15:24:36 by sappunn       #+#    #+#                 */
/*   Updated: 2022/02/07 15:24:36 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H
# include <pthread.h>
# include "../headers/bool.h"
# include "../philo_list/philo_list.h"
# include <stdlib.h>

long	get_time(void);
void	free_philo_list(t_philo_list **top, t_bool destroy_mutex);
void	think(long time, t_philo_list *entry);
void	eat(t_philo_list *entry);
void	zzz(t_philo_list *entry);
void	die(t_philo_list *entry);
long	my_print(char *str, int id, t_philo_list *entry);
void	mili_sleep(long sleep);
char	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str, int *success);
int		ft_isdigit(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
t_bool	check_death(t_philo_list *entry);
long	time_to_death(t_philo_list *entry);
long	get_last_meal(t_philo_list *entry);
void	set_last_meal(t_philo_list *entry, long time);
t_bool	init_mutex(t_philo_list **top);
#endif
