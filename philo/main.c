/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:56:34 by gfredes-          #+#    #+#             */
/*   Updated: 2024/03/25 13:56:34 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_end(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nbr_of_philos)
	{
		pthread_mutex_destroy(&info->forks[i]);
		pthread_mutex_destroy(&info->philos[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&info->print);
	pthread_mutex_destroy(&info->mutex);
	if (info->forks)
		free(info->forks);
	if (info->threads_id)
		free(info->threads_id);
	if (info->philos)
		free(info->philos);
}

void	ft_one_philo(t_info *info)
{
	info->start_time = ft_get_time();
	if (pthread_create(&info->threads_id[0], NULL, &one_philo_routine,
			&info->philos[0]))
	{
		printf("Error: thread creation failed\n");
		return ;
	}
	pthread_join(info->threads_id[0], NULL);
	ft_end(info);
	return ;
}

int	main(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (check_args(argc, argv))
		return (1);
	ft_get_info(info, argv);
	ft_init_philos(info);
	if (info->nbr_of_philos == 1)
	{
		ft_one_philo(info);
		return (1);
	}
	else
	{
		if (ft_threads(info))
			return (1);
	}
	ft_end(info);
	free(info);
	return (0);
}
