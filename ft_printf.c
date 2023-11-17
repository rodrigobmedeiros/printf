/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:49:54 by robernar          #+#    #+#             */
/*   Updated: 2023/11/17 12:51:20 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf.h"

void	ft_define_treatment(char *str, va_list args, int *print_counter)
{
	char	*special_chars;
	char	*special_char;
	
	special_chars = "cspdiuxX%";
	special_char = ft_memchr(special_chars, *str, ft_strlen(special_chars));
	if (*special_char == 'c')
	{
		// tratamento para no do caso do digito ser c 
		// dai preciso de um tratamento para caracter
		ft_putchar_fd(va_arg(args, int), 1);
		*print_counter = *print_counter  + 1;
	}
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
			str++; // proximo caracter apos o %
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
	printf("number of printed chars - system: %d\n", printf("rodrigo%c\n", 'A'));
	printf("number of printed chars - custom: %d\n", ft_printf("rodrigo%c\n", 'A'));
}
