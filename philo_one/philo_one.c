/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 16:31:16 by zdnaya            #+#    #+#             */
/*   Updated: 2021/04/25 01:32:40 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

void print(t_data *data)
{
    // printf("philo_nbt=>%u\n", data->nbr_philo);
    // printf("t_die=>%llu\n", data->t_die);
    // printf("t_eat=>%llu\n", data->t_eat);
    // printf("t_sleep=>%llu\n", data->t_sleep);
    // printf("round_eat=>%u\n", data->round_eat);
    puts("philosophe_data:\n");
    int  i = 0;
    while ( i <=  data->nbr_philo)
    {
        printf("-------for philosophe %d------------------\n",i);
        printf("position=>%u\n", data->philosophe[i].is_sit_in);
        printf("t_think=>%d\n",    data->philosophe[i].is_thinking);
        printf("t_eat=>%d\n", data->philosophe[i].is_eating );
        printf("t_sleep=>%u\n",data->philosophe[i].is_sleeping);
        printf("round_eat=>%u\n", data->philosophe[i].eating_round);
        printf("left_fork=>%u\n", data->philosophe[i].left_fork);
        printf("right_fork=>%u\n", data->philosophe[i].right_fork);
        puts("------------------------------------------------\n");
        i++;
    }
}

void    *i_dont_know(void *arg)
{
    t_data *data;
    
    data = (t_data *)arg;

    data->philosophe = init_philo(data);
    print(data);
    if ( data->philosophe->is_thinking == 1)
        ft_putstr_fd("Philososphe is Thinking",1);
    return(arg);
}

void    creat_threads(t_data *data)
{
    int j;
    
    j = 0;
    while (j < data->nbr_philo)
    {
        pthread_create(&data->philo[j], NULL, i_dont_know ,(void *)data);
        j++;
    }
}

int main(int ac, char **av)
{
    t_data data;
    pthread_t test;

    initial_data(ac, av, &data);
    creat_threads(&data);
    
}