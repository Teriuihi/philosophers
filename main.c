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

t_bool	init_mutex(t_philo_list *entry)
{
	while (entry)
	{
		if (pthread_mutex_init(&entry->data->right_fork.mutex, NULL) != 0)
			return (false);
		entry = entry->next;
	}
	return (true);
}

int	main(int len, char **args)
{
	int				success;
	int				amount_philo;
	t_philo_list	**philo_top;

	if (len != 5 && len != 6)
		return (msg_bool(true,
				"Invalid argument length, got %d expected 5 or 6", len));
	amount_philo = ft_atoi(args[1], &success);
	if (!success)
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	philo_top = load_philos(load_philo_data(len, args), amount_philo);
	if (init_mutex(*philo_top) == false)
		return (1);
	return (0);
}
//
//void	philo_run(void *arg)
//{
//
//}