/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 22:10:10 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/05/03 16:22:31 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

void *death(void *dt)
{
    t_philo_state *data;
    u_int64_t t;

    data = (t_philo_state *)dt;
    while (1)
    {
        pthread_mutex_lock(&data->mtx_death);
        if ((data->numbr != -1))
        {
            int i;

            i = 0;
            // printf("==>%d<==\n", data->ph_nbr);
            while (i < data->ph_nbr)
            {
                if ( data->idx >= data->numbr)
                    data->done++;
                i++;
            }
            if (data->done == data->ph_nbr)
            {
                data->time = time_data() - data->start;
                usleep(5);
                printf("\033[31mAT %lld ms\t\t: STOP Stimulation! \n", data->time);
                pthread_mutex_unlock(&data->mtx_death);
                pthread_mutex_unlock(data->philo_dead);
                pthread_mutex_lock(data->is_death);
                break;
                }
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

void display_msg(t_philo_state *data, int w)
{
    pthread_mutex_lock(&data->msg);
    if (w == 1)
    {
        data->time = time_data() - data->start;
        printf("\033[94mAT %lld ms\t\t:Philosophe %d is Thinking!\033[0m\n", data->time, data->is_sit_in);
        // usleep(5);
        data->status = THINKING;
    }
    else if (w == 2)
    {
        printf("\033[32mAT %lld ms\t\t:Philosopher %d is eating\033[0m\n", time_data() - data->start, data->is_sit_in);
    }
    else if (w == 3)
    {
        data->time = time_data() - data->start;
        printf("\033[32mAT %lld ms\t\t:Philosopher %d is sleeping\033[0m\n", data->time, data->is_sit_in);
        // usleep(5);
        data->status = SLEEP;
    }
    else if (w == 4)
    {
        data->time = time_data() - data->start;
        // usleep(5);
        printf("AT %lld ms\t\t:The philosepher \033[31m%d\033[0m is taking the FORK \n", data->time, data->is_sit_in);
    }
    else if (w == 5)
    {
        data->time = time_data() - data->start;
        // usleep(5);
        printf("\033[31mAT %lld ms\t\t:\u2620 Philosopher %d is DEATH\n", data->time, data->is_sit_in);
    }
    pthread_mutex_unlock(&data->msg);
}

int handle_errors(char const *str)
{
    if (str)
        write(1, str, ft_strlen(str));
    exit(1);
}

void free_ph(t_philo_state **philo)
{
    if (*philo)
    {
        free(*philo);
        *philo = NULL;
    }
    philo = NULL;
}