/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_load.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 15:25:15 by sappunn       #+#    #+#                 */
/*   Updated: 2022/02/07 15:25:15 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_LOAD_H
# define PHILO_LOAD_H
# include "../philo_list/philo_list.h"

t_philo			*load_philo_data(int len, char **args);
t_philo_list	**load_philos(t_philo *data, int amount_philo, t_stuff *stuff);
#endif
