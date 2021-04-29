/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_forks_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:24:48 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/29 11:55:10 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

void pickup_forks(t_data *data)
{
    if (pthread_mutex_lock(&data->forks[data->index]) == 0)
    {
        death(data, 2);
        display_msg(data, 4);
    }
    if (pthread_mutex_lock(&data->forks[(data->index + 1) % data->nbr_philo]) == 0)
    {
        death(data, 2);
        display_msg(data, 4);
        data->status[data->index] = EAT;
    }
}

void eating_time(t_data *data)
{
    if (data->status[data->index] == EAT)
    {
        pthread_mutex_lock(&data->is_eating);
        display_msg(data, 2);
        usleep(1000 * (data->t_eat));
        pthread_mutex_unlock(&data->is_eating);
        data->last_meal = time_data();
    }
}

void put_down_forks(t_data *data)
{
    pthread_mutex_unlock(&data->forks[data->index]);
    pthread_mutex_unlock(&data->forks[((data->index + 1) % (data->nbr_philo))]);
    display_msg(data, 3);
    usleep(data->t_sleep * 1000);
}