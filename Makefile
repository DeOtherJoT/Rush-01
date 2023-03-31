# MACROS #

GCC		= gcc -Wall -Wextra -Werror
FSAN	= -fsanitize=address -g
NAME	= rush-01
NAME_F	= rush-01.dSYM
RM		= rm -rf

# PATHS AND LIB #
SRC_DIR	= sources/
NSC_DIR = new_src/
INC		= -Iincludes

# SOURCE FILES #
S_SRCS	= $(SRC_DIR)*.c
N_SRCS	= $(NSC_DIR)*.c


# RECIPES #
all		:
	$(GCC) $(INC) $(S_SRCS) -o $(NAME)

fsan	:
	$(GCC) $(INC) $(S_SRCS) -o $(NAME) $(FSAN)

new		:
	$(GCC) $(INC) $(N_SRCS) -o $(NAME) $(FSAN)

clean	:
	$(RM) $(NAME) $(NAME_F)

re		: clean all

.PHONY	: all clean re