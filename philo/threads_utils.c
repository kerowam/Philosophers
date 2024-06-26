/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 04:39:30 by gfredes-          #+#    #+#             */
/*   Updated: 2024/04/17 19:49:30 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_end_checker(void *info)
{
	t_info	*inf;

	inf = (t_info *)info;
	while (1)
	{
		if (ft_check_finished(inf) == 1)
			break ;
		pthread_mutex_lock(&inf->death_mutex);
		if (inf->death == 1)
		{
			pthread_mutex_unlock(&inf->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&inf->death_mutex);
		usleep(100);
	}
	return ((void *)0);
}

int	ft_init_thread(pthread_t *thread, void *(*routine)(void *), void *arg)
{
	if (pthread_create(thread, NULL, routine, arg))
	{
		printf("Error: thread creation failed\n");
		return (1);
	}
	return (0);
}

int	ft_join_thread(pthread_t thread)
{
	if (pthread_join(thread, NULL))
	{
		printf("Error: thread join failed\n");
		return (1);
	}
	return (0);
}

int	ft_join_threads(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nbr_of_philos)
	{
		if (ft_join_thread(info->threads_id[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	ft_set_value(int *value, int new_value, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*value = new_value;
	pthread_mutex_unlock(mutex);
}
