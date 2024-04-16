/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:14:37 by gfredes-          #+#    #+#             */
/*   Updated: 2024/04/16 20:22:48 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	init_forks(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nbr_of_philos)
	{
		if (pthread_mutex_init(&info->forks[i], NULL))
		{
			printf("Error: mutex init failed\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_get_info(t_info *info, char **argv)
{
	info->nbr_of_philos = ft_atoi(argv[1]);
	info->time_to_die = (time_t) ft_atoi(argv[2]);
	info->time_to_eat = (time_t) ft_atoi(argv[3]);
	info->time_to_sleep = (time_t) ft_atoi(argv[4]);
	if (argv[5])
		info->nbr_of_times_each_philo_must_eat = ft_atoi(argv[5]);
	else
		info->nbr_of_times_each_philo_must_eat = -1;
	ft_check_info(info);
	info->death = 0;
	info->finished = 0;
	/*info->end = (int *)malloc(sizeof(int));
	if (!info->end)
	{
		printf("Error: malloc failed\n");
		return (1);
	}*/
	info->end = 0;
	info->start_time = ft_get_time();
	pthread_mutex_init(&info->print, NULL);
	pthread_mutex_init(&info->mutex, NULL);
	pthread_mutex_init(&info->end_mutex, NULL);
	pthread_mutex_init(&info->death_mutex, NULL);
	pthread_mutex_init(&info->meal_mutex, NULL);
	pthread_mutex_init(&info->init_mutex, NULL);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->nbr_of_philos);
	info->threads_id = malloc(sizeof(pthread_t) * info->nbr_of_philos);
	if (!info->forks || !info->threads_id)
	{
		printf("Error: malloc failed\n");
		return (1);
	}
	if (init_forks(info))
		return (1);
	return (0);
}

void	ft_set_forks(t_info *info)
{
	int	i;

	i = 1;
	info->philos[0].left_fork = &info->forks[0];
	info->philos[0].right_fork = &info->forks[info->nbr_of_philos - 1];
	while (i < info->nbr_of_philos)
	{
		info->philos[i].left_fork = &info->forks[i];
		info->philos[i].right_fork = &info->forks[i - 1];
		i++;
	}
	return ;
}

void	ft_init_philos(t_info *info)
{
	int	i;

	i = 0;
	info->philos = malloc(sizeof(t_philo) * info->nbr_of_philos);
	if (!info->philos)
	{
		printf("Error: malloc failed\n");
		return ;
	}
	while (i < info->nbr_of_philos)
	{
		info->philos[i].id = i + 1;
		info->philos[i].time_of_death = info->start_time + info->time_to_die;
		info->philos[i].meals_eaten = 0;
		info->philos[i].status = 0;
		info->philos[i].info = info;
		pthread_mutex_init(&info->philos[i].mutex, NULL);
		ft_set_forks(info);
		i++;
	}
}
