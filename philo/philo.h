/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:40:32 by frahenin          #+#    #+#             */
/*   Updated: 2024/10/18 16:20:19 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef pthread_mutex_t	t_mutex;
typedef struct s_data	t_data;

typedef struct s_fork
{
	long				fork_id;
	t_mutex				fork;
}						t_fork;

typedef struct s_philo
{
	long				id;
	long				eaten_count;
	pthread_t			thred_id;
	t_fork				*l_fork;
	t_fork				*s_fork;
	t_data				*data;
}						t_philo;

struct					s_data
{
	long				philo_nbr;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				must_eat;
	t_philo				*philos;
	t_fork				*fork;
};

void					error_exit(char *str);

void					parse_input(t_data *data, char **av);
void					data_init(t_data *data);

#endif