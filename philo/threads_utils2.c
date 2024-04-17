/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:33:34 by gfredes-          #+#    #+#             */
/*   Updated: 2024/04/17 20:40:36 by gfredes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_manage_end_checker(pthread_t *thread, void *routine, t_info *info)
{
	if (ft_init_thread(thread, routine, info) == 1)
		return (1);
	if (ft_join_thread(*thread) == 1)
		return (1);
	return (0);
}
