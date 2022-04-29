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

#include "../headers/philo_structs.h"
#include "../not_libft/not_libft.h"
#include "../functions/util.h"

t_philo_list	*ft_philo_new(int id, t_philo_data *data)
{
	t_philo_list	*start;

	start = ft_calloc(1, sizeof(*start));
	if (!start)
		return (NULL);
	start->id = id;
	start->data = data;
	start->next = NULL;
	start->prev = NULL;
	return (start);
}

void	add_philo(t_philo_list **top, t_philo_list *next)
{
	t_philo_list	*top_philo;

	top_philo = *top;
	if (next == NULL)
		exit(0);
	if (top_philo->next == NULL)
	{
		top_philo->next = next;
		top_philo->prev = next;
		next->next = top_philo;
		next->prev = top_philo;
		return ;
	}
	top_philo->prev->next = next;
	top_philo->prev = next;
	next->prev = top_philo->prev;
	next->next = top_philo;
}

t_philo_data	*load_philo_data(int len, char **args)
{
	int				success;
	t_philo_data	*data;

	data = ft_calloc(1, sizeof(t_philo_data));
	if (!data)
		msg_quit(1, "Error initializing philosophers data struct\n");
	data->ttd = ft_atoi(args[2], &success);
	if (!success)
		msg_quit(1, "Error initializing time to die\n");
	data->tte = ft_atoi(args[3], &success);
	if (!success)
		msg_quit(1, "Error initializing time to eat\n");
	data->tts = ft_atoi(args[4], &success);
	if (!success)
		msg_quit(1, "Error initializing time to sleep\n");
	if (len != 5)
	{
		data->amount_eat = -1;
		return (data);
	}
//	data->ttd = ft_atoi(args[5], &success);
//	if (!success)
//		msg_quit(1, "Error\n");
	return (data);
}

t_philo_list	**load_philos(t_philo_data	*data, int amount_philo)
{
	int				i;
	t_philo_list	**top;
	t_philo_data	*new_data;

	top = ft_calloc(1, sizeof(t_philo_list));
	if (!top)
		msg_quit(1, "Error\n");
	i = 1;
	while (i < amount_philo)
	{
		new_data = ft_calloc(1, sizeof(t_philo_data));
		if (!new_data)
			msg_quit(1, "Error\n");
		ft_memcpy(new_data, data, sizeof(t_philo_data));
		if (top == NULL)
			*top = ft_philo_new(i, new_data);
		else
			add_philo(top, ft_philo_new(i, new_data));
		i++;
	}
	return (top);
}
