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

void	sleep_if_not_dead(long time, char *msg, t_philo_list *entry)
{
	long	u_sec;

	pthread_mutex_lock(entry->print);
	if (*entry->rip == true)
	{
		pthread_mutex_unlock(entry->print);
		return ;
	}
	pthread_mutex_unlock(entry->print);
	u_sec = get_time();
	if (u_sec + time - entry->data->last_meal > entry->data->ttd)
	{
		u_sec = entry->data->last_meal + entry->data->ttd - u_sec;
		if (u_sec > 0)
		{
			my_print(msg, entry->id, entry, false);
			mili_sleep(u_sec);
		}
		die(entry);
		return ;
	}
	my_print(msg, entry->id, entry, false);
	mili_sleep(time);
}

void	think(long time, t_philo_list *entry)
{
	sleep_if_not_dead(time, "%ld %d is thinking\n", entry);
}

void	zzz(t_philo_list *entry)
{
	sleep_if_not_dead(entry->data->tts, "%ld %d is sleeping\n", entry);
}

void	die(t_philo_list *entry)
{
	pthread_mutex_lock(entry->print);
	if (*entry->rip == true)
	{
		pthread_mutex_unlock(entry->print);
		return ;
	}
	*entry->rip = true;
	pthread_mutex_unlock(entry->print);
	my_print("%ld %d died\n", entry->id, entry, true);
}
