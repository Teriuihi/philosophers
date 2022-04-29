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
# include "../headers/bool.h"
# include "../philo_list/philo_list.h"

t_bool	msg_bool(t_bool t_bool, char *str, ...);
void	*msg_ptr(void *ptr, char *str, ...);
void	free_philo_list(t_philo_list **top);
#endif
