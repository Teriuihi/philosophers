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
# include "structs.h"

t_philo_data	*load_philo_data(int len, char **args);
t_philo			**load_philos(t_philo_data *data, int amount_philo);
#endif
