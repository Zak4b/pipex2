NAME = pipex
FLAGS = -Wall -Wextra -Werror -g

SOURCES = main.c utils.c 

OBJS = $(SOURCES:.c=.o)

$(NAME): $(OBJS)
	cc $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	cc $(FLAGS) $(INC) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all