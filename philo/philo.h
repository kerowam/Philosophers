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
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>


struct	s_philo;

typedef struct s_info
{
	int				nbr_of_philos;
	time_t			start_time;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				nbr_of_times_each_philo_must_eat;
	struct s_philo	*philos;
	int				death;
	int				finished;
	int				end;
	int				inited;
	pthread_t		*threads_id;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	mutex;
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	death_mutex;
	//pthread_mutex_t	finish_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	init_mutex;
}					t_info;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	mutex;
	t_info			*info;
	time_t			time_of_death;
	int				meals_eaten;
	int				status;
	int				eating;
}					t_philo;

//check_args.c
int		check_all_args_are_numbers(char **argv);
int		check_number_of_philosophers(char *argv);
int		check_args(int argc, char **argv);
int		check_max_int(char **argv);

//utils.c
int		ft_atoi(const char *str);
void	ft_usleep(t_philo *ph, useconds_t time);
void	ft_check_info(t_info *info);
void	ft_add_delay(t_philo *ph);
int		ft_read_value(int *value, pthread_mutex_t *mutex);

//init.c
time_t	ft_get_time(void);	
int		ft_get_info(t_info *info, char **argv);
void	print_info(t_info *info);
void	ft_init_philos(t_info *info);

//threads.c
void	*routine(void *philo);
int		ft_threads(t_info *info);
void	*one_philo_routine(void *philo);
int		ft_check_finished(t_info *info);

//actions.c
void	ft_eat(t_philo *ph);
void	ft_sleep(t_philo *ph);
void	ft_think(t_philo *ph);
void	ft_print(t_philo *ph, char *str);

//threads_utils.c
void	*ft_end_checker(void *info);
int		ft_init_thread(pthread_t *thread, void *(*routine)(void *), void *arg);
int		ft_join_thread(pthread_t thread);
int		ft_join_threads(t_info *info);
#endif