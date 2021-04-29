# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zainabdnayagmail.com <zainabdnayagmail.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 23:41:39 by zainabdnaya       #+#    #+#              #
#    Updated: 2021/04/29 00:55:20 by zainabdnaya      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= philo_one
OBJ_PATH= obj
H_FLAG= -I ./philosepher.h
COMP= gcc
# FLAGS= -Wall -Wextra -Werror


SRC= philo_one.c\
	mutex_forks_eat.c\
	 ft_atoi.c\
	  init.c\
	  needed.c\
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


#  @echo " \033[94m ------- Made by :Zdnaya -------\033[0m"
# 	 @echo " 	██████╗ ██╗  ██╗██╗██╗      ██████╗ ███████╗███████╗██████╗ ██╗  ██╗███████╗██████╗   "
# 	 @echo " 	██╔══██╗██║  ██║██║██║     ██╔═══██╗██╔════╝██╔════╝██╔══██╗██║  ██║██╔════╝██╔══██╗  "
# 	 @echo " 	██████╔╝███████║██║██║     ██║   ██║███████╗█████╗  ██████╔╝███████║█████╗  ██████╔╝  "
# 	 @echo " 	██╔═══╝ ██╔══██║██║██║     ██║   ██║╚════██║██╔══╝  ██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗  "
# 	 @echo " 	██║     ██║  ██║██║███████╗╚██████╔╝███████║███████╗██║     ██║  ██║███████╗██║  ██║  " 
# 	 @echo " 	╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝╚══════╝╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝  "   