/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:09:24 by gfredes-          #+#    #+#             */
/*   Updated: 2024/03/30 23:17:32 by gfredes-         ###   ########.fr       */
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
	while (time_passed < time && ph->info->death == 0)
	{
		gettimeofday(&end, NULL);
		time_passed = ((end.tv_sec - start.tv_sec) * 1000000)
			+ (end.tv_usec - start.tv_usec);
		usleep(0);
		if (ph->info->death == 1)
			break ;
	}
}

/*void	print_info(t_info *info)
{
	printf("Number of philosophers: %d\n", info->nbr_of_philos);
	printf("Time to die: %lu\n", info->time_to_die);
	printf("Time to eat: %lu\n", info->time_to_eat);
	printf("Time to sleep: %lu\n", info->time_to_sleep);
	printf("Number of times each philosopher must eat: %d\n", info->nbr_of_times_each_philo_must_eat);
}*/
