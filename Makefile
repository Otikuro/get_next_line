COMPILER = cc
FLAGS = -Wall -Werror -Wextra
NAME = gnl.a
FILES = src/get_next_line.c \
		src/get_next_line_utils.c \

OBJS = $(FILES:.c=.o)
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
