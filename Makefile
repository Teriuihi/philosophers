NAME=philo
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f

LIBS=not_libft/not_libft.a

FILES=functions/util.c load_philosophers/load_philos.c main.c
FILES_OBJ=$(FILES:%.c=%.o)
FILES_LIBS=$(LIB_FT:%.c:%.o)

all: $(NAME)

$(NAME): $(FILES_OBJ)
	$(MAKE) -C not_libft/
	$(CC) $(CFLAGS) -o $(NAME) $(FILES_OBJ) $(LIBS)

clean:
	$(RM) $(FILES_OBJ)
	$(MAKE) -C not_libft/ clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C not_libft/ fclean

re: fclean $(NAME)

.PHONY: make all clean fclean re
