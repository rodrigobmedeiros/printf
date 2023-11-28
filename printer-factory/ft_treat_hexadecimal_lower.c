/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hexadecimal_lower.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:30:31 by robernar          #+#    #+#             */
/*   Updated: 2023/11/26 19:47:11 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printer-factory.h"

void	ft_treat_hexadecimal_lower(va_list args, int *print_counter)
{
	unsigned int	hex_num;
	char	*str_num;

	hex_num = va_arg(args, unsigned int);
	str_num = ft_itoa_address(hex_num, 16, "0123456789abcdef");
	ft_putstr_fd(str_num, 1);
	*print_counter = *print_counter + ft_strlen(str_num);
	free(str_num);
}
