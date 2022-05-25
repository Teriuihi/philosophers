NAME=philo
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f

FUNCTIONS=ft_atoi.c ft_calloc.c ft_isdigit.c ft_memcpy.c ft_memset.c \
philo_actions.c philo_eat.c util.c free_util.c util_2.c threads.c
LOAD=load_philos.c philo_data_init.c
LIST=add_philo.c last_philo.c new_philo.c
FILES=main.c \
$(addprefix functions/, ${FUNCTIONS}) \
$(addprefix philo_load/, ${LOAD}) \
$(addprefix philo_list/, ${LIST})
FILES_OBJ=$(FILES:%.c=%.o)
FILES_LIBS=$(LIB_FT:%.c:%.o)

all: $(NAME)

$(NAME): $(FILES_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(FILES_OBJ) $(LIBS)

clean:
	$(RM) $(FILES_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: make all clean fclean re
