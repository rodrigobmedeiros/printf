NAME = libftprintf.a

SRCS = \
	ft_printf.c

FLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.c}

all: $(NAME)

$(NAME): ${OBJS}
	ar rc ${NAME} ${OBJS}

.c.o:
	cc ${FLAGS} -c -o $@ $<

clean:
	rm -f ${OBJS}

fclean:
	rn -f ${NAME}

re: clean fclean all
