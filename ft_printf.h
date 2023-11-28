/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:23:32 by robernar          #+#    #+#             */
/*   Updated: 2023/11/27 22:24:14 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# include "printer-factory/printer-factory.h"

typedef void	(*t_PrintOption)(va_list, int *);
char	*ft_itoa_base(long n, int base, char *digits);
char	*ft_itoa_address(unsigned long n, int base, char *digits);
char	*ft_itoa_unsigned_decimal(unsigned int n, int base, char *digits);
int		ft_printf(const char *format, ...);
#endif
