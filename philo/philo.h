/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:55:58 by gfredes-          #+#    #+#             */
/*   Updated: 2024/03/25 13:55:58 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>


struct s_philo;

typedef struct s_info
{
	int							number_of_philosophers;
	u_int64_t				start_time;
	u_int64_t				time_to_die;
	u_int64_t 			time_to_eat;
	u_int64_t				time_to_sleep;
	int							number_of_times_each_philosopher_must_eat;
	struct s_philo	*philos;
	int							death;
	int							finished;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}					t_info;

typedef struct s_philo
{
	int							id;
	pthread_t				thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_info					*info;
	u_int64_t				last_meal;
	int							meals_eaten;
	int							status;
}					t_philo;

//check_args.c
int check_args_number(int argc);
int check_all_args_are_numbers(char **argv);
int check_number_of_philosophers(char *argv);
int check_args(int argc, char **argv);
// int	check_max_int(char **argv);

//utils.c
int ft_atoi(const char *str);

#endif