/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:49:54 by robernar          #+#    #+#             */
/*   Updated: 2023/11/16 18:38:48 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printf(const char *format,  ...)
{
	va_list	args;
	char	*special_chars;
	char	*str;
	int	len;

	va_start(args, format);
	str = (char *)format;
	len = ft_strlen(str);
	special_chars = "cspdiuxX%"; // caracteres que tem algum tipo de tratamento especial.
	while (*str || len == 0)
		if (*str == '%')
			str++;
		else
			ft_putchar_fd(*str++, 1);
			
			// preciso verificar se existe um dos caracteres que preciso tratar.

	va_end(args);
	return (1);
}

#include <stdio.h>
int	main()
{
	printf("%d\n", ft_printf("rodrigo", 1, 2, 3));
	printf("%%");
	printf("%d - %d", 1, 2, 3, 4, 5);
}
