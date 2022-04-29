NAME=libft.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
FILES=ft_atoi.c ft_calloc.c ft_isdigit.c ft_memcpy.c \
ft_memset.c ft_printf/ft_printf.c ft_printf/hex.c \
ft_printf/hex_util.c ft_printf/printing.c ft_putnbr_fd.c \
ft_putstr_fd.c ft_split.c ft_strlen.c ft_itoa.c
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
