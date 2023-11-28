/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer-factory.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:23:32 by robernar          #+#    #+#             */
/*   Updated: 2023/11/28 08:09:33 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PRINTER_FACTORY_H
# define PRINTER_FACTORY_H
# include <stdarg.h>
# include "../itoa-variations/itoa-variations.h"

typedef void	(*t_PrinterOption)(va_list, int *);
void	ft_treat_char(va_list args, int *print_counter);
void	ft_treat_str(va_list args, int *print_counter);
void	ft_treat_decimal_int(va_list args, int *print_counter);
void	ft_treat_decimal_unsigned_int(va_list args, int *print_counter);
void	ft_treat_hexadecimal_lower(va_list args, int *print_counter);
void	ft_treat_hexadecimal_upper(va_list args, int *print_counter);
void	ft_treat_percent(va_list args, int *print_counter);
void	ft_treat_memory_address(va_list args, int *print_counter);
#endif
