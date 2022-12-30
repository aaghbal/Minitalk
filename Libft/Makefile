# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 12:46:13 by aaghbal           #+#    #+#              #
#    Updated: 2022/11/02 17:27:42 by aaghbal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror 
MAND_SRC = ft_bzero.c   ft_isascii.c ft_memcpy.c  ft_strchr.c  ft_strlen.c\
			ft_isalnum.c ft_isdigit.c ft_memmove.c ft_strlcat.c ft_tolower.c\
			ft_isalpha.c ft_isprint.c ft_memset.c  ft_strlcpy.c ft_toupper.c\
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			 ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_u.c \
			 fct.c fct2.c

BON = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
	  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJ = $(BON:.c=.o)
MAND_OBJ = $(MAND_SRC:.c=.o)
RM = rm -f
NAME  = libft.a
HEADER = libft.h


all : $(NAME)

$(NAME) : $(MAND_OBJ)
	@ar -rc $@ $(MAND_OBJ)

bonus : $(NAME) $(BONUS_OBJ)
	@ar -rc $(NAME) $(BONUS_OBJ)


%.o : %.c ${HEADER}
	@$(CC) $(FLAGS) -c $<

clean :
	@$(RM) $(MAND_OBJ) $(BONUS_OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all bonus

.PHONY: all fclean clean re
