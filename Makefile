#NAME#

NAME	= rush-01
C_NAME	= checker

#MACROS#

GCC		= gcc -Wall -Wextra -Werror
FSAN	= -fsanitize=address -g3
RM		= rm -rf

#PATHS#

INC_DIR	= includes
SRC_DIR	= srcs/

#SOURCE FILES#

SRCS	= $(addprefix $(SRC_DIR), ft_split.c input.c main.c solver.c utils_solver.c utils.c utils2.c)
C_SRCS	= $(addprefix $(SRC_DIR), ft_split.c input.c solver.c utils_solver.c utils.c utils2.c checker.c get_next_line.c gnl_utils.c gnl_utils2.c)

#RECIPES#

all		:	$(NAME) $(C_NAME)

$(NAME)	:
	$(GCC) $(SRCS) -o $(NAME)

$(C_NAME)	:
	$(GCC) $(C_SRCS) -o $(C_NAME)

fsan	:
	$(GCC) $(SRCS) -o $(NAME) $(FSAN)
	$(GCC) $(C_SRCS) -o $(C_NAME) $(FSAN)

clean	:
	$(RM) $(NAME) $(NAME).dSYM $(C_NAME) $(C_NAME).dSYM ans.txt

norm	:
	norminette $(SRC_DIR)

.PHONY	: all fsan clean norm