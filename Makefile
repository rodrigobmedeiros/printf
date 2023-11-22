NAME = libftprintf.a

SRCS = \
	ft_printf.c\
	ft_itoa_base.c

FLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

LIBFT_DIR = libft

all: $(NAME)

$(NAME): ${OBJS} | gen-libft
	ar rc ${NAME} ${LIBFT_DIR}/libft.a ${OBJS}

gen-libft:
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
