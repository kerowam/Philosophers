/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:09:24 by gfredes-          #+#    #+#             */
/*   Updated: 2024/03/25 15:10:31 by gfredes-         ###   ########.fr       */
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

void	print_info(t_info *info)
{
	printf("Number of philosophers: %d\n", info->nbr_of_philos);
	printf("Time to die: %llu\n", info->time_to_die);
	printf("Time to eat: %llu\n", info->time_to_eat);
	printf("Time to sleep: %llu\n", info->time_to_sleep);
	printf("Number of times each philosopher must eat: %d\n", info->nbr_of_times_each_philo_must_eat);
}
