/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 22:10:10 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/29 12:03:52 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

int death(t_data *data, int w)
{
    if (w == 1)
    {
        if (time_data() - data->last_meal >= data->t_die)
        {
            data->time = time_data() - data->start[data->index];
            printf("\033[31mAT %lld ms\t\t:\u2620 Philosopher %d is DEATH\n", data->time, data->index);
            exit(1);
        }
    }
    if (w == 2)
    {
        if (data->time > data->t_die)
        {
            data->time = time_data() - data->start[data->index];
            printf("\033[31mAT %lld ms\t:\u2620 Philosopher %d is DEATH\n", data->time,data->index);
            exit(1);
        }
    }
    pthread_mutex_unlock(&data->mtx_death);
    return (0);
}

void display_msg(t_data *data, int w)
{
    pthread_mutex_lock(&data->msg);
    if (w == 1 )
    {
        data->time = time_data() - data->start[data->index];
        printf("\033[94mAT %lld ms\t\t:Philosophe %d is Thinking!\033[0m\n", data->time, data->index + 1);
        data->status[data->index] = THINKING;
    }
    if (w == 2)
    {
        data->time = time_data() - data->start[data->index];
        printf("\033[32mAT %lld ms\t\t:Philosopher %d is eating\033[0m\n", data->time,data->index + 1);
        data->last_meal = time_data();
    }
    if (w == 3)
    {
        data->time = time_data() - data->start[data->index];
        printf("\033[32mAT %lld ms\t\t:Philosopher %d is sleeping\033[0m\n", data->time,data->index + 1);
    }
    if (w == 4)
    {
        data->fork_nbr++;
        printf("AT %lld ms\t\t:The philosepher \033[31m%d\033[0m take the fork %d\n", data->time, data->index + 1, data->fork_nbr);
    }
    pthread_mutex_unlock(&data->msg);
}

int handle_errors(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	return (1);
}