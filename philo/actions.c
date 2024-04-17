/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:50:44 by gfredes-          #+#    #+#             */
/*   Updated: 2024/04/17 16:57:33 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *ph)
{
	time_t	time;

	pthread_mutex_lock(ph->left_fork);
	pthread_mutex_lock(&ph->info->end_mutex);
	if (ph->info->end == 0)
	{
		pthread_mutex_unlock(&ph->info->end_mutex);
		pthread_mutex_lock(&ph->info->print);
		time = ft_get_time() - ph->info->start_time;
		printf("%lu %d has taken a fork\n", time, ph->id);
		pthread_mutex_unlock(&ph->info->print);
	}
	else
		pthread_mutex_unlock(&ph->info->end_mutex);
	pthread_mutex_lock(ph->right_fork);
	pthread_mutex_lock(&ph->info->end_mutex);
	if (ph->info->end == 0)
	{
		pthread_mutex_unlock(&ph->info->end_mutex);
		pthread_mutex_lock(&ph->info->print);
		time = ft_get_time() - ph->info->start_time;
		printf("%lu %d has taken a fork\n", time, ph->id);
		pthread_mutex_unlock(&ph->info->print);
	}
	else
		pthread_mutex_unlock(&ph->info->end_mutex);
	ph->eating = 1;
	pthread_mutex_lock(&ph->info->end_mutex);
	if (ph->info->end == 0)
	{
		pthread_mutex_unlock(&ph->info->end_mutex);
		pthread_mutex_lock(&ph->info->print);
		time = ft_get_time() - ph->info->start_time;
		printf("%lu %d is eating\n", time, ph->id);
		pthread_mutex_unlock(&ph->info->print);
	}
	else
		pthread_mutex_unlock(&ph->info->end_mutex);
	pthread_mutex_lock(&ph->mutex);
	ph->time_of_death = ft_get_time() + ph->info->time_to_die;
	pthread_mutex_unlock(&ph->mutex);
	pthread_mutex_lock(&ph->info->meal_mutex);
	ph->meals_eaten++;
	pthread_mutex_unlock(&ph->info->meal_mutex);
	if (ph->info->time_to_eat > 0)
		ft_usleep(ph, ph->info->time_to_eat);
	pthread_mutex_unlock(ph->left_fork);
	pthread_mutex_unlock(ph->right_fork);
	ph->eating = 0;
}

void	ft_sleep(t_philo *ph)
{
	time_t	time;

	pthread_mutex_lock(&ph->info->print);
	time = ft_get_time() - ph->info->start_time;
	pthread_mutex_lock(&ph->info->end_mutex);
	if (ph->info->end == 0)
		printf("%lu %d is sleeping\n", time, ph->id);
	pthread_mutex_unlock(&ph->info->print);
	pthread_mutex_unlock(&ph->info->end_mutex);
	if (ph->info->time_to_sleep > 0)
		ft_usleep(ph, ph->info->time_to_sleep);
}

void	ft_think(t_philo *ph)
{
	time_t	time;

	pthread_mutex_lock(&ph->info->print);
	time = ft_get_time() - ph->info->start_time;
	//pthread_mutex_lock(&ph->info->end_mutex);
	if (ft_read_value(&ph->info->end, &ph->info->end_mutex) == 0)
	{
		printf("%lu %d is thinking\n", time, ph->id);
	}
	//pthread_mutex_unlock(&ph->info->end_mutex);
	pthread_mutex_unlock(&ph->info->print);
}
