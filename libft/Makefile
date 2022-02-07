NAME=libft.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
FILES=ft_calloc.c ft_atoi.c ft_isdigit.c ft_memset.c ft_memcpy.c \
ft_putstr_fd.c ft_strlen.c ft_split.c
FILES_OBJ=$(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(FILES_OBJ)
	ar -rcs $(NAME) $(FILES_OBJ)

clean:
	$(RM) $(FILES_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: make all clean fclean re
