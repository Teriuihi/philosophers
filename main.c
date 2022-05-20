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

	entry = arg;
	my_print("%ld started %d\n", entry->id, entry, false);
	entry->data->last_meal = get_time();
	if (entry->id % 2 == 0)
		think(entry->data->ttd / 2, entry);
	while (1)
	{
		pthread_mutex_lock(entry->print);
		if (*entry->rip == true)
		{
			pthread_mutex_unlock(entry->print);
			break ;
		}
		pthread_mutex_unlock(entry->print);
		eat(entry);
		if (entry->data->amount_eat > 0)
			entry->data->amount_eat--;
		if (entry->data->amount_eat == 0)
			return (NULL);
		zzz(entry);
		think(entry->data->tte / 2, entry);
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
		entry = entry->next;
	}
	entry = *top;
	if (entry != NULL)
		*entry->start = get_time();
	while (entry)
	{
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
	pthread_mutex_t	print;

	if (len != 5 && len != 6)
		return (msg_bool(true,
				"Invalid argument length, got %d expected 5 or 6\n", len));
	amount_philo = ft_atoi(args[1], &success);
	if (!success)
		return (msg_bool(true, "Error, out of mem\n"));
	if (pthread_mutex_init(&print, NULL))
		return (msg_bool(true, "Error, unable to initialize print mutex.\n"));
	rip = false;
	philo_top = load_philos(load_philo_data(len, args),
			amount_philo, &rip, &print);
	if (philo_top == NULL)
		return (1);
	if (init_mutex(philo_top) == false)
		return (msg_bool(true, "Error, starting threads\n"));
	free_philo_list(philo_top);
	return (0);
}
