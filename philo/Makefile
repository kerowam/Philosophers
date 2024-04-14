# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 13:55:28 by gfredes-          #+#    #+#              #
#    Updated: 2024/03/25 13:55:28 by gfredes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror

CLEAN = rm -f

SRC = main.c\
	check_args.c\
	utils.c\
	init.c\
	threads.c\
	actions.c\
	threads_utils.c\

OBJT = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJT)
	gcc -g -fsanitize=thread $(CFLAGS) $(SRC) -o $(NAME) -lpthread 

clean:
	$(CLEAN) $(OBJT)

fclean: clean
	$(CLEAN) $(NAME)

re: fclean all

.PHONY: all clean fclean re