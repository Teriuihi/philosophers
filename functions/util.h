/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 15:24:36 by sappunn       #+#    #+#                 */
/*   Updated: 2022/02/07 15:24:36 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H
# include "../headers/bool.h"

t_bool	msg_bool(t_bool t_bool, char *str, ...);
void	*msg_ptr(void *ptr, char *str, ...);
#endif
