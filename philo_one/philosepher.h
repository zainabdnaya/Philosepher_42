/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosepher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 23:44:09 by zainabdnaya       #+#    #+#             */
/*   Updated: 2021/05/01 04:27:53 by zainabdnaya      ###   ########.fr       */
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

static int dies = 0;

typedef struct s_pilo_state
{
    pthread_mutex_t     *forks;
    int                 is_sleeping;
    int                 left_fork;
    int                 right_fork;
    int                 fork_nbr;
    int                 is_sit_in;
    char                status;
    pthread_mutex_t     is_eating;
    pthread_mutex_t     msg;
    pthread_mutex_t     mtx_death;
    uint64_t            start;
    uint64_t            last_meal; 
    uint64_t            die;
    uint64_t            eat;
    uint64_t            sleep; 
    uint64_t            time;

    unsigned int        round_eat;
}              t_philo_state;

typedef struct s_data
{
    pthread_mutex_t     is_eating;
    pthread_mutex_t     msg;
    pthread_mutex_t     mtx_death;
    int                 nbr;
    int                 death;
    int                 index;
    unsigned int        nbr_forks;
    unsigned int        nbr_philo;
    t_philo_state       **philos;
    pthread_mutex_t     *forks;
    uint64_t            t_die;
    uint64_t            t_eat;
    uint64_t            t_sleep;
} t_data;

void                    ft_putstr_fd(char *s, int fd);
void                    initial_data(int ac, char **av,t_data *data);
void                    display_msg(t_philo_state *data, int w);
void                    pickup_forks(t_philo_state  *data);
void                    eating_time(t_philo_state   *data);
void                    put_down_forks(t_philo_state *data);

uint64_t                time_data(void);
uint64_t                my_atoi(const char *str);

size_t                  ft_strlen(const char *s);

int                     handle_errors(char const *str);
void                    *death(void *dt);
#endif