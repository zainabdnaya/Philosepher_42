/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosepher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:48:02 by zdnaya            #+#    #+#             */
/*   Updated: 2021/05/19 11:00:47 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSEPHER_H
# define PHILOSEPHER_H
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
	int				idx;
	int				numbr;
	int				is_sleeping;
	int				left_fork;
	int				right_fork;
	int				fork_nbr;
	int				ph_nbr;
	int				is_sit_in;
	int				done;
	char			status;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*msg;
	pthread_mutex_t	mtx_death;
	pthread_mutex_t	*is_death;
	pthread_mutex_t	*philo_dead;
	uint64_t		start;
	uint64_t		last_meal;
	uint64_t		die;
	uint64_t		eat;
	uint64_t		sleep;
	uint64_t		time;
	unsigned int	round_eat;
}			t_philo_state;

typedef struct s_data
{
	t_philo_state	*philos;
	pthread_mutex_t	*msg;
	pthread_mutex_t	mtx_death;
	pthread_mutex_t	*is_death;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*philo_dead;
	int				index;
	int				nbr;
	int				death;
	unsigned int	nbr_forks;
	unsigned int	nbr_philo;
	uint64_t		t_die;
	uint64_t		t_eat;
	uint64_t		t_sleep;
}					t_data;
void		ft_putstr_fd(char *s, int fd);
void		initial_data( char **av, t_data *data);
void		display_msg(t_philo_state *data, int w);
void		pickup_forks(t_philo_state *data);
void		eating_time(t_philo_state *data);
void		check_error(int ac, char **av);
void		put_down_forks(t_philo_state *philo);
void		free_ph(t_philo_state **philo);
void		*death(void *dt);
uint64_t	time_data(void);
uint64_t	my_atoi(const char *str);
size_t		ft_strlen(const char *s);
int			handle_errors(char const *str);
int			check_digit(const char *s);
#endif
