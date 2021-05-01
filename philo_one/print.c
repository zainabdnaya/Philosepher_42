/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 22:10:10 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/05/01 17:04:47 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"


void *death(void *dt)
{
    t_philo_state *data;

    data = (t_philo_state*) dt;
    while (1)
    {
        pthread_mutex_lock(&data->mtx_death);
        // printf("==>%lld\n", time_data() - data->last_meal);
        if (time_data() - data->last_meal > data->die)
        {
            data->time = time_data() - data->start;
            pthread_mutex_lock(&data->msg);
            printf("\033[31mAT %lld ms\t\t:\u2620 Philosopher %d is DEATH\n", data->time, data->is_sit_in);
            pthread_mutex_unlock(&data->msg);
            // dies = 1;
            exit(1);
            // return (data);
            // exit(1);
        }
        usleep(100);
        pthread_mutex_unlock(&data->mtx_death);
    }
        // pthread_mutex_unlock(&data->mtx_death);
    return (data);
}

void display_msg(t_philo_state *data, int w)
{
    pthread_mutex_lock(&data->msg);
    if (w == 1 )
    {
        data->time = time_data() - data->start;
        printf("\033[94mAT %lld ms\t\t:Philosophe %d is Thinking!\033[0m\n", data->time, data->is_sit_in);
        data->status = THINKING;
    }
    else if (w == 2)
    {
        printf("\033[32mAT %lld ms\t\t:Philosopher %d is eating\033[0m\n", time_data() - data->start,data->is_sit_in);
        data->last_meal = time_data();
    }
    else if (w == 3)
    {
        data->time = time_data() - data->start;
        printf("\033[32mAT %lld ms\t\t:Philosopher %d is sleeping\033[0m\n", data->time, data->is_sit_in);
        data->status = SLEEP;
    }
    else if (w == 4)
    {
        data->time = time_data() - data->start;
        data->fork_nbr++;
        printf("AT %lld ms\t\t:The philosepher \033[31m%d\033[0m is taking the FORK \n", data->time, data->is_sit_in);
    }
    pthread_mutex_unlock(&data->msg);
    usleep(10);
}

int handle_errors(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	return (1);
}