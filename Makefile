# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 23:28:03 by yer-retb          #+#    #+#              #
#    Updated: 2022/06/06 06:20:07 by yer-retb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAG = -Wall -Wextra -Werror

SRCS = push_swap.c check_error.c ft_moves.c ft_more_move.c sort.c ft_id.c big_sort.c

OBJ = $(SRCS:.c=.o)

NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAG) $(SRCS) -o $(NAME)

clean :
	@rm -rf $(OBJ) 

fclean : clean
	@rm -rf	$(NAME)

re : clean all