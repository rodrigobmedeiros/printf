NAME = printerfactory.a

SRCS = \
	ft_treat_char.c\
	ft_treat_str.c\
	ft_treat_percent.c\
	ft_treat_decimal_int.c\
	ft_treat_decimal_unsigned_int.c\
	ft_treat_memory_address.c\
	ft_treat_hexadecimal_lower.c\
	ft_treat_hexadecimal_upper.c

FLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): ${OBJS}
	cp ../libft/libft.a $(NAME)
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
