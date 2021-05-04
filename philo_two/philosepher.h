/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosepher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:58:10 by zdnaya            #+#    #+#             */
/*   Updated: 2021/05/04 14:04:08 by zdnaya           ###   ########.fr       */
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
# include <semaphore.h>

typedef struct s_pilo_state
{
        int idx;
        int numbr;
        int is_sleeping;
        int left_fork;
        int right_fork;
        int fork_nbr;
        int ph_nbr;
        int is_sit_in;
        int done;
    
        char status;
        
    uint64_t start;
    uint64_t last_meal;
    uint64_t die;
    uint64_t eat;
    uint64_t sleep;
    uint64_t time;

    unsigned int round_eat;
} t_philo_state;

typedef struct s_data
{
    t_philo_state *philos;

    int index;
    int nbr;
    int death;

    unsigned int nbr_forks;
    unsigned int nbr_philo;

    uint64_t t_die;
    uint64_t t_eat;
    uint64_t t_sleep;
} t_data;

uint64_t my_atoi(const char *str);
size_t ft_strlen(const char *s);

int handle_errors(char const *str);
int check_digit(const char *s);

void check_error(int ac, char **av);
#endif