/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:56:08 by gfredes-          #+#    #+#             */
/*   Updated: 2024/03/29 01:17:24 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args_number(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: wrong number of arguments\n");
		printf("Usage: ./philo <number_of_philosophers> <time_to_die time_to_eat> \
			<time_to_sleep> [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	return (0);
}

int	check_all_args_are_numbers(char **argv)
{
	int	i;
	int	n;

	i = 1;
	while (argv[i])
	{
		n = 0;
		while (argv[i][n])
		{
			if (argv[i][n] < '0' || argv[i][n] > '9')
			{
				printf("Error: invalid argument\n");
				return (1);
			}
			n++;
		}
		i++;
	}
	return (0);
}

int	check_number_of_philos_and_meals(char *philos, char *meals)
{
	if (ft_atoi(philos) < 1)
	{
		printf("Error: philo don't work without philosophers\n");
		return (1);
	}
	if (ft_atoi(meals) < 1)
	{
		printf("Error: philo don't work without meals\n");
		return (1);
	}
	return (0);
}

int	check_time(char *time_to_die, char *time_to_eat, char *time_to_sleep)
{
	if (ft_atoi(time_to_die) < 0 || ft_atoi(time_to_eat) < 0
		|| ft_atoi(time_to_sleep) < 0)
	{
		printf("Error: time can't be negative\n");
		return (1);
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (check_args_number(argc) || check_all_args_are_numbers(argv)
		|| check_number_of_philos_and_meals(argv[1], argv[5])
		|| check_time(argv[2], argv[3], argv[4]))
		return (1);
	// check_max_int(argv);
	return (0);
}

/*int	check_max_int(char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > 2147483647)
		{
			printf("Error: argument too big\n");
			return (1);
		}
		i++;
	}
}*/
