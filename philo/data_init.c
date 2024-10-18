/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:17:02 by frahenin          #+#    #+#             */
/*   Updated: 2024/10/18 16:58:04 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
		error_exit("Error with malloc\n");
	return (ret);
}

void	data_init(t_data *data)
{
	data->philos = ft_malloc(sizeof(t_philo) * (data->philo_nbr));
	data->fork = ft_malloc(sizeof(t_fork) * (data)->philo_nbr);
}