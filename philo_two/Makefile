# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/04 12:57:11 by zdnaya            #+#    #+#              #
#    Updated: 2021/05/05 23:37:37 by zainabdnaya      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= philo_two
OBJ_PATH= obj
H_FLAG= -I ./philosepher.h
COMP= gcc
# FLAGS= -Wall -Wextra -Werror


SRC= philo_two.c\
	mutex_forks_eat.c\
	 my_atoi.c\
	  init.c\
	  print.c\
	 


OBJ_NAME= $(SRC:.c=.o)

OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all:			$(NAME)

$(NAME) :  $(OBJ)
	@rm -rf $(NAME)
	@$(COMP) $(H_FLAG) $(OBJ) -o $@
	@echo "\033[95m ------- Philo_one has been created successfully -------\033[0m"

$(OBJ_PATH)/%.o: %.c 
	@mkdir -p $(OBJ_PATH) 
	@$(COMP) $(H_FLAG) $(FLAGS) -g -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[1;33m>> all objects files are deleted.\033[0m" 

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;31m>> $(NAME) && all obbjects are deleted.\033[0m" 

re : fclean all
