/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:19:21 by robernar          #+#    #+#             */
/*   Updated: 2023/11/26 19:47:37 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printer_factory.h"

void	ft_treat_percent(va_list args, int *print_counter)
{
	(void) args;
	ft_putchar_fd('%', 1);
	*print_counter = *print_counter + 1;
}
