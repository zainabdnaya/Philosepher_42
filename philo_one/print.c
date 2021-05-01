/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 22:10:10 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/05/01 04:29:40 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"


void *death(void *dt)
{
    t_philo_state *data;

    data = (t_philo_state*) dt;
    while (!dies)
    {
        pthread_mutex_lock(&data->mtx_death);
        if (time_data() - data->last_meal >= data->die)
        {
            data->time = time_data() - data->start;
            printf("\033[31mAT %lld ms\t\t:\u2620 Philosopher %d is DEATH\n", data->time, data->is_sit_in + 1);
            pthread_mutex_unlock(&data->mtx_death);
            // pthread_mutex_lock(&data->msg);
            dies = 1;
            usleep(10);
            exit(1);
            // return (data);
            // exit(1);
        }
        pthread_mutex_unlock(&data->mtx_death);
    }
        pthread_mutex_unlock(&data->mtx_death);
    return (data);
}

void display_msg(t_philo_state *data, int w)
{
    pthread_mutex_lock(&data->msg);
    if (w == 1 )
    {
        data->time = time_data() - data->start;
        printf("\033[94mAT %lld ms\t\t:Philosophe %d is Thinking!\033[0m\n", data->time, data->is_sit_in + 1);
        data->status = THINKING;
    }
    else if (w == 2)
    {
        printf("\033[32mAT %lld ms\t\t:Philosopher %d is eating\033[0m\n", time_data() - data->start,data->is_sit_in + 1);
        data->last_meal = time_data();
    }
    
    else if (w == 3)
    {
        data->time = time_data() - data->start;
        printf("\033[32mAT %lld ms\t\t:Philosopher %d is sleeping\033[0m\n", data->time, data->is_sit_in + 1);
        data->status = SLEEP;
    }
    else if (w == 4)
    {
        data->time = time_data() - data->start;
        data->fork_nbr++;
        printf("AT %lld ms\t\t:The philosepher \033[31m%d\033[0m take the fork %d\n", data->time, data->is_sit_in + 1, data->fork_nbr);
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