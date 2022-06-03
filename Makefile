# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 23:28:03 by yer-retb          #+#    #+#              #
#    Updated: 2022/06/03 05:33:41 by yer-retb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAG = 
SRCS = push_swap.c check_error.c ft_moves.c ft_more_move.c sort.c ft_id.c big_sort.c

obj = $(SRCS:.c=.o)

all : $(obj)

$(obj) : $(SRCS)
	@$(CC) $(CFLAG) $(SRCS) -o push_swap -fsanitize=address -g

clean :
	@rm -rf *.o 
fclean : clean
	@rm -rf	$(obj)
re : fclean all
