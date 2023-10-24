# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pevangel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 17:24:01 by pevangel          #+#    #+#              #
#    Updated: 2023/10/24 17:30:10 by pevangel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

flags = -Wall -Wextra -Werror

NAME  = ft_printf.h

SRC = ft_printf.c\

OBJS = $(SRCS:.c=.0)

all: $(NAME)

$(NAME): $(OBJS)

clean = 
	rm - rf $(OBJS)
fclean = clean
	rm - rf $(NAME)
re: fclean all

