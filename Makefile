#NAME#

NAME	= rush-01

#MACROS#

GCC		= gcc -Wall -Wextra -Werror
FSAN	= -fsanitizer=address -g3
RM		= rm -rf

#PATHS#

INC_DIR	= includes
SRC_DIR	= srcs/

#SOURCE FILES#

SRCS	= $(addprefix $(SRC_DIR), ft_split.c input.c main.c solver.c utils_solver.c utils.c utils2.c)

#RECIPES#

all		:	$(NAME)

$(NAME)	:
	$(GCC) $(SRCS) -o $(NAME)

fsan	:
	$(GCC) $(SRCS) -o $(NAME) $(FSAN)

clean	:
	$(RM) $(NAME) $(NAME).dSYM

norm	:
	norminette $(SRC_DIR)

.PHONY	: all fsan clean norm