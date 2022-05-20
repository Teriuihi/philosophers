/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_util.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/20 21:39:27 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/20 21:39:27 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/bool.h"
#include "../philo_list/philo_list.h"
#include <stdlib.h>

void	free_philo_list(t_philo_list **top, t_bool destroy_mutex)
{
	t_philo_list	*entry;
	t_philo_list	*tmp;

	entry = *top;
	pthread_mutex_destroy(&entry->stuff->print);
	while (entry)
	{
		if (destroy_mutex == TRUE)
			pthread_mutex_destroy(&entry->data->right_fork);
		free(entry->data);
		tmp = entry;
		entry = entry->next;
		free(tmp);
	}
	free(top);
}
