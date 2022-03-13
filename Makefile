# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 20:05:23 by fchrysta          #+#    #+#              #
#    Updated: 2022/03/13 19:30:43 by fchrysta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =		push_swap.c validate.c parser.c count_nbr.c ft_error.c \
				free_stack.c check_duplicates.c index_lists.c swap.c \
				push.c rotate.c rotate_rev.c is_sorted.c sort_stack.c \
				sort_3_el.c sort_5_el.c sort_max_el.c count_stack.c \
				find_min_max.c find_last.c sort_max_el_helpers.c

HEADER =		push_swap.h
CC =			gcc
NAME =			push_swap
OBJECTS	=		$(SOURCES:.c=.o)
FLAGS =			-Wall -Wextra -Werror

.PHONY: 		all re clean fclean

all	:			$(NAME)


$(NAME)	:		$(OBJECTS)
				$(CC) $(OBJECTS) -o $@

%.o : 			%.c $(HEADER)
				$(CC) $(FLAGS) $< -c

clean :
				rm -rf $(OBJECTS)

fclean :		clean
				rm -rf $(NAME)

re:				fclean all
