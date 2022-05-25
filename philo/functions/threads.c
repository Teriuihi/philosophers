/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 15:23:18 by sappunn       #+#    #+#                 */
/*   Updated: 2022/02/07 15:23:18 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_load/philo_load.h"
#include "../functions/util.h"
#include <pthread.h>

static void	*monitor_thread(void *arg)
{
	t_philo_list	*entry;
	t_bool			running;

	running = TRUE;
	entry = arg;
	while (running)
	{
		while (entry && running)
		{
			if (time_to_death(entry) < 0)
			{
				die(entry);
				running = FALSE;
			}
			else
				entry = entry->next;
		}
		entry = arg;
		if (check_death(entry) == TRUE)
			running = FALSE;
		else
			mili_sleep(5);
	}
	return (NULL);
}

static void	*philo_thread(void *arg)
{
	t_philo_list	*entry;

	entry = arg;
	set_last_meal(entry, get_time());
	if (entry->id % 2 == 1)
		think(entry->data->tte / 2, entry);
	while (check_death(entry) == FALSE)
	{
		eat(entry);
		if (entry->data->amount_eat > 0)
			entry->data->amount_eat--;
		if (entry->data->amount_eat == 0)
			return (NULL);
		zzz(entry);
		think(0, entry);
	}
	return (NULL);
}

static void	run_threads(t_philo_list **top)
{
	t_philo_list	*entry;

	entry = *top;
	entry->stuff->start = get_time();
	while (entry)
	{
		pthread_create(&entry->data->thread, NULL, philo_thread, entry);
		entry = entry->next;
	}
	pthread_create(&((*top)->stuff->monitor), NULL, monitor_thread, *top);
	entry = *top;
	while (entry)
	{
		pthread_join(entry->data->thread, NULL);
		entry = entry->next;
	}
	pthread_join((*top)->stuff->monitor, NULL);
}

t_bool	init_mutex(t_philo_list **top)
{
	t_philo_list	*entry;

	entry = *top;
	while (entry)
	{
		if (pthread_mutex_init(&entry->data->right_fork, NULL) != 0)
			return (FALSE);
		entry = entry->next;
	}
	run_threads(top);
	return (TRUE);
}
