/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 21:04:22 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/05/08 23:38:07 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

uint64_t time_data(void)
{
    static struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
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
        if ((data->numbr != -1))
        {

            i = 0;
            while (i < data->ph_nbr)
            {
                if (data->idx >= data->numbr)
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

void display_msg(t_philo_state *data, int w)
{
    sem_wait(data->msg);
    if (w == 1)
    {
        data->time = time_data() - data->start;
        printf("\033[94mAT %lld ms\t\t:Philosophe %d is Thinking!\033[0m\n", data->time, data->is_sit_in);
        usleep(3);
        data->status = THINKING;
    }
    else if (w == 2)
    {
        printf("\033[32mAT %lld ms\t\t:Philosopher %d is eating\033[0m\n", time_data() - data->start, data->is_sit_in);
        usleep(3);
        data->status = EAT;
    }
    else if (w == 3)
    {
        data->time = time_data() - data->start;
        printf("\033[32mAT %lld ms\t\t:Philosopher %d is sleeping\033[0m\n", data->time, data->is_sit_in);
        usleep(3);
        data->status = SLEEP;
    }
    else if (w == 4)
    {
        data->time = time_data() - data->start;
        usleep(3);
        printf("AT %lld ms\t\t:The philosepher \033[31m%d\033[0m is taking the FORK \n", data->time, data->is_sit_in);
    }
    sem_post(data->msg);
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