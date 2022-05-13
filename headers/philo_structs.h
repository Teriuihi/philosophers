/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   internal.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 19:19:13 by sappunn       #+#    #+#                 */
/*   Updated: 2022/01/28 19:19:13 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCTS_H
# define PHILO_STRUCTS_H
# include <time.h>
# include <pthread.h>
# include "fork_struct.h"

typedef struct s_philo
{
	time_t		ttd;
	time_t		tte;
	time_t		tts;
	time_t		last_meal;
	t_fork		right_fork;
	t_fork		*left_fork;
	pthread_t	thread;
	int			amount_eat;
}	t_philo;

#endif
