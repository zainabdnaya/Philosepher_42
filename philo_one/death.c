/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 09:40:00 by zdnaya            #+#    #+#             */
/*   Updated: 2021/05/15 09:40:20 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

void *death(void *dt)
{
    t_philo_state *data;
    u_int64_t t;
    int i;

    data = (t_philo_state *)dt;
    while (1)
    {
        pthread_mutex_lock(&data->mtx_death);
        if ((data->numbr != -1))
        {

            i = 0;
            while (i < data->ph_nbr)
            {
                if (data->idx > data->numbr)
                    data->done++;
                i++;
            }
            if (data->done == data->ph_nbr)
            {
                pthread_mutex_lock(data->is_death);
                display_msg(data, 6);
                pthread_mutex_unlock(&data->mtx_death);
                pthread_mutex_unlock(data->philo_dead);
                break;
            }
            pthread_mutex_unlock(&data->mtx_death);
            usleep(100);
        }
        else if ((time_data() - data->last_meal > data->die && data->status != EAT))
        {
            pthread_mutex_lock(data->is_death);
            display_msg(data, 5);
            pthread_mutex_unlock(&data->mtx_death);
            pthread_mutex_unlock(data->philo_dead);
            break;
        }
        pthread_mutex_unlock(&data->mtx_death);
        usleep(100);
    }
    return (data);
}