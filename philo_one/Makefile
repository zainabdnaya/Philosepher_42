# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 23:41:39 by zainabdnaya       #+#    #+#              #
#    Updated: 2021/05/15 09:58:33 by zdnaya           ###   ########.fr        #
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
	  death.c\


OBJ_NAME= $(SRC:.c=.o)

OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all:			$(NAME)

$(NAME) :  $(OBJ)
	@rm -rf $(NAME)
	@$(COMP) $(H_FLAG) $(OBJ) -o $@
	@echo "\033[95m --------------------------- Philo_one has been created successfully ------------------------------\n\033[0m"                                                                                                                                                                                                                                                                              
	@echo "  PPPPPPPPPPPPPPPPP   hhhhhhh               iiii  lllllll                                                                                                 "
	@echo "  P::::::::::::::::P  h:::::h              i::::i l:::::l                                                                                                 "
	@echo "  P::::::PPPPPP:::::P h:::::h               iiii  l:::::l                                                                                                 "
	@echo "  PP:::::P     P:::::Ph:::::h                     l:::::l                                                                                                 "
	@echo "    P::::P     P:::::P h::::h hhhhh       iiiiiii  l::::l    ooooooooooo                              ooooooooooo   nnnn  nnnnnnnn        eeeeeeeeeeee    "
	@echo "    P::::P     P:::::P h::::hh:::::hhh    i:::::i  l::::l  oo:::::::::::oo                          oo:::::::::::oo n:::nn::::::::nn    ee::::::::::::ee  "
	@echo "    P::::PPPPPP:::::P  h::::::::::::::hh   i::::i  l::::l o:::::::::::::::o                        o:::::::::::::::on::::::::::::::nn  e::::::eeeee:::::ee"
	@echo "    P:::::::::::::PP   h:::::::hhh::::::h  i::::i  l::::l o:::::ooooo:::::o                        o:::::ooooo:::::onn:::::::::::::::ne::::::e     e:::::e"
	@echo "    P::::PPPPPPPPP     h::::::h   h::::::h i::::i  l::::l o::::o     o::::o                        o::::o     o::::o  n:::::nnnn:::::ne:::::::eeeee::::::e"
	@echo "    P::::P             h:::::h     h:::::h i::::i  l::::l o::::o     o::::o                        o::::o     o::::o  n::::n    n::::ne:::::::::::::::::e "
	@echo "    P::::P             h:::::h     h:::::h i::::i  l::::l o::::o     o::::o                        o::::o     o::::o  n::::n    n::::ne::::::eeeeeeeeeee  "
	@echo "    P::::P             h:::::h     h:::::h i::::i  l::::l o::::o     o::::o                        o::::o     o::::o  n::::n    n::::ne:::::::e           "
	@echo "  PP::::::PP           h:::::h     h:::::hi::::::il::::::lo:::::ooooo:::::o                        o:::::ooooo:::::o  n::::n    n::::ne::::::::e          "
	@echo "  P::::::::P           h:::::h     h:::::hi::::::il::::::lo:::::::::::::::o                        o:::::::::::::::o  n::::n    n::::n e::::::::eeeeeeee  "
	@echo "  P::::::::P           h:::::h     h:::::hi::::::il::::::l oo:::::::::::oo                          oo:::::::::::oo   n::::n    n::::n  ee:::::::::::::e  "
	@echo "  PPPPPPPPPP           hhhhhhh     hhhhhhhiiiiiiiillllllll   ooooooooooo                              ooooooooooo     nnnnnn    nnnnnn    eeeeeeeeeeeeee  "
	@echo "                                                                           ________________________                                                       "
	@echo "                                                                           _::::::::::::::::::::::_                                                       "
	@echo "                                                                           ________________________                                                       "
                                                                                                                                                    
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
