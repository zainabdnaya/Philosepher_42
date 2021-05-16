# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/08 20:49:54 by zainabdnaya       #+#    #+#              #
#    Updated: 2021/05/16 16:11:59 by zdnaya           ###   ########.fr        #
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
	@echo "\033[95m --------------------------- philo_three has been created successfully ------------------------------\n\033[0m"  
	@echo " PPPPPPPPPPPPPPPPP   hhhhhhh               iiii  lllllll                                       tttt         hhhhhhh                                                                         "
	@echo " P::::::::::::::::P  h:::::h              i::::i l:::::l                                     ttt:::t         h:::::h                                                                         "
	@echo " P::::::PPPPPP:::::P h:::::h               iiii  l:::::l                                     t:::::t         h:::::h                                                                         "
	@echo " PP:::::P     P:::::Ph:::::h                     l:::::l                                     t:::::t         h:::::h                                                                         "
	@echo "   P::::P     P:::::P h::::h hhhhh       iiiiiii  l::::l    ooooooooooo                ttttttt:::::ttttttt    h::::h hhhhh      rrrrr   rrrrrrrrr       eeeeeeeeeeee        eeeeeeeeeeee     "
	@echo "   P::::P     P:::::P h::::hh:::::hhh    i:::::i  l::::l  oo:::::::::::oo              t:::::::::::::::::t    h::::hh:::::hhh   r::::rrr:::::::::r    ee::::::::::::ee    ee::::::::::::ee   "
	@echo "   P::::PPPPPP:::::P  h::::::::::::::hh   i::::i  l::::l o:::::::::::::::o             t:::::::::::::::::t    h::::::::::::::hh r:::::::::::::::::r  e::::::eeeee:::::ee e::::::eeeee:::::ee "
	@echo "   P:::::::::::::PP   h:::::::hhh::::::h  i::::i  l::::l o:::::ooooo:::::o             tttttt:::::::tttttt    h:::::::hhh::::::hrr::::::rrrrr::::::re::::::e     e:::::ee::::::e     e:::::e "
	@echo "   P::::PPPPPPPPP     h::::::h   h::::::h i::::i  l::::l o::::o     o::::o                   t:::::t          h::::::h   h::::::hr:::::r     r:::::re:::::::eeeee::::::ee:::::::eeeee::::::e "
	@echo "   P::::P             h:::::h     h:::::h i::::i  l::::l o::::o     o::::o                   t:::::t          h:::::h     h:::::hr:::::r     rrrrrrre:::::::::::::::::e e:::::::::::::::::e  "
	@echo "   P::::P             h:::::h     h:::::h i::::i  l::::l o::::o     o::::o                   t:::::t          h:::::h     h:::::hr:::::r            e::::::eeeeeeeeeee  e::::::eeeeeeeeeee   "
	@echo "   P::::P             h:::::h     h:::::h i::::i  l::::l o::::o     o::::o                   t:::::t    tttttth:::::h     h:::::hr:::::r            e:::::::e           e:::::::e            "
	@echo " PP::::::PP           h:::::h     h:::::hi::::::il::::::lo:::::ooooo:::::o                   t::::::tttt:::::th:::::h     h:::::hr:::::r            e::::::::e          e::::::::e           "
	@echo " P::::::::P           h:::::h     h:::::hi::::::il::::::lo:::::::::::::::o                   tt::::::::::::::th:::::h     h:::::hr:::::r             e::::::::eeeeeeee   e::::::::eeeeeeee   "
	@echo " P::::::::P           h:::::h     h:::::hi::::::il::::::l oo:::::::::::oo                      tt:::::::::::tth:::::h     h:::::hr:::::r              ee:::::::::::::e    ee:::::::::::::e   "
	@echo " PPPPPPPPPP           hhhhhhh     hhhhhhhiiiiiiiillllllll   ooooooooooo                          ttttttttttt  hhhhhhh     hhhhhhhrrrrrrr                eeeeeeeeeeeeee      eeeeeeeeeeeeee   "
	@echo "                                                                          ________________________                                                                                                      "
	@echo "                                                                          _::::::::::::::::::::::_                                                                                                      "
	@echo "                                                                          ________________________                                                                                                      "                                                                                                                                               
	@echo " \033[95m \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Made by : Zdnaya \033[0m"

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
