/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 21:30:54 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 21:30:54 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../headers/libft.h"

/**
 * Writes a string to the specified file descriptor
 *
 * @param	s	String to write
 * @param	fd	File descriptor to write to
 */
int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = ft_strlen(s);
	write(fd, s, len);
	return (len);
}
