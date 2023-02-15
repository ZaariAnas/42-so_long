# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azari <azari@student.1337.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 11:34:25 by azari             #+#    #+#              #
#    Updated: 2023/02/15 10:22:51 by azari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

NAME 	= so_long

CFILES	= so_long.c								\
		  src/ErrorHandling.c					\
		  get_next_line/get_next_line.c			\
		  get_next_line/get_next_line_utils.c	\
		  src/EventHandling/WindowHooks.c		\

OFILES	= $(CFILES:.c=.o)

all : $(NAME)

	
$(NAME) : $(OFILES)
	@$(CC) -lmlx -framework OpenGL -framework AppKit $(OFILES) -o $(NAME)
	@echo "\033[33;1m✔  done making\033[0m"
	@echo "\033[4;35m                                                            \n\
	  ▄████████  ▄██████▄          ▄█          ▄██████▄  ███▄▄▄▄      ▄██████▄      \n\
	 ███    ███ ███    ███        ███         ███    ███ ███▀▀▀██▄   ███    ███     \n\
	 ███    █▀  ███    ███        ███         ███    ███ ███   ███   ███    █▀      \n\
	 ███        ███    ███        ███         ███    ███ ███   ███  ▄███            \n\
	███████████ ███    ███        ███         ███    ███ ███   ███ ▀▀███ ████▄      \n\
	        ███ ███    ███        ███         ███    ███ ███   ███   ███    ███     \n\
	  ▄█    ███ ███    ███        ███▌     ▄  ███    ███ ███   ███   ███    ███     \n\
	▄████████▀   ▀██████▀  █████  ███████▄▄██  ▀██████▀   ▀█   █▀    ████████▀      \n\
                                                                       	 		\033[0m"
	@echo "                                                      \033[44mBy: Anas Zari"
	
%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@
	
clean	:
	@rm -rf $(OFILES)
	@echo "\033[32m✔  object files removed successfully.\033[0m"

fclean	: clean
	@rm -rf $(NAME)
	@echo "\033[32m✔  object files and archive removed successfully.\033[0m"

re		: fclean all
	