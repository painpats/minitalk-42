# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbourre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 20:31:19 by cbourre           #+#    #+#              #
#    Updated: 2022/09/27 16:17:15 by cbourre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SRV =	server
SRCS_SRV =	server.c \
			server_binto.c
OBJ_SRV	 =	$(SRCS_SRV:.c=.o)

NAME_CLI =	client
SRCS_CLI = 	client.c
OBJ_CLI  =	$(SRCS_CLI:.c=.o)

NAME_SRV_BONUS =	server_bonus
SRCS_SRV_BONUS = 	server_bonus.c \
					server_binto_bonus.c
OBJ_SRV_BONUS = $(SRCS_SRV_BONUS:.c=.o)

NAME_CLI_BONUS = 	client_bonus
SRCS_CLI_BONUS = 	client_bonus.c \
					client_pid_bonus.c
OBJ_CLI_BONUS = $(SRCS_CLI_BONUS:.c=.o)

##### COMPIL #####

CC =		gcc

CFLAGS =	-g -O0 -Wall -Wextra -Werror

INCLUDE =	-Llibft -lft

RM =		rm -f

##### RULES #####

all: $(NAME_SRV) $(NAME_CLI)
	
.c.o:
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

$(NAME_SRV): $(OBJ_SRV)
	make -C libft
	$(CC) $(CFLAGS) $(OBJ_SRV) $(INCLUDE) -o $(NAME_SRV)

$(NAME_CLI): $(OBJ_CLI)
	make -C libft
	$(CC) $(CFLAGS) $(OBJ_CLI) $(INCLUDE) -o $(NAME_CLI)

##### BONUS #####

bonus: $(NAME_SRV_BONUS) $(NAME_CLI_BONUS)

$(NAME_SRV_BONUS): $(OBJ_SRV_BONUS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJ_SRV_BONUS) $(INCLUDE) -o $(NAME_SRV_BONUS)

$(NAME_CLI_BONUS): $(OBJ_CLI_BONUS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJ_CLI_BONUS) $(INCLUDE) -o $(NAME_CLI_BONUS)

#####

clean:
	$(RM) $(OBJ_CLI) $(OBJ_SRV) $(OBJ_CLI_BONUS) $(OBJ_SRV_BONUS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME_CLI) $(NAME_SRV) $(NAME_CLI_BONUS) $(NAME_SRV_BONUS)
	make -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re
