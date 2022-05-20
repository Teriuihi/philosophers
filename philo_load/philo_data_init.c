/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_data_init.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/29 20:35:20 by sappunn       #+#    #+#                 */
/*   Updated: 2022/04/29 20:35:20 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "../functions/util.h"

static t_bool	msg_bool(char *str)
{
	printf("%s", str);
	return (FALSE);
}

static t_bool	init_data(t_philo *data, int len, char **args)
{
	int	success;

	data->ttd = ft_atoi(args[2], &success);
	if (!success)
		return (msg_bool("Error initializing time to die\n"));
	data->tte = ft_atoi(args[3], &success);
	if (!success)
		return (msg_bool("Error initializing time to eat\n"));
	data->tts = ft_atoi(args[4], &success);
	if (!success)
		return (msg_bool("Error initializing time to sleep\n"));
	if (len == 6)
		data->amount_eat = ft_atoi(args[5], &success);
	else
		data->amount_eat = -1;
	if (!success)
		return (msg_bool("Error amount to eat\n"));
	data->left_fork = NULL;
	data->last_meal = get_time();
	return (TRUE);
}

t_philo	*load_philo_data(int len, char **args)
{
	t_philo	*data;

	data = ft_calloc(1, sizeof(t_philo));
	if (!data)
	{
		printf("Error initializing philosophers data struct\n");
		return (NULL);
	}
	if (init_data(data, len, args) == FALSE)
	{
		free((data));
		return (NULL);
	}
	return (data);
}
