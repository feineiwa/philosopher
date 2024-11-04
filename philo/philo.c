/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:53:44 by frahenin          #+#    #+#             */
/*   Updated: 2024/11/04 14:11:01 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner_simulation(void	*ap)
{
	t_philo	*philo;

	philo = (t_philo *)ap;
	ft_usleep(50);
	printf("Philosopher %d is thinking", philo->id);
}

static int	dinner_start(t_data *data)
{
	int	i;

	i = 0;
	if (data->philo_nbr == 1)
	{
		; // a faire
	}
	else
	{
		while (i < data->philo_nbr)
		{
			if (pthread_create(&data->philos[i].thred_id, NULL,
					dinner_simulation, &data->philos[i]))
				return (ERROR);
			i++;
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data data;

	if (ac != 5 && ac != 6)
		return (error_exit("Error imput arguments\nError Arguments\n"));
	if (parse_input(&data, av) == ERROR)
		return (ERROR);
	if (data_init(&data) == ERROR)
		return (ERROR);
	int i = 0;
	while (i < data.philo_nbr)
	{
		printf("philo id %d and fork left id %d and fork right id %d\n",
			data.philos[i].id, data.philos[i].l_fork->fork_id,
			data.philos[i].r_fork->fork_id);
		i++;
	}
	if (dinner_start(&data))
		return (ERROR);
	// clean(&table);
	return (0);
}