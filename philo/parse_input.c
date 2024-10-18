/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:11:11 by frahenin          #+#    #+#             */
/*   Updated: 2024/10/18 15:13:30 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline int	is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

static inline int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static long	ft_atol(char *str)
{
	long	n;
	size_t	i;

	i = 0;
	n = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '\0')
		error_exit("no argument\n");
	if (str[i] == '+')
		i++;
	while (str[i] && is_digit(str[i]))
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i])
		error_exit("argument should be number\n");
	if (n > INT_MAX)
		error_exit("the input value is bigger than INT_MAX");
	return (n);
}

void	parse_input(t_data *data, char **av)
{
	data->philo_nbr = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]) * 1000;
	data->time_to_eat = ft_atol(av[3]) * 1000;
	data->time_to_sleep = ft_atol(av[4]) * 1000;
	if (av[5])
		data->must_eat = ft_atol(av[5]);
}
