/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:28:36 by gfredes-          #+#    #+#             */
/*   Updated: 2024/03/29 14:03:14 by gfredes-         ###   ########.fr       */
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
			ph->info->death = 1;
			pthread_mutex_unlock(&ph->info->mutex);
			printf("%lu %d died\n", ft_get_time() - ph->info->start_time,
				ph->id);
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
	ph->time_of_death = ph->info->start_time + ph->info->time_to_die;
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

int	ft_check_finished(t_info *info)
{
	int	i;
	int	meal_count;

	i = 0;
	meal_count = 0;
	while (i < info->nbr_of_philos)
	{
		if (info->philos[i].meals_eaten
			>= info->nbr_of_times_each_philo_must_eat)
			meal_count++;
		i++;
	}
	if (meal_count == info->nbr_of_philos)
	{
		pthread_mutex_lock(&info->mutex);
		info->finished = 1;
		pthread_mutex_unlock(&info->mutex);
	}
	if (info->finished == 1)
		return (1);
	return (0);
}

int	ft_threads(t_info *info)
{
	int			i;
	pthread_t	checker_thread;

	i = 0;
	info->start_time = ft_get_time();
	if (info->nbr_of_times_each_philo_must_eat > 0)
	{
		if (ft_init_thread(&checker_thread, &ft_end_checker, info) == 1)
			return (1);
	}
	while (i < info->nbr_of_philos)
	{
		if (ft_init_thread(&info->threads_id[i], &routine, &info->philos[i]))
			return (1);
		usleep(1);
		i++;
	}
	if (ft_join_threads(info) == 1)
		return (1);
	if (info->nbr_of_times_each_philo_must_eat > 0)
	{
		if (ft_join_thread(checker_thread) == 1)
			return (1);
	}
	return (0);
}
