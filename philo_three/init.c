/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:25:57 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/05/12 23:18:27 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosepher.h"

void check_error(int ac, char **av)
{
    if (ac < 5 || ac > 6)
        handle_errors("Error: Less or more Arguments!\n");
    if (!check_digit(av[1]) || !check_digit(av[2]) ||
        !check_digit(av[3]) || !check_digit(av[4]))
        handle_errors("Error: You should put just Numbers!\n");
    if (ac == 6 && !check_digit(av[5]))
        handle_errors("Error: You should put just Numbers!\n");
    if (my_atoi(av[1]) < 0 || my_atoi(av[1]) > 200)
        handle_errors("Error: The philosepher should be > 0 & not more than 200 strict!\n");
    if (my_atoi(av[2]) <= 60 || my_atoi(av[3]) <= 60 || my_atoi(av[4]) <= 60)
        handle_errors("Error: The av[2],av[3],av[4] should be >= 60!\n");
    if (ac == 6 && my_atoi(av[5]) <= 0)
        handle_errors("Error: The Round of eating should be > 0!\n");
}

sem_t *open_sem(unsigned int n, char *fd_name)
{
    sem_t *semaphore;

    sem_unlink(fd_name);
    semaphore = sem_open(fd_name, O_CREAT, 0777, n);
    return (semaphore);
}

void initial_sem(t_data *data)
{
    data->forks = open_sem(data->nbr_forks, "fork");
    data->mtx_death = open_sem(1, "mtx_death");
    data->msg = open_sem(1, "msg");
    data->philo_dead = open_sem(1, "philo_dead");
}
void init_philos(char **av, t_data *data)
{
    int i;
    unsigned long long time;

    i = 0;
    time = time_data();
    while (i < data->nbr_philo)
    {
        data->philos[i].is_sit_in = i + 1;
        data->philos[i].start = time;
        data->philos[i].last_meal = time_data();
        data->philos[i].die = data->t_die;
        data->philos[i].eat = data->t_eat;
        data->philos[i].sleep = data->t_sleep;
        data->philos[i].round_eat = data->nbr;
        data->philos[i].forks = data->forks;
        data->philos[i].mtx_death = data->mtx_death;
        data->philos[i].msg = data->msg;
        data->philos[i].philo_dead = data->philo_dead;
        data->philos[i].numbr = data->nbr;
        data->philos[i].done = 0;
        data->philos[i].ph_nbr = (unsigned int)my_atoi(av[1]);
        if (data->nbr != -1)
            data->philos[i].idx = 0;

        
        i++;
    }
}

void initial_data(char **av, t_data *data)
{
    data->nbr_philo = (unsigned int)my_atoi(av[1]);
    data->nbr_forks = (unsigned int)my_atoi(av[1]);
    data->t_die = my_atoi(av[2]);
    data->t_eat = (unsigned int)my_atoi(av[3]);
    data->t_sleep = my_atoi(av[4]);
    if (av[5])
        data->nbr = (unsigned int)my_atoi(av[5]);
    else
        data->nbr = -1;
    data->philos = (t_philo_state*)malloc(sizeof(*(data->philos)) * data->nbr_philo); 
    initial_sem(data);
    init_philos(av, data);

}