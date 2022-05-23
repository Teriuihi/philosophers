/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_philos.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 15:10:08 by sappunn       #+#    #+#                 */
/*   Updated: 2022/02/07 15:10:08 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "../philo_list/philo_list.h"
#include "../functions/util.h"

static void	add_new_philo_update_fork(t_philo_list **top,
				t_philo_list *new_philo)
{
	if (*top == NULL)
		*top = new_philo;
	else
	{
		add_philo(top, new_philo);
		new_philo->prev->data->left_fork = &new_philo->data->right_fork;
	}
}

static t_bool	init(t_philo *data, t_philo_list ***top)
{
	if (data == NULL)
	{
		return (FALSE);
	}
	*top = ft_calloc(1, sizeof(t_philo_list));
	if (*top == NULL)
	{
		printf("Error\n");
		return (FALSE);
	}
	return (TRUE);
}

t_philo_list	**load_philos(t_philo *data, int amount_philo, t_stuff *stuff)
{
	int				i;
	t_philo_list	**top;
	t_philo			*new_data;

	if (init(data, &top) == FALSE)
		return (NULL);
	i = 1;
	while (i <= amount_philo)
	{
		new_data = ft_calloc(1, sizeof(t_philo));
		if (!new_data)
		{
			free_philo_list(top, FALSE);
			printf("Error\n");
			return (NULL);
		}
		ft_memcpy(new_data, data, sizeof(t_philo));
		add_new_philo_update_fork(top, ft_philo_new(i, new_data, stuff));
		i++;
	}
	free(data);
	last_philo(top)->data->left_fork = &(*top)->data->right_fork;
	return (top);
}
