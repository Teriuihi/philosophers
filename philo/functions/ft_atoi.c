/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 21:30:48 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 21:30:48 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

/**
 * Checks if a character is a whitespace
 *
 * @param	c	Character to check
 *
 * @return	1 if the character is whitespace, 0 if it's not
 */
static int	ft_isspace(char c)
{
	return (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' ');
}

/**
 * Converts a string that starts with a digit to an int
 *
 * @param 	str	Char array to convert
 *
 * @return 		Converted integer
 */
static int	convert(const char *str, int *success)
{
	int	res;
	int	tmp;

	if (!ft_isdigit(*str))
		return (0);
	while (*str == '0' && *(str + 1) != 0)
		str++;
	res = (*str - '0') * -1;
	str++;
	while (ft_isdigit(*str))
	{
		tmp = res;
		res *= 10;
		res -= (*str - '0');
		if ((res / 10) != tmp)
			return (0);
		str++;
	}
	if (*str == 0)
		*success = 1;
	return (res);
}

/**
 * Converts a string to an int
 *
 * @param	str	String to convert
 *
 * @return	The converted integer or 0 on failure
 * 	(keep in mind 0 could be the converted integer)
 */
int	ft_atoi(const char *str, int *success)
{
	int	negative;
	int	res;

	*success = 0;
	negative = -1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = 1;
		str++;
	}
	res = convert(str, success);
	if (res == -2147483648 && negative == -1)
		*success = 0;
	return (res * negative);
}
