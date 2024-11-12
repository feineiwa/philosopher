/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:53:44 by frahenin          #+#    #+#             */
/*   Updated: 2024/11/12 16:54:17 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_long(t_mutex *mutex, long *dest, long value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

long	get_long(t_mutex *mutex, long *value)
{
	long	ret;

	pthread_mutex_lock(mutex);
	ret = *value;
	pthread_mutex_unlock(mutex);
	return (ret);
}

void	set_bool(t_mutex *mutex, int *dest, int value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}
int	get_bool(t_mutex *mutex, int *value)
{
	int	ret;

	pthread_mutex_lock(mutex);
	ret = *value;
	pthread_mutex_unlock(mutex);
	return (ret);
}

int	simulation_finished(t_data *data)
{
	return (get_bool(&data->data_mutex, &data->end_simulation));
}

void	wait_all_threads(t_data *data)
{
	while (get_bool(&data->data_mutex, &data->all_threads_ready))
		;
}

time_t	gettime(t_time_code time_code)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		exit(1);
	if (SECOND == time_code)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (MILLISECONDS == time_code)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (MICROSECONDS == time_code)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		exit(1);
	return (1337);
}

void	*dinner_simulation(void *ap)
{
	t_philo	*philo;

	philo = (t_philo *)ap;
	wait_all_threads(philo->data);
	while (!simulation_finished())
		return (NULL);
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
				return (ERROR_FAILURE);
			i++;
		}
	}
	data->start_simulation = gettime(MILLISECONDS);
	set_bool(&data->data_mutex, &data->all_threads_ready, TRUE);
	return (0);
}

int	main(int ac, char **av)
{
	t_data data;

	if (ac != 5 && ac != 6)
		return (error_exit("Error imput arguments\nError Arguments"));
	if (parse_input(&data, av) == ERROR_FAILURE)
		return (ERROR_FAILURE);
	if (data_init(&data) == ERROR_FAILURE)
		return (ERROR_FAILURE);
	if (dinner_start(&data))
		return (ERROR_FAILURE);
	// clean(&table);
	return (0);
}