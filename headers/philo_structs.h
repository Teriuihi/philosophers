/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   internal.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 19:19:13 by sappunn       #+#    #+#                 */
/*   Updated: 2022/01/28 19:19:13 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCTS_H
# define PHILO_STRUCTS_H
# include <time.h>

typedef struct s_philo_data
{
	time_t	ttd;
	time_t	tte;
	time_t	tts;
	int		amount_eat;
}	t_philo_data;

typedef struct s_philo_list
{
	int					id;
	struct s_philo_data	*data;
	void				*fork;
	struct s_phio		*next;
	struct s_phio		*prev;
}	t_philo_list;
#endif
