/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:14:08 by robernar          #+#    #+#             */
/*   Updated: 2023/11/28 07:48:29 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printer_factory.h"

void	ft_treat_char(va_list args, int *print_counter)
{
	ft_putchar_fd(va_arg(args, int), 1);
	*print_counter = *print_counter + 1;
}
