# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/21 13:03:39 by jcharloi          #+#    #+#              #
#    Updated: 2017/08/24 17:55:35 by jcharloi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME1 = checker
NAME2 = push_swap

SRC_PATH = ./sources/
SRC_NAME = start.c check_errors.c change_tab.c movements.c movements_pa_pb.c push_swap.c selection_sort_improved.c tools.c min_max.c value.c
OBJ_PATH = ./objects/
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_PATH = ./sources/libft/
LIB_NAME = ./sources/libft/libft.a
PRINT_NAME = ./sources/libft/ft_printf/libftprintf.a

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

YELLOW = "\033[38;5;228m"
ORANGE = "\033[38;5;214m"
PINK = "\033[38;5;213m"
PURPLE = "\033[38;5;105m"
BLUE = "\033[38;5;33m"
GREEN = "\033[33;32m"
EOC = "\033[0m"

all: creation
	@make $(NAME1)
	@make $(NAME2)

creation:
	@make -C $(LIB_PATH)
	@echo $(ORANGE)"Your $(LIB_NAME) is (al)ready (ready) to work !"$(EOC)
	@echo $(ORANGE)"Your $(PRINT_NAME) is (al)ready (ready) to work !"$(EOC)
	@echo $(ORANGE)"Your $(BONUS_PATH)interface is (al)ready (ready) to work !"$(EOC)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@echo $(BLUE)"Your $(OBJ_PATH) folder is (al)ready (ready) to work !"$(EOC)

$(NAME1): $(OBJ)
	@$(CC) -o $(NAME1) $(OBJ) $(LIB_NAME) $(PRINT_NAME) $(CFLAGS)
	@echo $(GREEN)"Done, you can now check with Checker .."$(EOC)

$(NAME2): $(OBJ)
	@$(CC) -o $(NAME2) $(OBJ) $(LIB_NAME) $(PRINT_NAME) $(CFLAGS)
	@echo $(GREEN)".. And push with Push_Swap, GLHF ! ✅"$(EOC)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo $(PURPLE)"Your ./$@. file is ready to work !"$(EOC)

clean:
	@make clean -C $(LIB_PATH)
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo $(YELLOW)"Cleaned !"$(EOC)

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME1)
	@rm -f $(NAME2)
	@echo $(PINK)"Fcleaned ! Compile me again !"$(EOC)

re: fclean all

.PHONY : all creation clean fclean re
