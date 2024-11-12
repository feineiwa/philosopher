/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:40:32 by frahenin          #+#    #+#             */
/*   Updated: 2024/11/12 16:50:34 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define ERROR_FAILURE 1

typedef pthread_mutex_t	t_mutex;
typedef struct s_data	t_data;

# define PHILO_MAX 200

typedef enum e_bool
{
	FALSE,
	TRUE,
}						t_bool;

typedef struct s_fork
{
	int					fork_id;
	t_mutex				fork_mutex;
}						t_fork;

typedef struct s_philo
{
	int					id;
	int					eaten_count;
	int					max_meals;
	long				meal_time;
	pthread_t			thred_id;
	t_fork				*l_fork;
	t_fork				*r_fork;
	t_mutex				*ph_mutex;
	t_data				*data;
}						t_philo;

struct					s_data
{
	long				philo_nbr;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				total_meals;
	long				start_simulation;
	t_bool				all_threads_ready;
	t_bool				end_simulation;
	t_mutex				data_mutex;
	t_mutex				write_mutex;
	t_philo				*philos;
	t_fork				*fork;
};

typedef enum e_satus
{
	THINKING,
	TAKE_LEFT_FORK,
	TAKE_RIGHT_FORK,
	EATING,
	SLEEPING,
	DIED,
}						t_ph_status;

typedef enum e_time_code
{
	SECOND,
	MILLISECONDS,
	MICROSECONDS,
}						t_time_code;

int						error_exit(char *str);

int						parse_input(t_data *data, char **av);
int						data_init(t_data *data);

#endif