/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:25:36 by gfredes-          #+#    #+#             */
/*   Updated: 2024/04/17 19:26:48 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_mutex(t_info *info)
{
	pthread_mutex_init(&info->print, NULL);
	pthread_mutex_init(&info->mutex, NULL);
	pthread_mutex_init(&info->end_mutex, NULL);
	pthread_mutex_init(&info->death_mutex, NULL);
	pthread_mutex_init(&info->meal_mutex, NULL);
	pthread_mutex_init(&info->init_mutex, NULL);
}
