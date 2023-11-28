/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hexadecimal_upper.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:10:52 by robernar          #+#    #+#             */
/*   Updated: 2023/11/26 19:47:22 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printer_factory.h"

static void	ft_str_to_upper(char *s)
{
	while (*s)
	{
		*s = ft_toupper(*s);
		s++;
	}
	return ;
}

void	ft_treat_hexadecimal_upper(va_list args, int *print_counter)
{
	long int	hex_num;
	char		*str_num;

	hex_num = va_arg(args, unsigned int);
	str_num = ft_itoa_address(hex_num, 16, "0123456789abcdef");
	ft_str_to_upper(str_num);
	ft_putstr_fd(str_num, 1);
	*print_counter = *print_counter + ft_strlen(str_num);
	free(str_num);
}
