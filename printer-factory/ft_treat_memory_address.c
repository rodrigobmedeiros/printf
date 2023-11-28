/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_memory_address.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:27:34 by robernar          #+#    #+#             */
/*   Updated: 2023/11/28 19:02:30 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printer_factory.h"

static int	ft_error_nil(void)
{
	ft_putstr_fd("(nil)", 1);
	return (5);
}

void	ft_treat_memory_address(va_list args, int *print_counter)
{
	unsigned long	hex_num;
	char			*str_num;
	char			*cpy_to_free;

	hex_num = va_arg(args, unsigned long);
	if (!hex_num)
	{
		*print_counter = *print_counter + ft_error_nil();
		return ;
	}
	str_num = ft_itoa_address(hex_num, 16, "0123456789abcdef");
	cpy_to_free = str_num;
	if (*str_num == '-')
		str_num++;
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str_num, 1);
	*print_counter = *print_counter + ft_strlen(str_num) + 2;
	free(cpy_to_free);
}
