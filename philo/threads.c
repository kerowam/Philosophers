/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:28:36 by gfredes-          #+#    #+#             */
/*   Updated: 2024/03/29 03:04:13 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_death_checker(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	while (ph->info->death == 0)
	{
		pthread_mutex_lock(&ph->mutex);
		if (ft_get_time() >= ph->time_of_death && ph->eating == 0)
		{
			pthread_mutex_lock(&ph->info->mutex);
			printf("%lu %d died\n", ft_get_time() - ph->info->start_time, ph->id);
			ph->info->death = 1;
			pthread_mutex_unlock(&ph->info->mutex);
		}
		pthread_mutex_unlock(&ph->mutex);
	}
	return ((void *)0);
}

void	*one_philo_routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	printf("%lu %d has taken a fork\n", ft_get_time() - ph->info->start_time, \
		ph->id);
	while (ft_get_time() < ph->time_of_death)
		usleep(0);
	printf("%lu %d died\n", ft_get_time() - ph->info->start_time, ph->id);
	return ((void *)0);
}

void	*routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	if (pthread_create(&ph->thread, NULL, &ft_death_checker, (void *)ph))
		return ((void *)1);
	while (ph->info->death == 0 && ph->info->finished == 0)
	{
		if (ph->info->death == 0 && ph->info->finished == 0)
			ft_think(ph);
		if (ph->info->death == 0 && ph->info->finished == 0)
			ft_eat(ph);
		if (ph->info->death == 0 && ph->info->finished == 0)
			ft_sleep(ph);
	}
	if (pthread_join(ph->thread, NULL))
		return ((void *)1);
	return ((void *)0);
}

void	*ft_end_checker(void *info)
{
	t_info	*inf;
	int		i;
	int		meal_count;

	inf = (t_info *)info;
	i = 0;
	meal_count = 0;
	while (1)
	{
		while (i < inf->nbr_of_philos)
		{
			if (inf->philos[i].meals_eaten >= inf->nbr_of_times_each_philo_must_eat)
				meal_count++;
			i++;
		}
		if (i == inf->nbr_of_philos && meal_count < inf->nbr_of_philos)
		{
			i = 0;
			meal_count = 0;
		}
		else if (meal_count == inf->nbr_of_philos)
			break ;
	}
	if (meal_count == inf->nbr_of_philos)
	{
		pthread_mutex_lock(&inf->mutex);
		inf->finished = 1;
		pthread_mutex_unlock(&inf->mutex);
	}
	return ((void *)0);
}

int	ft_threads(t_info *info)
{
	int			i;
	pthread_t	checker_thread;

	i = 0;
	info->start_time = ft_get_time();
	if (info->nbr_of_times_each_philo_must_eat > 0)
	{
		if (pthread_create(&checker_thread, NULL, &ft_end_checker, info))
		{
			printf("Error: thread creation failed\n");
			return (1);
		}
	}
	while (i < info->nbr_of_philos)
	{
		if (pthread_create(&info->threads_id[i], NULL, &routine, &info->philos[i]))
		{
			printf("Error: thread creation failed\n");
			return (1);
		}
		usleep(1);
		i++;
	}
	i = 0;
	while (i < info->nbr_of_philos)
	{
		if (pthread_join(info->threads_id[i], NULL))
		{
			printf("Error: thread join failed\n");
			return (1);
		}
		i++;
	}
	return (0);
}
