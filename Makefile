NAME = libftprintf.a

SRCS = \
	ft_printf.c

FLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

LIBFT_DIR = libft

all: $(NAME)

$(NAME): ${OBJS} libft/libft.a
	ar rc ${NAME} ${OBJS} ${LIBFT_DIR}/libft.a

libft/libft.a:
	make -C ${LIBFT_DIR}

.c.o:
	cc ${FLAGS} -c -o $@ $<

clean:
	rm -f ${OBJS}
	make -C ${LIBFT_DIR} clean

fclean:
	rm -f ${NAME}
	make -C ${LIBFT_DIR} fclean

re: clean fclean all
