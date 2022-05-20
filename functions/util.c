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
#include <sys/time.h>
#include <stdio.h>

long	get_time(void)
{
	struct timeval	ct;

	if (gettimeofday(&ct, NULL) != 0)
		return (0);
	return (ct.tv_sec * 1000 + ct.tv_usec / 1000);
}

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

long	my_print(char *str, int id, t_philo_list *entry, t_bool print)
{
	long	time;

	if (pthread_mutex_lock(entry->print))
	{
		*entry->rip = true;
		printf("Error, unable to lock print mutex\n");
		return (-1);
	}
	if (*entry->rip == true && print == false)
	{
		pthread_mutex_unlock(entry->print);
		return (-1);
	}
	time = get_time();
	printf(str, time - *entry->start, id);
	if (pthread_mutex_unlock(entry->print))
	{
		*entry->rip = true;
		printf("Error, unable to unlock print mutex\n");
		return (-1);
	}
	return (time);
}

void	mili_sleep(long sleep)
{
	long	time;

	time = get_time() + sleep;
	while (time >= get_time())
		usleep(100);
}
