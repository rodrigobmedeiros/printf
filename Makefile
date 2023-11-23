NAME = libftprintf.a

SRCS = \
	ft_printf.c\
	ft_itoa_base.c

FLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH) all

.c.o:
	cc $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: clean fclean all
