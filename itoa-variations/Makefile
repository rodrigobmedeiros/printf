NAME = itoavariations.a

SRCS = \
	ft_itoa_variations.c\

FLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): ${OBJS}
	ar rc ${NAME} ${OBJS}

%.o: %.c
	cc ${FLAGS} -c -o $@ $<

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: clean fclean all

so:
	cc -nostartfiles -fPIC $(FLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)
