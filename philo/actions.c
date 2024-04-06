/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:50:44 by gfredes-          #+#    #+#             */
/*   Updated: 2024/04/04 17:48:19 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *ph)
{
	pthread_mutex_lock(ph->left_fork);
	if (ph->info->death == 0 && ph->info->finished == 0)
		printf("%lu %d has taken a fork\n",
			ft_get_time() - ph->info->start_time, ph->id);
	pthread_mutex_lock(ph->right_fork);
	if (ph->info->death == 0 && ph->info->finished == 0)
		printf("%lu %d has taken a fork\n",
			ft_get_time() - ph->info->start_time, ph->id);
	pthread_mutex_lock(&ph->info->print);
	ph->eating = 1;
	if (ph->info->death == 0 && ph->info->finished == 0)
		printf("%lu %d is eating\n", ft_get_time() - ph->info->start_time,
			ph->id);
	pthread_mutex_unlock(&ph->info->print);
	ph->time_of_death = ft_get_time() + ph->info->time_to_die;
	ph->meals_eaten++;
	if (ph->info->time_to_eat > 0)
		ft_usleep(ph, ph->info->time_to_eat * 1000);
	pthread_mutex_unlock(ph->left_fork);
	pthread_mutex_unlock(ph->right_fork);
	ph->eating = 0;
}

void	ft_sleep(t_philo *ph)
{
	pthread_mutex_lock(&ph->info->print);
	if (ph->info->death == 0 && ph->info->finished == 0)
		printf("%lu %d is sleeping\n", ft_get_time() - ph->info->start_time,
			ph->id);
	pthread_mutex_unlock(&ph->info->print);
	if (ph->info->time_to_sleep > 0)
		ft_usleep(ph, ph->info->time_to_sleep * 1000);
}

void	ft_think(t_philo *ph)
{
	pthread_mutex_lock(&ph->info->print);
	if (ph->info->death == 0 && ph->info->finished == 0)
	{
		printf("%lu %d is thinking\n", ft_get_time() - ph->info->start_time,
			ph->id);
	}
	pthread_mutex_unlock(&ph->info->print);
}
