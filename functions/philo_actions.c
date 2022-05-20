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

#include <printf.h>
#include "../headers/philo_structs.h"
#include "util.h"

void	sleep_if_not_dead(long time, char *msg, t_philo_list *entry)
{
	long	u_sec;

	if (check_death(entry) == TRUE)
		return ;
	u_sec = get_time();
	if (u_sec + time - entry->data->last_meal > entry->data->ttd)
	{
		u_sec = entry->data->last_meal + entry->data->ttd - u_sec;
		if (u_sec > 0)
		{
			my_print(msg, entry->id, entry);
			mili_sleep(u_sec);
		}
		die(entry);
		return ;
	}
	my_print(msg, entry->id, entry);
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
	pthread_mutex_lock(&(entry->stuff->print));
	if (entry->stuff->rip == TRUE)
	{
		pthread_mutex_unlock(&(entry->stuff->print));
		return ;
	}
	entry->stuff->rip = TRUE;
	printf("%p ", &(entry->stuff->print));
	printf("%ld %d died\n", get_time() - entry->stuff->start, entry->id);
	pthread_mutex_unlock(&(entry->stuff->print));
}
