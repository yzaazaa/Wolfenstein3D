# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 02:42:24 by yzaazaa           #+#    #+#              #
#    Updated: 2023/12/24 10:17:46 by yzaazaa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

HEADER = get_next_line.h

CFLAGS = -Wall -Wextra -Werror

CC = cc

all : $(NAME)

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJS)
	@echo "Creating gnl.a ..."
	@ar rc $(NAME) $(OBJS)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : clean