# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azari <azari@student.1337.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 11:34:25 by azari             #+#    #+#              #
#    Updated: 2023/03/09 13:22:59 by azari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

NAME 	= so_long

CFILES	= so_long.c										\
		  imports/get_next_line/get_next_line.c			\
		  imports/get_next_line/get_next_line_utils.c	\
		  imports/ft_printf/ft_printf.c					\
		  imports/ft_printf/ft_printf_utils.c			\
		  src/errors/error_handling.c					\
		  src/map/map_processing/map_processing.c		\
		  src/map/map_processing/map_analyses.c			\
		  src/map/map_processing/map_analyses2.c		\
		  src/map/map_triggers/event_triggers.c			\
		  src/map/map_triggers/import_triggers.c		\
		  src/map/map_triggers/move_triggers.c			\
		  src/map/map_triggers/rendering_triggers.c		\
		  src/map/map_utils/map_controlers.c			\
		  src/map/map_utils/map_controlers2.c			\

OFILES	= $(CFILES:.c=.o)

all : $(NAME)

	
$(NAME) : $(OFILES)
	@$(CC) -lmlx -framework OpenGL -framework AppKit $(OFILES) -o $(NAME)
	@echo "\033[33;1m😎  done making\033[0m"
	@echo "\033[4;35m                                                            \n\
	███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗  		\n \
	██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝        \n \
	███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗       \n \
	╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║		\n \
	███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝		\n \
	╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ 		\n \
                                                                       	 		\033[0m"
	@echo "                                                      \033[97mBy: Anas Zari"
	
%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@
	
clean	:
	@rm -rf $(OFILES)
	@echo "\033[32m✅  object files removed successfully.\033[0m"

fclean	: clean
	@rm -rf $(NAME)
	@echo "\033[32m✅  object files and archive removed successfully.\033[0m"
	@echo "\033[33;1m😎  done cleaning\033[0m"

re		: fclean all
