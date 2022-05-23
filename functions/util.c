/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 15:23:18 by sappunn       #+#    #+#                 */
/*   Updated: 2022/02/07 15:23:18 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/bool.h"
#include "../philo_list/philo_list.h"
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

long	get_time(void)
{
	struct timeval	ct;

	if (gettimeofday(&ct, NULL) != 0)
		return (0);
	return (ct.tv_sec * 1000 + ct.tv_usec / 1000);
}

long	my_print(char *str, int id, t_philo_list *entry)
{
	long	time;

	pthread_mutex_lock(&(entry->stuff->print));
	if (entry->stuff->rip == TRUE)
	{
		pthread_mutex_unlock(&(entry->stuff->print));
		return (-1);
	}
	time = get_time();
	printf(str, time - entry->stuff->start, id);
	pthread_mutex_unlock(&(entry->stuff->print));
	return (time);
}

void	mili_sleep(long sleep)
{
	long	time;

	time = get_time() + sleep;
	while (time > get_time())
		usleep(50);
}

t_bool	check_death(t_philo_list *entry)
{
	t_bool	result;

	pthread_mutex_lock(&(entry->stuff->print));
	result = entry->stuff->rip;
	pthread_mutex_unlock(&(entry->stuff->print));
	return (result);
}
