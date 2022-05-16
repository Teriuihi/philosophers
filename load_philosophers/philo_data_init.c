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

#include "../functions/util.h"
#include "../not_libft/not_libft.h"

static t_bool	init_data(t_philo *data, int len, char **args, t_bool *rip)
{
	int	success;

	data->ttd = ft_atoi(args[2], &success);
	if (!success)
		return (msg_bool(false, "Error initializing time to die\n"));
	data->tte = ft_atoi(args[3], &success);
	if (!success)
		return (msg_bool(false, "Error initializing time to eat\n"));
	data->tts = ft_atoi(args[4], &success);
	if (!success)
		return (msg_bool(false, "Error initializing time to sleep\n"));
	if (len == 6)
		data->amount_eat = ft_atoi(args[5], &success);
	else
		data->amount_eat = -1;
	if (!success)
		return (msg_bool(false, "Error amount to eat\n"));
	data->left_fork = NULL;
	data->last_meal = get_time();
	data->right_fork.in_use = false;
	*rip = false;
	data->rip = rip;
	return (true);
}

t_philo	*load_philo_data(int len, char **args, t_bool *rip)
{
	t_philo	*data;

	data = ft_calloc(1, sizeof(t_philo));
	if (!data)
		return (msg_ptr(NULL, "Error initializing philosophers data struct\n"));
	if (init_data(data, len, args, rip) == false)
	{
		free((data));
		return (NULL);
	}
	return (data);
}
