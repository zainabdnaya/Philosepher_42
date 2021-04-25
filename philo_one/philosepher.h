/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosepher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 23:44:09 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/25 01:44:45 by zainabdnaya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdio.h>

typedef struct s_pilo_state
{
    int                 is_sit_in;
    int                 is_thinking;
    int                 is_eating;
    int                 is_sleeping;
    int                 left_fork;
    int                 right_fork;
    int                 eating_round;
    
}              t_philo_state;

typedef struct s_data
{
    unsigned int        nbr_philo;
        uint64_t        t_die;
        uint64_t        t_eat;
        uint64_t        t_sleep;
    unsigned int        round_eat;
    unsigned int        nbr_forks;
    t_philo_state       *philosophe;
        pthread_t       *philo;
    pthread_mutex_t     *forks;
    
}               t_data;
void                    ft_putstr_fd(char *s, int fd);
void                    initial_data(int ac, char **av,t_data *data);
void                    init_philo(t_data *data);

uint64_t                my_atoi(const char *str);

#endif