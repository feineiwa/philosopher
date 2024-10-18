/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:53:44 by frahenin          #+#    #+#             */
/*   Updated: 2024/10/18 15:17:39 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data)
{
	data->must_eat = -1;
	data->time_to_die = 0;
	data->philo_nbr = 0;
	data->time_to_sleep = 0;
	data->time_to_eat = 0;
}

int	main(int ac, char **av)
{
	t_data data;

	if (ac != 5 && ac != 6)
		error_exit("Error Argument\n");
	init_data(&data);
	parse_input(&data, av);
	data_init(&data);
	// dinner_start(&table);
	// clean(&table);
	(void)av;
	return (0);
}