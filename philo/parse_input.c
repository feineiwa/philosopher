/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:11:11 by frahenin          #+#    #+#             */
/*   Updated: 2024/11/01 10:40:18 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

static int	is_digit(char c)
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
		return (error_exit("no argument\n"), 0);
	if (str[i] == '-')
		return (error_exit("the argument should be a positive number\n"), 0);
	else if (str[i] == '+')
		i++;
	while (str[i] && is_digit(str[i]))
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i])
		return (error_exit("argument should be number\n"), 0);
	if (n > INT_MAX)
		return (error_exit("the input value is bigger than INT_MAX"), 0);
	return (n);
}

int	parse_input(t_data *data, char **av)
{
	data->philo_nbr = (int)ft_atol(av[1]);
	data->time_to_die = (int)ft_atol(av[2]) * 1000;
	data->time_to_eat = (int)ft_atol(av[3]) * 1000;
	data->time_to_sleep = (int)ft_atol(av[4]) * 1000;
	if (av[5])
		data->must_eat = ft_atol(av[5]);
	else
		data->must_eat = -1;
	if (!data->philo_nbr || !data->time_to_die || !data->time_to_eat
		|| !data->time_to_sleep || !data->must_eat || data->philo_nbr >= 200)
		return (error_exit("Error arguments"));
	return (0);
}
