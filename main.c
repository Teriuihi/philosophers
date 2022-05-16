/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/29 19:29:42 by sappunn       #+#    #+#                 */
/*   Updated: 2022/04/29 19:29:42 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "load_philosophers/philo_load.h"
#include "philo_list/philo_list.h"
#include "not_libft/not_libft.h"
#include "functions/util.h"
#include <pthread.h>

void	*philo_thread(void *arg)
{
	t_philo_list	*entry;
	long			usec;

	entry = arg;
	usleep(entry->id * 50);
	if (entry->data->tte > entry->data->tts)
		usec = entry->data->tte - entry->data->tts;
	else
		usec = 1;
	if (entry->id % 2 == 0)
		think(entry->data->ttd / 2, entry);
	while (*entry->data->rip == false)
	{
		eat(entry);
		if (entry->data->amount_eat > 0)
			entry->data->amount_eat--;
		if (entry->data->amount_eat == 0)
			return (NULL);
		zzz(entry);
		think(usec, entry);
	}
	return (NULL);
}

t_bool	init_mutex(t_philo_list **top)
{
	t_philo_list	*entry;

	entry = *top;
	while (entry)
	{
		if (pthread_mutex_init(&entry->data->right_fork.mutex, NULL) != 0)
			return (false);
		pthread_create(&entry->data->thread, NULL, philo_thread, entry);
		entry = entry->next;
	}
	entry = *top;
	while (entry)
	{
		pthread_join(entry->data->thread, NULL);
		entry = entry->next;
	}
	return (true);
}

int	main(int len, char **args)
{
	int				success;
	int				amount_philo;
	t_philo_list	**philo_top;
	t_bool			rip;

	if (len != 5 && len != 6)
		return (msg_bool(true,
				"Invalid argument length, got %d expected 5 or 6\n", len));
	amount_philo = ft_atoi(args[1], &success);
	if (!success)
		return (msg_bool(true, "Error, out of mem\n"));
	philo_top = load_philos(load_philo_data(len, args, &rip), amount_philo);
	if (philo_top == NULL)
		return (1);
	if (init_mutex(philo_top) == false)
		return (msg_bool(true, "Error, starting threads\n"));
	free_philo_list(philo_top);
	return (0);
}
