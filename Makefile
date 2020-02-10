# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkuksa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 12:49:43 by bkuksa            #+#    #+#              #
#    Updated: 2019/04/02 12:50:21 by bkuksa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bkuksa.filler

SRCS := srcs/main.c
SRCS += srcs/size_save.c
SRCS += srcs/place.c
SRCS += srcs/first_folow.c
SRCS += srcs/right_side.c
SRCS += srcs/help_all.c
SRCS += srcs/op_alg.c
SRCS += srcs/cut.c


FLAGS = -Wall -Werror -Wextra -I./includes

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

run:
	./resources/filler_vm -f resources/maps/map00 -p1 ./bkuksa.filler -p2 ./resources/players/abanlin.filler || true
	rm -f ./bkuksa.filler

.PHONY: all clean fclean re run
