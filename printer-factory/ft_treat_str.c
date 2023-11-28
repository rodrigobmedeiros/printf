/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:17:17 by robernar          #+#    #+#             */
/*   Updated: 2023/11/28 19:03:00 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printer_factory.h"

static int	ft_error_null(void)
{
	ft_putstr_fd("(null)", 1);
	return (6);
}

void	ft_treat_str(va_list args, int *print_counter)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		*print_counter = *print_counter + ft_error_null();
		return ;
	}
	ft_putstr_fd(str, 1);
	*print_counter = *print_counter + ft_strlen(str);
	return ;
}
