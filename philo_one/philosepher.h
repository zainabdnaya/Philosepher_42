/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosepher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 23:44:09 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/04/29 02:57:48 by zainabdnaya      ###   ########.fr       */
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
# include <string.h>
# define  THINKING '0'
# define  EAT '1'
# define  SLEEP '2'

typedef struct s_pilo_state
{
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
        pthread_t       *philo;
    pthread_mutex_t     *forks;
    char                *status;
    int                 is_sit_in;
    int                 is_sleeping;
    int                 left_fork;
    int                 right_fork;
    int                 is_thinking;
    uint64_t            time;
    uint64_t            last_meal;
    uint64_t            *start;
    pthread_mutex_t     is_eating;
    pthread_mutex_t     mtx_death;
    pthread_mutex_t     msg;
    int                 death;
    int                 index;
    int                 fork_nbr;
}               t_data;
void                    ft_putstr_fd(char *s, int fd);
void                    initial_data(int ac, char **av,t_data *data);
void                    display_msg(t_data *data, int w);
void                    pickup_forks(t_data *data);
void                    eating_time(t_data *data);
void                    put_down_forks(t_data *data);

uint64_t                time_data(void);
uint64_t                my_atoi(const char *str);

size_t                  ft_strlen(const char *s);

int                     handle_errors(char const *str);
int                     death(t_data *data, int w);
#endif