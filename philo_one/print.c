/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 22:10:10 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/29 02:48:16 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

void display_msg(t_data *data, int w)
{
    pthread_mutex_lock(&data->msg);
    if (w == 1)
    {
        data->time = time_data() - data->start[data->index];
        printf("\033[94mAT %lld ms\t\t:Philosophe %d is Thinking!\033[0m\n", data->time, data->nbr_philo);
    }
    if (w == 2)
    {
        data->time = time_data() - data->start[data->index];
        printf("\033[32mAT %lld ms\t\t:Philosopher %d is eating\033[0m\n", data->time, data->nbr_philo);
    }
    if (w == 3)
    {
        data->time = time_data() - data->start[data->index];
        printf("\033[32mAT %lld ms\t\t:Philosopher %d is sleeping\033[0m\n", data->time, data->nbr_philo);
    }
    if (w == 4)
    {
        data->fork_nbr++;
        printf("\033[0;30mAT %lld ms\t\t:The philosepher \033[31m%d\033[0m take the fork %d\n", data->time, data->nbr_philo, data->fork_nbr);
    }
    pthread_mutex_unlock(&data->msg);
}

int handle_errors(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	return (1);
}