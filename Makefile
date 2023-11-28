NAME = libftprintf.a

ITOA_VARIATIONS_PATH = ./itoa-variations
PRINTER_FACTORY_PATH = ./printer-factory

SRCS = \
	ft_printf.c\
	$(ITOA_VARIATIONS_PATH)/ft_itoa_variations.c\
	$(PRINTER_FACTORY_PATH)/ft_treat_char.c\
	$(PRINTER_FACTORY_PATH)/ft_treat_str.c\
	$(PRINTER_FACTORY_PATH)/ft_treat_decimal_int.c\
	$(PRINTER_FACTORY_PATH)/ft_treat_decimal_unsigned_int.c\
	$(PRINTER_FACTORY_PATH)/ft_treat_hexadecimal_lower.c\
	$(PRINTER_FACTORY_PATH)/ft_treat_hexadecimal_upper.c\
	$(PRINTER_FACTORY_PATH)/ft_treat_percent.c\
	$(PRINTER_FACTORY_PATH)/ft_treat_memory_address.c\

FLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)	
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJS)

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
