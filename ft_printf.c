/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:49:54 by robernar          #+#    #+#             */
/*   Updated: 2023/11/28 07:48:56 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static t_PrinterOption ft_get_treatment(char c)
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
		return (ft_treat_decimal_unsigned_int);
	return (NULL);
}

static void	ft_apply_treatment(char *str, va_list args, int *print_counter)
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
	
	if (!format)
		return (-1);
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
