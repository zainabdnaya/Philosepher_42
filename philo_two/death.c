/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 10:02:14 by zdnaya            #+#    #+#             */
/*   Updated: 2021/05/15 10:03:22 by zdnaya           ###   ########.fr       */
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
        sem_wait(data->mtx_death);
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
                sem_wait(data->msg);
                data->time = time_data() - data->start;
                usleep(3);
                printf("\033[31mAT %lld ms\t\t: STOP Stimulation! \n", data->time);
                sem_post(data->mtx_death);
                sem_post(data->philo_dead);
                break;
            }
        }
        else
        {

            if ((time_data() - data->last_meal > data->die) && data->status != EAT)
            {
                sem_wait(data->msg);
                data->time = time_data() - data->start;
                printf("\033[31mAT %lld ms\t\t:\u2620 Philosopher %d is DEATH\n", data->time, data->is_sit_in); // sem_post(data->msg);
                sem_post(data->mtx_death);
                usleep(400);
                sem_post(data->philo_dead);
                break;
            }
        }
        usleep(100);
        sem_post(data->mtx_death);
    }
    return (data);
}