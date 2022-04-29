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

#include "../not_libft/not_libft.h"
#include "../headers/bool.h"
#include "../philo_list/philo_list.h"

t_bool	msg_bool(t_bool t_bool, char *str, ...)
{
	va_list	ap;

	if (str != NULL)
	{
		va_start(ap, str);
		if (t_bool == true)
			ft_printf_va(1, str, ap);
		else
			ft_printf_va(2, str, ap);
	}
	return (t_bool);
}

void	*msg_ptr(void *ptr, char *str, ...)
{
	va_list	ap;

	if (str != NULL)
	{
		va_start(ap, str);
		if (ptr != NULL)
			ft_printf_va(1, str, ap);
		else
			ft_printf_va(2, str, ap);
	}
	return (ptr);
}

void	free_philo_list(t_philo_list **top)
{
	t_philo_list	*entry;
	t_philo_list	*tmp;

	entry = *top;
	while (entry)
	{
		free(entry->data);
		tmp = entry;
		entry = entry->next;
		free(tmp);
	}
	free(top);
}
