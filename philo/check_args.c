/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:56:08 by gfredes-          #+#    #+#             */
/*   Updated: 2024/03/25 15:09:05 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_args_number(int argc)
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

int check_all_args_are_numbers(char **argv)
{
	int i;
	int n;

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

int	check_number_of_philosophers(char *argv)
{
	if (ft_atoi(argv) < 1)
	{
		printf("Error: philo don't work without philosophers\n");
		return (1);
	}
	return (0);
}

int	check_number_of_meals(char *argv)
{
	if (ft_atoi(argv) < 1)
	{
		printf("Error: philo don't work without meals\n");
		return (1);
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (check_args_number(argc) || check_all_args_are_numbers(argv)
		|| check_number_of_philosophers(argv[1]) || check_number_of_meals(argv[5]))
		return (1);
	check_args_number(argc);
	check_all_args_are_numbers(argv);
	// check_max_int(argv);
	check_number_of_philosophers(argv[1]);
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
