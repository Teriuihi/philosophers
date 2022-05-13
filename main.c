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
#include <stdio.h>

void	*philo_thread(void *arg)
{
	t_data	*data;

	data = arg;
//	while (data->entry->data->left_fork->in_use)
//		sleep(1);
//	while (pthread_mutex_lock(&data->entry->data->left_fork->mutex) != 0)
//		sleep(1);
//	while (pthread_mutex_lock(&data->entry->data->right_fork.mutex) != 0)
//		sleep(1);
	ft_printf(1, data->print, "created philo %d %p\n", data->entry->id, data->print);
//	pthread_mutex_unlock(&data->entry->data->left_fork->mutex);
//	pthread_mutex_unlock(&data->entry->data->right_fork.mutex);
	return (NULL);
}

t_bool	init_mutex(t_philo_list *entry, pthread_mutex_t	*print)
{
	t_data	*data;

	while (entry)
	{
		data = ft_calloc(sizeof(t_data), 1);
		if (data == NULL)
			return (false);
		data->print = print;
		data->entry = entry;
		if (pthread_mutex_init(&entry->data->right_fork.mutex, NULL) != 0)
			return (false);
		pthread_create(&entry->data->thread, NULL, philo_thread, data);
		entry = entry->next;
	}
	return (true);
}

int	main(int len, char **args)
{
	int				success;
	int				amount_philo;
	t_philo_list	**philo_top;
	pthread_mutex_t	*print;

	if (len != 5 && len != 6)
		return (msg_bool(true,
				"Invalid argument length, got %d expected 5 or 6", len));
	amount_philo = ft_atoi(args[1], &success);
	if (!success)
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	print = ft_calloc(1, sizeof(pthread_mutex_t));
	printf("res: %d\n\n", pthread_mutex_init(print, NULL));
	philo_top = load_philos(load_philo_data(len, args), amount_philo);
	if (init_mutex(*philo_top, print) == false)
		return (1);
	free_philo_list(philo_top);
	return (0);
}
