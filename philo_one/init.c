/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:39:14 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/26 00:57:31 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosepher.h"


void    initial_data(int ac, char **av,t_data *data)
{
    int i;

    i = 0;
    if (ac < 5 || ac > 6)
        ft_putstr_fd("Error: bad arguments number\n", 1);
    data->nbr_philo = (unsigned int) my_atoi(av[1]);
    data->nbr_forks =  (unsigned int) my_atoi(av[1]);
    data->t_die = my_atoi(av[2]);
    data->t_eat = my_atoi(av[3]);
    data->t_sleep = my_atoi(av[4]);
    if (av[5])
        data->round_eat = (unsigned int) my_atoi(av[5]);
    else
        data->round_eat = 0;
    data->philo = (pthread_t *) malloc(sizeof(pthread_t) * (data->nbr_philo));
    data->forks =  (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) *(data->nbr_forks));
    data->status = malloc(sizeof(char) * (data->nbr_philo + 1));
    while (i < data->nbr_philo)
    {
        data->status[i] = THINKING ;
        i++;
    }
    data->status[i] = '\0';
}



