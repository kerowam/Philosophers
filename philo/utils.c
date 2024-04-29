/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:09:24 by gfredes-          #+#    #+#             */
/*   Updated: 2024/04/17 19:58:36 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	nb *= neg;
	return (nb);
}

void	ft_usleep(t_philo *ph, useconds_t time)
{
	struct timeval	start;
	struct timeval	end;
	useconds_t		time_passed;

	time_passed = 0;
	gettimeofday(&start, NULL);
	usleep(time * 920);
	while (time_passed < time * 1000
		&& ft_read_value(&ph->info->end, &ph->info->end_mutex) == 0)
	{
		gettimeofday(&end, NULL);
		time_passed = ((end.tv_sec - start.tv_sec) * 1000000)
			+ (end.tv_usec - start.tv_usec);
		usleep(time * 3);
		pthread_mutex_lock(&ph->info->death_mutex);
		if (ph->info->death == 1)
		{
			pthread_mutex_unlock(&ph->info->death_mutex);
			return ;
		}
		pthread_mutex_unlock(&ph->info->death_mutex);
	}
}

void	ft_check_info(t_info *info)
{
	if (info->time_to_eat < 60)
		info->time_to_eat = 60;
	if (info->time_to_sleep < 60)
		info->time_to_sleep = 60;
}

void	ft_add_delay(t_philo *ph)
{
	useconds_t	time;

	if (ph->info->time_to_eat > 0)
		time = ((ph->info->time_to_eat) / 2);
	else
		time = 1;
	ft_think(ph);
	ft_usleep(ph, time);
}

int	ft_read_value(int *value, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	if (*value == 0)
	{
		pthread_mutex_unlock(mutex);
		return (0);
	}
	else
	{
		pthread_mutex_unlock(mutex);
		return (1);
	}
}
