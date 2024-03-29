/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:50:44 by gfredes-          #+#    #+#             */
/*   Updated: 2024/03/29 02:25:36 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *ph)
{
	pthread_mutex_lock(ph->left_fork);
	if (ph->info->death == 0 && ph->info->finished == 0)
		printf("%lu %d has taken a fork\n", ft_get_time() - ph->info->start_time, \
			ph->id);
	pthread_mutex_lock(ph->right_fork);
	if (ph->info->death == 0 && ph->info->finished == 0)
		printf("%lu %d has taken a fork\n", ft_get_time() - ph->info->start_time, \
			ph->id);
	ph->time_of_death = ft_get_time() + ph->info->time_to_die;
	ph->meals_eaten++;
	ph->eating = 1;
	pthread_mutex_lock(&ph->mutex);
	if (ph->info->death == 0 && ph->info->finished == 0)
		printf("%lu %d is eating\n", ft_get_time() - ph->info->start_time, ph->id);
	pthread_mutex_unlock(&ph->mutex);
	usleep(ph->info->time_to_eat * 1000);
	pthread_mutex_unlock(ph->left_fork);
	pthread_mutex_unlock(ph->right_fork);
	ph->eating = 0;
}

void	ft_sleep(t_philo *ph)
{
	pthread_mutex_lock(&ph->mutex);
	if (ph->info->death == 0 && ph->info->finished == 0)
		printf("%lu %d is sleeping\n", ft_get_time() - ph->info->start_time, ph->id);
	pthread_mutex_unlock(&ph->mutex);
	usleep(ph->info->time_to_sleep * 1000);
}

void	ft_think(t_philo *ph)
{
	pthread_mutex_lock(&ph->mutex);
	if (ph->info->death == 0 && ph->info->finished == 0)
		printf("%lu %d is thinking\n", ft_get_time() - ph->info->start_time, ph->id);
	pthread_mutex_unlock(&ph->mutex);
}
