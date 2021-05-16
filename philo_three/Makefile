# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/08 20:49:54 by zainabdnaya       #+#    #+#              #
#    Updated: 2021/05/16 20:52:33 by zainabdnaya      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= philo_three
OBJ_PATH= obj
H_FLAG= -I ./philosepher.h
COMP= gcc
# FLAGS= -Wall -Wextra -Werror


SRC= philo_three.c\
	eat_sleep.c\
	 my_atoi.c\
	  init.c\
	  print.c\
	   death.c \
	 


OBJ_NAME= $(SRC:.c=.o)

OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all:			$(NAME)

$(NAME) :  $(OBJ)
	@rm -rf $(NAME)
	@$(COMP) $(H_FLAG) $(OBJ) -g -o $@
	

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


	