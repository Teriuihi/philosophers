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
#include <stdio.h>

int	take_fork(pthread_mutex_t *fork, t_philo_list *entry)
{
	if (pthread_mutex_lock(fork))
	{
		printf("Error, unable to lock mutex\n");
		*entry->rip = true;
		return (-1);
	}
	pthread_mutex_lock(entry->print);
	if (*entry->rip == true)
	{
		pthread_mutex_unlock(entry->print);
		if (pthread_mutex_unlock(fork))
		{
			printf("Error, unable to unlock mutex\n");
			pthread_mutex_lock(entry->print);
			*entry->rip = true;
			pthread_mutex_unlock(entry->print);
			return (-1);
		}
		return (1);
	}
	pthread_mutex_unlock(entry->print);
	if (get_time() - entry->data->last_meal > entry->data->ttd)
	{
		die(entry);
		pthread_mutex_unlock(fork);
		return (1);
	}
	my_print("%ld %d has taken a fork\n", entry->id, entry, false);
	return (0);
}

void	eat(t_philo_list *entry)
{
	pthread_mutex_lock(entry->print);
	if (*entry->rip == true)
	{
		pthread_mutex_unlock(entry->print);
		return ;
	}
	pthread_mutex_unlock(entry->print);
	if (get_time() - entry->data->last_meal > entry->data->ttd)
	{
		die(entry);
		return ;
	}
	if (take_fork(&entry->data->left_fork->mutex, entry))
		return ;
	if (take_fork(&entry->data->right_fork.mutex, entry))
	{
		pthread_mutex_unlock(&entry->data->left_fork->mutex);
		return ;
	}
	entry->data->last_meal = my_print("%ld %d is eating\n", entry->id, entry,
			false);
	if (entry->data->last_meal == -1)
		return ;
	mili_sleep(entry->data->tte);
	if (pthread_mutex_unlock(&entry->data->left_fork->mutex)
		|| pthread_mutex_unlock(&entry->data->right_fork.mutex))
	{
		printf("Error, unable to unlock mutex\n");
		pthread_mutex_lock(entry->print);
		*entry->rip = true;
		pthread_mutex_unlock(entry->print);
		return ;
	}
}
