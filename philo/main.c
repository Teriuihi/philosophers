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

static void	start_philo(int len, char **args, int amount_philo)
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
