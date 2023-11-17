/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:49:54 by robernar          #+#    #+#             */
/*   Updated: 2023/11/17 11:27:22 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf.h"

void	ft_define_treatment(char *str, va_list args, int *print_counter)
{
	char	*special_chars;
	char	*special_char;

	special_chars = "cspdiuxX%";
	special_char = ft_memchr(special_chars, *str);
	if (*special_char == 'c')
		// tratamento para no do caso do digito ser c 
		// dai preciso de um tratamento para caracter
		ft_putchar_fd(va_arg(args, char), 1);
		*print_couter = *print_counter++;
}

int	ft_printf(const char *format,  ...)
{
	va_list	args;
	int	print_counter;
	char	*special_chars;
	char	*str;

	va_start(args, format);
	str = (char *)format;
	special_chars = "cspdiuxX%"; // caracteres que tem algum tipo de tratamento especial.
	while (*str)
		if (*str == '%')
			str++; // proximo caracter apos o %
				
		else
			ft_putchar_fd(*str++, 1);
			
			// preciso verificar se existe um dos caracteres que preciso tratar.

	va_end(args);
	return (print_counter);
}

#include <stdio.h>
int	main()
{
	printf("%d\n", ft_printf("rodrigo", 1, 2, 3));
	printf("%%");
	printf("%d - %d", 1, 2, 3, 4, 5);
}
