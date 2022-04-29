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

typedef struct s_philo
{
	time_t	ttd;
	time_t	tte;
	time_t	tts;
	time_t	last_meal;
	void	*right_fork;
	void	*left_fork;
	int		amount_eat;
}	t_philo;

typedef struct s_philo_list
{
	int					id;
	t_philo				*data;
	struct s_philo_list	*next;
	struct s_philo_list	*prev;
}	t_philo_list;

#endif
