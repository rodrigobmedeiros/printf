NAME = libftprintf.a

SRCS = \
	ft_printf.c\

FLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

ITOA_VARIATIONS_PATH = ./itoa-variations
ITOA_VARIATIONS = $(ITOA_VARIATIONS_PATH)/itoavariations.a

PRINTER_FACTORY_PATH = ./printer-factory
PRINTER_FACTORY = $(PRINTER_FACTORY_PATH)/printerfactory.a

all: $(NAME)

$(NAME): $(LIBFT) $(ITOA_VARIATIONS) $(PRINTER_FACTORY) $(OBJS)
	cp $(PRINTER_FACTORY) $(NAME)
	cp $(ITOA_VARIATIONS) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(ITOA_VARIATIONS):
	make -C $(ITOA_VARIATIONS_PATH) all

$(PRINTER_FACTORY):
	make -C $(PRINTER_FACTORY_PATH) all

.c.o:
	cc $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean
	make -C $(ITOA_VARIATIONS_PATH) clean
	make -C $(PRINTER_FACTORY_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean
	make -C $(ITOA_VARIATIONS_PATH) clean
	make -C $(PRINTER_FACTORY_PATH) clean

re: clean fclean all
