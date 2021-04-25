/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:39:14 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/25 02:32:34 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosepher.h"


void    initial_data(int ac, char **av,t_data *data)
{
    if ( ac < 5 || ac > 6)
        ft_putstr_fd("Error: bad arguments number\n", 1);
    data->nbr_philo = (unsigned int) my_atoi(av[1]);
    data->t_die = my_atoi(av[2]);
    data->t_eat = my_atoi(av[3]);
    data->t_sleep = my_atoi(av[4]);
    if (av[5])
        data->round_eat = (unsigned int) my_atoi(av[5]);
    else
        data->round_eat = 0;
    data->nbr_forks =  (unsigned int) my_atoi(av[1]);
    data->philo = malloc(sizeof(pthread_t) * (data->nbr_philo));
    data->forks = malloc(sizeof(pthread_mutex_t) *(data->nbr_forks));
    if (!data->philo || !data->forks)
        return ;
    data->is_thinking = 1;
    data->is_eating = 0;
    data->is_sleeping = 0;
    data->is_sit_in = 0;
}



