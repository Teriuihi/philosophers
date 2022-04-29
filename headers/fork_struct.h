/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork_struct.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/29 20:51:11 by sappunn       #+#    #+#                 */
/*   Updated: 2022/04/29 20:51:11 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_STRUCT_H
# define FORK_STRUCT_H
# include <pthread.h>
# include "bool.h"

typedef struct s_fork
{
	pthread_mutex_t	*mutex;
	t_bool			in_use;
}	t_fork;
#endif
