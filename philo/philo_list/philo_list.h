/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_list.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/29 21:32:16 by sappunn       #+#    #+#                 */
/*   Updated: 2022/04/29 21:32:16 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_LIST_H
# define PHILO_LIST_H
# include "../headers/philo_structs.h"
# include "../headers/bool.h"

typedef struct s_stuff
{
	t_bool			rip;
	pthread_mutex_t	print;
	long			start;
	pthread_t		monitor;
}	t_stuff;

typedef struct s_philo_list
{
	int					id;
	t_philo				*data;
	struct s_philo_list	*next;
	struct s_philo_list	*prev;
	t_stuff				*stuff;
}	t_philo_list;

t_philo_list	*last_philo(t_philo_list **top);
void			add_philo(t_philo_list **top, t_philo_list *entry);
t_philo_list	*ft_philo_new(int id, t_philo *data, t_stuff *stuff);

#endif
