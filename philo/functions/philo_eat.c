/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_eat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 18:57:40 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/20 18:57:40 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo_structs.h"
#include "util.h"
#include <pthread.h>

static t_bool	am_i_dead(t_philo_list *entry)
{
	if (check_death(entry) == TRUE)
		return (TRUE);
	if (time_to_death(entry) < 0)
	{
		die(entry);
		return (TRUE);
	}
	return (FALSE);
}

int	take_fork(pthread_mutex_t *fork, t_philo_list *entry)
{
	pthread_mutex_lock(fork);
	if (am_i_dead(entry))
	{
		pthread_mutex_unlock(fork);
		return (1);
	}
	my_print("%ld %d has taken a fork\n", entry->id, entry);
	return (0);
}

void	eat(t_philo_list *entry)
{
	long	last_meal;

	if (am_i_dead(entry))
		return ;
	if (take_fork(entry->data->left_fork, entry))
		return ;
	if (entry->data->left_fork == &entry->data->right_fork)
	{
		pthread_mutex_unlock(entry->data->left_fork);
		mili_sleep(entry->data->ttd);
		die(entry);
		return ;
	}
	if (take_fork(&entry->data->right_fork, entry))
	{
		pthread_mutex_unlock(entry->data->left_fork);
		return ;
	}
	last_meal = my_print("%ld %d is eating\n", entry->id, entry);
	set_last_meal(entry, last_meal);
	if (last_meal == -1)
		return ;
	mili_sleep(entry->data->tte);
	pthread_mutex_unlock(entry->data->left_fork);
	pthread_mutex_unlock(&entry->data->right_fork);
}
