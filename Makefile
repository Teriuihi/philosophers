NAME=push_swap
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f

MAIN=push_swap.c
FUNCTIONS=
LIBS=libft/libft.a
LIB_FT=ft_calloc.c ft_atoi.c ft_isdigit.c ft_memset.c ft_memcpy.c \
ft_putstr_fd.c ft_strlen.c

FILES=$(addprefix functions/, $(FUNCTIONS)) $(MAIN)
FILES_OBJ=$(FILES:%.c=%.o)
FILES_LIBS=$(LIB_FT:%.c:%.o)

all: $(NAME)

$(NAME): $(FILES_OBJ)
	$(MAKE) -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(FILES_OBJ) $(LIBS)

clean:
	$(RM) $(FILES_OBJ)
	$(MAKE) -C libft/ clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft/ fclean

re: fclean $(NAME)

.PHONY: make all clean fclean re
