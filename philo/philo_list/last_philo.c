/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   last_philo.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/29 21:31:13 by sappunn       #+#    #+#                 */
/*   Updated: 2022/04/29 21:31:13 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_list.h"

t_philo_list	*last_philo(t_philo_list **top)
{
	t_philo_list	*entry;

	if (top == NULL)
		return (NULL);
	entry = *top;
	if (entry == NULL)
		return (entry);
	while (entry->next != NULL)
		entry = entry->next;
	return (entry);
}
