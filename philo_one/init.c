/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 20:39:14 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/05/01 03:32:48 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosepher.h"


void    initial_data(int ac, char **av,t_data *data)
{
    int i;

    i = 0;
    if (ac < 5 || ac > 6)
        handle_errors("Less or more Arguments!\n");
    data->nbr_philo = (unsigned int)my_atoi(av[1]);
    data->nbr_forks =  (unsigned int) my_atoi(av[1]);
    data->t_die = my_atoi(av[2]);
    data->t_eat = (unsigned int) my_atoi(av[3]);
    data->t_sleep = my_atoi(av[4]);
    if (av[5])
        data->nbr = (unsigned int) my_atoi(av[5]);
    else
        data->nbr = -1;
    data->philos =malloc(sizeof(t_philo_state *) * (data->nbr_philo)); 
    data->forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * (data->nbr_forks));
    pthread_mutex_init(&data->is_eating, NULL);
    pthread_mutex_init(&data->mtx_death, NULL);   
    pthread_mutex_init(&data->msg, NULL);
    long time = time_data();
    while( i < data->nbr_philo)
    {
        data->philos[i] = (t_philo_state *)malloc(sizeof(t_philo_state));
        data->philos[i]->is_sit_in = i;
        data->philos[i]->right_fork = i;
		data->philos[i]->left_fork = (i + 1) % data->nbr_philo;
        data->philos[i]->start = time;
        data->philos[i]->last_meal = time_data();
        data->philos[i]->die = data->t_die;
        data->philos[i]->eat = data->t_eat;
        data->philos[i]->sleep = data->t_sleep;
        data->philos[i]->round_eat = data->nbr;
        data->philos[i]->is_eating = data->is_eating;
        data->philos[i]->mtx_death = data->mtx_death;
        data->philos[i]->msg = data->msg;
        i++;
    }

}



