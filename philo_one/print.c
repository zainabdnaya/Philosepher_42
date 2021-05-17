/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 22:10:10 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/05/17 18:31:18 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

void display_msg(t_philo_state *data, int w)
{
    // sleep(10);
    pthread_mutex_lock(data->msg);
    if (w == 1)
    {
        data->time = time_data() - data->start;
        printf("\033[94mAT %lld ms\t\t:Philosophe %d is Thinking!\033[0m\n", data->time, data->is_sit_in);
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
        data->status = SLEEP;
    }
    else if (w == 4)
    {
        data->time = time_data() - data->start;
        printf("AT %lld ms\t\t:The philosepher \033[31m%d\033[0m is taking the FORK \n", data->time, data->is_sit_in);
    }
    pthread_mutex_unlock(data->msg);
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