NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = main.c \
	   cmdds_exec.c\
	   search_for_path.c\
	   ft_split.c split_help.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

