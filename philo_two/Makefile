# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/15 10:05:49 by zdnaya            #+#    #+#              #
#    Updated: 2021/05/15 10:09:47 by zdnaya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= philo_two
OBJ_PATH= obj
H_FLAG= -I ./philosepher.h
COMP= gcc
# FLAGS= -Wall -Wextra -Werror


SRC= philo_two.c\
	sem_forks_eat.c\
	 my_atoi.c\
	  init.c\
	  print.c\
	  death.c\
	 


OBJ_NAME= $(SRC:.c=.o)

OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all:			$(NAME)

$(NAME) :  $(OBJ)
	@rm -rf $(NAME)
	@$(COMP) $(H_FLAG) $(OBJ) -o $@
	@echo "\033[95m --------------------------- Philo_one has been created successfully ------------------------------\n\033[0m"                                                                                                                                                                    
	@echo " PPPPPPPPPPPPPPPPP   hhhhhhh               iiii  lllllll                                                   tttt                                                               "
	@echo " P::::::::::::::::P  h:::::h              i::::i l:::::l                                                ttt:::t                                                               "
	@echo " P::::::PPPPPP:::::P h:::::h               iiii  l:::::l                                                t:::::t                                                               "
	@echo " PP:::::P     P:::::Ph:::::h                     l:::::l                                                t:::::t                                                               "
	@echo "   P::::P     P:::::P h::::h hhhhh       iiiiiii  l::::l    ooooooooooo                           ttttttt:::::tttttttwwwwwww           wwwww           wwwwwww ooooooooooo    "
	@echo "   P::::P     P:::::P h::::hh:::::hhh    i:::::i  l::::l  oo:::::::::::oo                         t:::::::::::::::::t w:::::w         w:::::w         w:::::woo:::::::::::oo  "
	@echo "   P::::PPPPPP:::::P  h::::::::::::::hh   i::::i  l::::l o:::::::::::::::o                        t:::::::::::::::::t  w:::::w       w:::::::w       w:::::wo:::::::::::::::o "
	@echo "   P:::::::::::::PP   h:::::::hhh::::::h  i::::i  l::::l o:::::ooooo:::::o                        tttttt:::::::tttttt   w:::::w     w:::::::::w     w:::::w o:::::ooooo:::::o "
	@echo "   P::::PPPPPPPPP     h::::::h   h::::::h i::::i  l::::l o::::o     o::::o                              t:::::t          w:::::w   w:::::w:::::w   w:::::w  o::::o     o::::o "
	@echo "   P::::P             h:::::h     h:::::h i::::i  l::::l o::::o     o::::o                              t:::::t           w:::::w w:::::w w:::::w w:::::w   o::::o     o::::o "
	@echo "   P::::P             h:::::h     h:::::h i::::i  l::::l o::::o     o::::o                              t:::::t            w:::::w:::::w   w:::::w:::::w    o::::o     o::::o "
	@echo "   P::::P             h:::::h     h:::::h i::::i  l::::l o::::o     o::::o                              t:::::t    tttttt   w:::::::::w     w:::::::::w     o::::o     o::::o "
	@echo " PP::::::PP           h:::::h     h:::::hi::::::il::::::lo:::::ooooo:::::o                              t::::::tttt:::::t    w:::::::w       w:::::::w      o:::::ooooo:::::o "
	@echo " P::::::::P           h:::::h     h:::::hi::::::il::::::lo:::::::::::::::o                              tt::::::::::::::t     w:::::w         w:::::w       o:::::::::::::::o "
	@echo " P::::::::P           h:::::h     h:::::hi::::::il::::::l oo:::::::::::oo                                 tt:::::::::::tt      w:::w           w:::w         oo:::::::::::oo  "
	@echo " PPPPPPPPPP           hhhhhhh     hhhhhhhiiiiiiiillllllll   ooooooooooo                                     ttttttttttt         www             www            ooooooooooo    "
	@echo "                                                                          ________________________                                                                            "
	@echo "                                                                          _::::::::::::::::::::::_                                                                            "
	@echo "                                                                          ________________________                                                                            "
	@echo "                                                                                                                                                                              "                                                                       
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
