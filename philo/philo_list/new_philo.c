/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_philo.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/29 21:36:53 by sappunn       #+#    #+#                 */
/*   Updated: 2022/04/29 21:36:53 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_list.h"
#include "../functions/util.h"

t_philo_list	*ft_philo_new(int id, t_philo *data, t_stuff *stuff)
{
	t_philo_list	*start;

	start = ft_calloc(1, sizeof(*start));
	if (!start)
		return (NULL);
	start->id = id;
	start->data = data;
	start->stuff = stuff;
	start->next = NULL;
	start->prev = NULL;
	return (start);
}
