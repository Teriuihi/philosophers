/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 15:23:18 by sappunn       #+#    #+#                 */
/*   Updated: 2022/02/07 15:23:18 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	err_quit(char *errmsg, int fd)
{
	ft_putstr_fd(errmsg, fd);
	exit(0);
}
