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

#include "philo_load/philo_load.h"
#include "philo_list/philo_list.h"
#include "functions/util.h"
#include <pthread.h>
#include <printf.h>

void	*philo_thread(void *arg)
{
	t_philo_list	*entry;

	entry = arg;
	entry->data->last_meal = get_time();
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
	entry = *top;
	if (entry != NULL)
		entry->stuff->start = get_time();
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
	return (TRUE);
}

void	start_philo(int len, char **args, int amount_philo)
{
	t_philo_list	**philo_top;
	t_stuff			stuff;

	if (pthread_mutex_init(&stuff.print, NULL))
	{
		printf("Error, unable to initialize print mutex.\n");
		return ;
	}
	stuff.rip = FALSE;
	philo_top = load_philos(load_philo_data(len, args), amount_philo, &stuff);
	if (philo_top == NULL)
		return ;
	if (init_mutex(philo_top) == FALSE)
	{
		free_philo_list(philo_top, FALSE);
		printf("Error, starting threads\n");
		return ;
	}
	free_philo_list(philo_top, TRUE);
}

int	main(int len, char **args)
{
	int			success;
	int			amount_philo;

	if (len != 5 && len != 6)
	{
		printf("Invalid argument length, got %d expected 5 or 6\n", len);
		return (0);
	}
	amount_philo = ft_atoi(args[1], &success);
	if (!success)
	{
		printf("Error, out of mem\n");
		return (0);
	}
	if (amount_philo <= 0)
	{
		printf("Error, there has to be at least one philosopher.\n");
		return (0);
	}
	start_philo(len, args, amount_philo);
	return (0);
}
