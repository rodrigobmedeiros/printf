/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:49:54 by robernar          #+#    #+#             */
/*   Updated: 2023/11/22 00:17:20 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_str_to_upper(char *s)
{
	while (*s)
	{
		*s = ft_toupper(*s);
		s++;
	}
	return ;
}

static void	ft_strrev(char *str)
{
	int	half;
	int	size;
	int	i;
	int	temp;

	i = 0;
	if (*str == '-')
		str++;
	size = ft_strlen(str);
	half = size / 2;
	while (i < half)
	{
		temp = str[i];
		str[i] = str[size - i -1];
		str[size - i - 1] = temp;
		i++;
	}
}

static char	char_from_int_base(int nbr, char *digits)
{
	return (digits[nbr]);
}

static int	ft_add_signal_if_negative(char *num, int index)
{
	num[index] = '-';
	return (-1);
}

static char	*ft_realloc(char *s)
{
	char	*re_s;

	re_s = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!re_s)
		return (NULL);
	ft_strlcpy(re_s, s, ft_strlen(s) + 1);
	free(s);
	return (re_s);
}

static char	*ft_itoa_base(long int n, int base, char *digits)
{
	int		signal;
	int		i_num;
	char	*num;

	num = (char *)malloc(sizeof(char) * 12);
	if (!num)
		return (NULL);
	signal = 1;
	i_num = 0;
	if (n < 0)
		signal = ft_add_signal_if_negative(num, i_num++);
	while (n / base != 0)
	{
		num[i_num++] = char_from_int_base(signal * (n % base), digits);
		n = n / base;
	}
	num[i_num++] = char_from_int_base(signal * (n % base), digits);
	num[i_num] = '\0';
	ft_strrev(num);
	num = ft_realloc(num);
	if (!num)
		return (NULL);
	return (num);
}

static void	ft_treat_char(va_list args, int *print_counter)
{
	ft_putchar_fd(va_arg(args, int), 1);
	*print_counter = *print_counter + 1;
}

static void	ft_treat_str(va_list args, int *print_counter)
{
	char	*str;

	str = va_arg(args, char *);
	ft_putstr_fd(str, 1);
	*print_counter = *print_counter + ft_strlen(str);
}

static void	ft_treat_percent(va_list args, int *print_counter)
{
	(void) args;	
	ft_putchar_fd('%', 1);
	*print_counter = *print_counter + 1;
}

void	ft_treat_decimal_int(va_list args, int *print_counter)
{
	int	int_num;
	char	*str_num;
	
	int_num = va_arg(args, int);
	str_num = ft_itoa(int_num);
	ft_putstr_fd(str_num, 1);
	*print_counter = *print_counter + ft_strlen(str_num);
	free(str_num);
}

void	ft_treat_memory_address(va_list args, int *print_counter)
{
	long int	hex_num;
	char	*str_num;

	hex_num = va_arg(args, long int);
	str_num = ft_itoa_base(hex_num, 16, "0123456789abcdef");
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str_num, 1);
	*print_counter = *print_counter + ft_strlen(str_num) + 2;
	free(str_num);
}

void	ft_treat_hexadecimal_lower(va_list args, int *print_counter)
{
	long int    hex_num;
	char    *str_num;

	hex_num = va_arg(args, long int);
	str_num = ft_itoa_base(hex_num, 16, "0123456789abcdef");
	ft_putstr_fd(str_num, 1);
	*print_counter = *print_counter + ft_strlen(str_num);
	free(str_num);
}

void    ft_treat_hexadecimal_upper(va_list args, int *print_counter)
{
	long int    hex_num;
	char    *str_num;

	hex_num = va_arg(args, long int);
	str_num = ft_itoa_base(hex_num, 16, "0123456789abcdef");
	ft_str_to_upper(str_num);
	ft_putstr_fd(str_num, 1);
	*print_counter = *print_counter + ft_strlen(str_num);
	free(str_num); 
}

PrintOption ft_get_treatment(char c)
{
	if (c == 'c')
		return (ft_treat_char);
	if (c == 's')
		return (ft_treat_str);
	if (c == '%')
		return (ft_treat_percent);
	if (c == 'd')
		return (ft_treat_decimal_int);
	if (c == 'p')
		return (ft_treat_memory_address);
	if (c == 'x')
		return (ft_treat_hexadecimal_lower);
	if (c == 'X')
		return (ft_treat_hexadecimal_upper);
	if (c == 'i')
		return (ft_treat_decimal_int);
	if (c == 'u')
		return (ft_treat_decimal_int);
	return (NULL);
}

void	ft_apply_treatment(char *str, va_list args, int *print_counter)
{
	char	*special_chars;
	char	*special_char;
	
	special_chars = "cspdiuxX%";
	special_char = ft_memchr(special_chars, *str, ft_strlen(special_chars));
	ft_get_treatment(*special_char)(args, print_counter);
}

int	ft_printf(const char *format,  ...)
{
	va_list	args;
	int	print_counter;
	char	*str;

	va_start(args, format);
	str = (char *)format;
	print_counter = 0;
	while (*str)
		if (*str == '%')
		{
			str++;
			ft_apply_treatment(str++, args, &print_counter);
		}
		else
		{
			ft_putchar_fd(*str++, 1);
			print_counter++;
		}
	va_end(args);
	return (print_counter);
}

#include <stdio.h>
int	main()
{
	// Teste para multiplos caracteres
	printf("number of printed chars - system: %d\n", printf("rodrigo%c - %c\n", 'A', 'B'));
	printf("number of printed chars - custom: %d\n", ft_printf("rodrigo%c - %c\n", 'A', 'B'));

	// Teste para uma string
	printf("number of printed chars - system: %d\n", printf("rodrigo - %s\n", "RODRIGO"));
	printf("number of printed chars - custom: %d\n", ft_printf("rodrigo - %s\n", "RODRIGO"));

 	// Teste para multiplas string
 	printf("number of printed chars - system: %d\n", printf("rodrigo - %s %s\n", "RODRIGO", "BERNARDO"));
 	printf("number of printed chars - custom: %d\n", ft_printf("rodrigo - %s %s\n", "RODRIGO", "BERNARDO"));

	// Teste para imprimir percentual
 	printf("number of printed chars - system: %d\n", printf("rodrigo - %%\n"));
 	printf("number of printed chars - custom: %d\n", ft_printf("rodrigo - %%\n"));

	// Teste para imprimir inteiros com %d
	printf("number of printed chars - system: %d\n", printf("rodrigo - %d\n", 11));
	printf("number of printed chars - custom: %d\n", ft_printf("rodrigo - %d\n", 11));

	// Teste para imprimir multiplos inteiros com %d
	printf("number of printed chars - system: %d\n", printf("rodrigo - %d %d\n", 11, 123));
	printf("number of printed chars - custom: %d\n", ft_printf("rodrigo - %d %d\n", 11, 123));

	int num = 10;
	// Teste para imprimir endereco na memoria
	printf("number of printed chars - system: %d\n", printf("address: %p\n", &num));
	printf("number of printed chars - custom: %d\n", ft_printf("address: %p\n", &num));

	num = 0xabcdef;
	// Teste para imprimir hexadecimal lower case
	printf("number of printed chars - system: %d\n", printf("address: %x\n", num));
	printf("number of printed chars - custom: %d\n", ft_printf("address: %x\n", num));

	// Teste para imprimir hexadecimal upper case
	printf("number of printed chars - system: %d\n", printf("address: %X\n", num));
	printf("number of printed chars - custom: %d\n", ft_printf("address: %X\n", num));

        // Teste para imprimir inteiros com %i
        printf("number of printed chars - system: %d\n", printf("rodrigo - %i\n", 11));
        printf("number of printed chars - custom: %d\n", ft_printf("rodrigo - %i\n", 11));

        // Teste para imprimir multiplos inteiros com %i
        printf("number of printed chars - system: %d\n", printf("rodrigo - %i %i\n", 11, 123));
        printf("number of printed chars - custom: %d\n", ft_printf("rodrigo - %i %i\n", 11, 123));

        // Teste para imprimir inteiros com %u
        printf("number of printed chars - system: %d\n", printf("rodrigo - %u\n", 11));
        printf("number of printed chars - custom: %d\n", ft_printf("rodrigo - %u\n", 11));

        // Teste para imprimir multiplos inteiros com %i
        printf("number of printed chars - system: %d\n", printf("rodrigo - %u %u\n", 11, 123));
        printf("number of printed chars - custom: %d\n", ft_printf("rodrigo - %u %u\n", 11, 123));
}
