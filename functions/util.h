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

long	get_time(void);
t_bool	msg_bool(t_bool t_bool, char *str, ...);
void	*msg_ptr(void *ptr, char *str, ...);
void	free_philo_list(t_philo_list **top);
void	think(long time, t_philo_list *entry);
void	eat(t_philo_list *entry);
void	zzz(t_philo_list *entry);
void	die(t_philo_list *entry);
long	my_print(char *str, int id, t_philo_list *entry, t_bool print);
void	mili_sleep(long sleep);
#endif
