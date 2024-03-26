/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:28:36 by gfredes-          #+#    #+#             */
/*   Updated: 2024/03/26 15:28:36 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	while (ph->info->death == 0)
	{
		if (ph->info->death == 0)
			ft_think(ph);
		if (ph->info->death == 0)
			ft_eat(ph);
		if (ph->info->death == 0)
			ft_sleep(ph);
	}
	return (NULL);
}

void	ft_threads(t_info *info)
{
	
}