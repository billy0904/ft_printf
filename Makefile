# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gablee <gablee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 20:45:17 by gablee            #+#    #+#              #
#    Updated: 2023/12/02 20:45:19 by gablee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = ./ft_printf.h
SRCS = ft_printf.c ft_printf_utils.c ft_printf_utils2.c

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $^ -I $(INC)

$(NAME) : $(OBJS)
	ar rcs $@ $^

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY = all clean fclean re
