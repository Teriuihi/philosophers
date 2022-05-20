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

typedef struct s_philo
{
	long			ttd;
	long			tte;
	long			tts;
	long			last_meal;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	*left_fork;
	pthread_t		thread;
	int				amount_eat;
}	t_philo;

#endif
