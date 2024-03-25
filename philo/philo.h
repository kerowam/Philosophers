/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:55:58 by gfredes-          #+#    #+#             */
/*   Updated: 2024/03/25 13:55:58 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

//check_args.c
int check_args_number(int argc);
int check_all_args_are_numbers(char **argv);
int check_number_of_philosophers(char *argv);
int check_args(int argc, char **argv);
// int	check_max_int(char **argv);

//utils.c
int ft_atoi(const char *str);

#endif