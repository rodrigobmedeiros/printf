/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_decimal_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:20:30 by robernar          #+#    #+#             */
/*   Updated: 2023/11/28 19:01:23 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printer_factory.h"

void	ft_treat_decimal_int(va_list args, int *print_counter)
{
	int		int_num;
	char	*str_num;

	int_num = va_arg(args, int);
	str_num = ft_itoa(int_num);
	ft_putstr_fd(str_num, 1);
	*print_counter = *print_counter + ft_strlen(str_num);
	free(str_num);
}
