/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:49:54 by robernar          #+#    #+#             */
/*   Updated: 2023/11/17 15:37:58 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_treat_char(va_list args, int *print_counter)
{
	ft_putchar_fd(va_arg(args, int), 1);
	*print_counter = *print_counter + 1;
}

void	ft_treat_str(va_list args, int *print_counter)
{
	char	*str;

	str = va_arg(args, char *);
	ft_putstr_fd(str, 1);
	*print_counter = *print_counter + ft_strlen(str);
}

PrintOption ft_get_treatment(char c)
{
	if (c == 'c')
		return (ft_treat_char);
	if (c == 's')
		return (ft_treat_str);
	return (NULL);
}

void	ft_define_treatment(char *str, va_list args, int *print_counter)
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
			ft_define_treatment(str++, args, &print_counter);
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
}
