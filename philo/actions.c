/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:50:44 by gfredes-          #+#    #+#             */
/*   Updated: 2024/04/17 18:20:31 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_philo *ph, char *str)
{
	time_t	time;

	pthread_mutex_lock(&ph->info->print);
	time = ft_get_time() - ph->info->start_time;
	printf("%lu %d %s\n", time, ph->id, str);
	pthread_mutex_unlock(&ph->info->print);
}

void	ft_eat(t_philo *ph)
{
	pthread_mutex_lock(ph->left_fork);
	if (ft_read_value(&ph->info->end, &ph->info->end_mutex) == 0)
		ft_print(ph, "has taken a fork");
	pthread_mutex_lock(ph->right_fork);
	if (ft_read_value(&ph->info->end, &ph->info->end_mutex) == 0)
		ft_print(ph, "has taken a fork");
	pthread_mutex_lock(&ph->mutex);
	ph->eating = 1;
	pthread_mutex_unlock(&ph->mutex);
	if (ft_read_value(&ph->info->end, &ph->info->end_mutex) == 0)
		ft_print(ph, "is eating");
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
	pthread_mutex_lock(&ph->mutex);
	ph->eating = 0;
	pthread_mutex_unlock(&ph->mutex);
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
	if (ft_read_value(&ph->info->end, &ph->info->end_mutex) == 0)
	{
		printf("%lu %d is thinking\n", time, ph->id);
	}
	pthread_mutex_unlock(&ph->info->print);
}
