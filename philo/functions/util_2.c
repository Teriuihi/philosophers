/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util_2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 15:23:18 by sappunn       #+#    #+#                 */
/*   Updated: 2022/02/07 15:23:18 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/bool.h"
#include "../philo_list/philo_list.h"

long	get_last_meal(t_philo_list *entry)
{
	long	result;

	pthread_mutex_lock(&(entry->stuff->print));
	result = entry->data->last_meal;
	pthread_mutex_unlock(&(entry->stuff->print));
	return (result);
}

void	set_last_meal(t_philo_list *entry, long time)
{
	pthread_mutex_lock(&(entry->stuff->print));
	entry->data->last_meal = time;
	pthread_mutex_unlock(&(entry->stuff->print));
}

int	get_meals_left(t_philo_list *entry)
{
	int	result;

	pthread_mutex_lock(&(entry->stuff->print));
	result = entry->data->amount_eat;
	pthread_mutex_unlock(&(entry->stuff->print));
	return (result);
}

void	reduce_meals_left(t_philo_list *entry)
{
	pthread_mutex_lock(&(entry->stuff->print));
	if (entry->data->amount_eat > 0)
		entry->data->amount_eat--;
	pthread_mutex_unlock(&(entry->stuff->print));
}
