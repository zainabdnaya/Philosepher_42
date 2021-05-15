/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 10:31:33 by zdnaya            #+#    #+#             */
/*   Updated: 2021/05/15 17:23:23 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

void *count_eat(void *arg)
{
    t_philo_state *data;
    int i;

    i = 0;

    data = (t_philo_state *)arg;

    while (1)
    {

        sem_wait(data->mtx_death);
        sem_wait(data->test);
        data->idx++;
        if (data->idx >= data->ph_nbr * (data->numbr))
        {
            sem_wait(data->msg);
            data->time = time_data() - data->start;
            printf("\033[31mAT %lld ms\t\t: STOP Stimulation! \n", data->time);
            usleep(500);
            sem_post(data->philo_dead);
            break;
        }
        usleep(100);
        sem_post(data->mtx_death);
    }
    return (arg);
}

void *death(void *dt)
{
    t_philo_state *data;
    u_int64_t t;
    int i;

    data = (t_philo_state *)dt;
    while (1)
    {

        sem_wait(data->mtx_death);
        // if ((data->numbr != -1))
        // {

        //     i = 0;
        //     while (i < data->ph_nbr)
        //     {
        //         if (data->idx > data->numbr)
        //             data->done++;
        //         i++;
        //     }
        //     if (data->done == data->ph_nbr)
        //     {
        //         sem_wait(data->msg);
        //         data->time = time_data() - data->start;
        //         usleep(3);
        //         printf("\033[31mAT %lld ms\t\t: STOP Stimulation! \n", data->time);
        //         sem_post(data->mtx_death);
        //         usleep(500);
        //         sem_post(data->philo_dead);
        //         break;
        //     }
        // }
        // else
        {

            if ((time_data() - data->last_meal > data->die) && data->status != EAT)
            {
                data->time = time_data() - data->start;
                sem_wait(data->msg);
                printf("\033[31mAT %lld ms\t\t:\u2620 Philosopher %d is DEATH\n", data->time, data->is_sit_in); // sem_post(data->msg);
                // sem_post(data->mtx_death);
                // usleep(500);
                sem_post(data->philo_dead);
                break;
            }
        }
        sem_post(data->mtx_death);
        usleep(1000);
    }
    return (data);
}