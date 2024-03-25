/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:14:37 by gfredes-          #+#    #+#             */
/*   Updated: 2024/03/25 16:14:37 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	ft_get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_get_info(t_info *info, char **argv)
{
	info->nbr_of_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		info->nbr_of_times_each_philo_must_eat = ft_atoi(argv[5]);
	else
		info->nbr_of_times_each_philo_must_eat = -1;
	info->death = 0;
	info->finished = 0;
	info->start_time = ft_get_time();
}

void	ft_init_philos(t_info *info)
{
	int i;

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
		info->philos[i].last_meal = info->start_time;
		info->philos[i].meals_eaten = 0;
		info->philos[i].status = 0;
		info->philos[i].info = info;
		i++;
	}
}
