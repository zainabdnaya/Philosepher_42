/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 09:40:00 by zdnaya            #+#    #+#             */
/*   Updated: 2021/05/18 16:29:48 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

void	*death(void *dt)
{
	t_philo_state	*data;
	uint64_t		time;

	data = (t_philo_state *)dt;
	while (1)
	{
		pthread_mutex_lock(&data->mtx_death);
		if ((time_data() - data->last_meal >= data->die && data->status != EAT))
		{
			pthread_mutex_lock(data->is_death);
			pthread_mutex_lock(data->msg);
			time = time_data() - data->start;
			printf("\033[31mAT %lld ms\t\t:\u2620 Philosopher %d is DEATH\n",
				time, data->is_sit_in);
			pthread_mutex_unlock(&data->mtx_death);
			pthread_mutex_unlock(data->philo_dead);
			break ;
		}
		usleep(100);
		pthread_mutex_unlock(&data->mtx_death);
	}
	return (data);
}
