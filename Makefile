# MACROS #

GCC		= gcc -Wall -Wextra -Werror
NAME	= rush-01
RM		= rm -rf

# PATHS AND LIB #
SRC_DIR	= sources/
INC		= -Iincludes

# SOURCE FILES #
S_SRCS	= $(SRC_DIR)*.c

# RECIPES #
all		:
	$(GCC) $(INC) $(S_SRCS) -o $(NAME)

clean	:
	$(RM) $(NAME)

re		: clean all

.PHONY	: all clean re