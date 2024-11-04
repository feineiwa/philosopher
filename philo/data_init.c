/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:17:02 by frahenin          #+#    #+#             */
/*   Updated: 2024/11/04 07:42:24 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_forks(t_philo *philo, t_fork *fork, int i)
{
	int	philo_nbr;

	philo_nbr = philo->data->philo_nbr;
	philo->l_fork = &fork[i];
	philo->r_fork = &fork[(i + 1) % philo_nbr];
	if (philo->id % 2)
	{
		philo->r_fork = &fork[i];
		philo->l_fork = &fork[(i + 1) % philo_nbr];
	}
	// printf("philo number is %d with position %i\n", philo_nbr, i);
}

static int	init_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		if (pthread_mutex_init(&data->fork[i].fork, NULL))
			return (ERROR);
		data->fork[i].fork_id = i;
		i++;
	}
	return (0);
}

static int	init_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < data->philo_nbr)
	{
		philo = data->philos + i;
		philo->id = i + 1;
		philo->data = data;
		philo->eaten_count = 0;
		assign_forks(philo, data->fork, i);
		i++;
	}
	return (0);
}

int	data_init(t_data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(sizeof(t_fork) * data->philo_nbr);
	if (!data->fork)
		return (ERROR);
	data->philos = malloc(sizeof(t_philo) * data->philo_nbr);
	if (!data->philos)
		return (ERROR);
	if (init_fork(data))
		return (ERROR);
	if (init_philo(data))
		return (ERROR);
	return (0);
}
