/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_philo.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/29 21:29:06 by sappunn       #+#    #+#                 */
/*   Updated: 2022/04/29 21:29:06 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_list.h"

void	add_philo(t_philo_list **top, t_philo_list *entry)
{
	t_philo_list	*start;
	t_philo_list	*end;

	start = *top;
	if (entry == NULL)
		return ;
	if (start == NULL)
	{
		*top = entry;
		entry->next = NULL;
		entry->prev = NULL;
		return ;
	}
	end = last_philo(top);
	end->next = entry;
	entry->prev = end;
	entry->next = NULL;
}
