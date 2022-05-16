/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/16 16:25:37 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/16 16:25:37 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo_structs.h"
#include "util.h"
#include <pthread.h>
#include <unistd.h>
#include "stdio.h"

static void	slep(long sleep)
{
	long	time;

	time = get_time() + sleep;
	while (time <= get_time())
		usleep(1);
}

void	think(long time, t_philo_list *entry)
{
	if (*entry->data->rip == true)
		return ;
	printf("%ld %d is thinking\n", get_time(), entry->id);
	slep(time);
}

void	eat(t_philo_list *entry)
{
	long	usec;

	if (*entry->data->rip == true)
		return ;
	if (get_time() - entry->data->last_meal > entry->data->ttd)
	{
		die(entry);
		return ;
	}
	pthread_mutex_lock(&entry->data->left_fork->mutex);
	if (*entry->data->rip == true)
	{
		pthread_mutex_unlock(&entry->data->left_fork->mutex);
		return ;
	}
	printf("%ld %d has taken a fork\n", get_time(), entry->id);
	pthread_mutex_lock(&entry->data->right_fork.mutex);
	if (*entry->data->rip == true)
	{
		pthread_mutex_unlock(&entry->data->left_fork->mutex);
		pthread_mutex_unlock(&entry->data->right_fork.mutex);
		return ;
	}
	printf("%ld %d has taken a fork\n", get_time(), entry->id);
	usec = get_time();
	if (usec - entry->data->last_meal > entry->data->ttd)
	{
		die(entry);
		pthread_mutex_unlock(&entry->data->left_fork->mutex);
		pthread_mutex_unlock(&entry->data->right_fork.mutex);
		return ;
	}
	entry->data->last_meal = usec;
	printf("%ld %d is eating for %ld milliseconds\n", usec, entry->id, entry->data->tte);
	slep(entry->data->tte);
	long ex = get_time();
	printf("%d released fork %d after %ld %ld\n", entry->id, pthread_mutex_unlock(&entry->data->left_fork->mutex), get_time() - usec, get_time() - ex);
	printf("%d released fork %d after %ld %ld\n", entry->id, pthread_mutex_unlock(&entry->data->right_fork.mutex), get_time() - usec, get_time() - ex);
}

void	zzz(t_philo_list *entry)
{
	long	usec;
	long	tmp;

	if (*entry->data->rip == true)
		return ;
	usec = get_time();
	if (usec + entry->data->tts - entry->data->last_meal > entry->data->ttd)
	{
		tmp = entry->data->last_meal + entry->data->ttd - usec;
		if (tmp > 0)
		{
			printf("%ld %d is sleeping\n", get_time(), entry->id);
			slep(tmp);
		}
		die(entry);
		return ;
	}
	slep(entry->data->tts);
}

void	die(t_philo_list *entry)
{
	if (*entry->data->rip == true)
		return ;
	*entry->data->rip = true;
	printf("%ld %d died\n", get_time(), entry->id);
}
