/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:40:32 by frahenin          #+#    #+#             */
/*   Updated: 2024/11/04 08:37:29 by frahenin         ###   ########.fr       */
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

# define ERROR 1

typedef pthread_mutex_t	t_mutex;
typedef struct s_data	t_data;

typedef struct s_fork
{
	int					fork_id;
	t_mutex				fork;
}						t_fork;

typedef struct s_philo
{
	int					id;
	int					eaten_count;
	pthread_t			thred_id;
	t_fork				*l_fork;
	t_fork				*r_fork;
	t_data				*data;
}						t_philo;

struct					s_data
{
	int					philo_nbr;
	time_t				time_to_die;
	time_t				time_to_eat;
	time_t				time_to_sleep;
	int					must_eat;
	t_philo				*philos;
	t_fork				*fork;
};

int						error_exit(char *str);

int						parse_input(t_data *data, char **av);
int						data_init(t_data *data);

#endif