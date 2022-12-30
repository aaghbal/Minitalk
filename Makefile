# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 18:36:17 by aaghbal           #+#    #+#              #
#    Updated: 2022/12/24 18:54:20 by aaghbal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror 
SRC = server.c client.c 
NAME = client
BON = server_bonus.c client_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_BON = $(BON:.c=.o)
RM = rm -f

all :$(NAME) server 

$(NAME) : client.o minitalk.h
	make -C ./Libft
	$(CC) $(FLAGS)	client.o ./Libft/libft.a -o client

server : server.o minitalk.h
	$(CC) $(FLAGS)	server.o ./Libft/libft.a -o server

bonus : server_bonus.o client_bonus.o minitalk.h
	$(CC) $(FLAGS)	server_bonus.o ./Libft/libft.a -o server_bonus
	$(CC) $(FLAGS)	client_bonus.o ./Libft/libft.a -o client_bonus

%.o : %.c $(BON) $(SRC)
	$(CC) $(FLAGS) -c $<

clean :
	$(RM) $(OBJ)
	$(RM) $(OBJ_BON)
	make clean -C ./Libft
 
fclean : clean
	$(RM) server client server_bonus client_bonus
	make fclean -C ./Libft

re : fclean all

.PHONY: all fclean clean re
