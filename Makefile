# MACROS #

GCC		= gcc -Wall -Wextra -Werror
FSAN	= -fsanitize=address -g
NAME	= rush-01
NAME_F	= rush-01.dSYM
RM		= rm -rf

# PATHS AND LIB #
SRC_DIR	= sources/
INC		= -Iincludes

# SOURCE FILES #
S_SRCS	= $(SRC_DIR)*.c

# RECIPES #
all		:
	$(GCC) $(INC) $(S_SRCS) -o $(NAME)

fsan	:
	$(GCC) $(INC) $(S_SRCS) -o $(NAME) $(FSAN)

clean	:
	$(RM) $(NAME) $(NAME_F)

re		: clean all

.PHONY	: all clean re