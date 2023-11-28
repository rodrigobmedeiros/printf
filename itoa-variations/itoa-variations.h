/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa-variations.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:23:32 by robernar          #+#    #+#             */
/*   Updated: 2023/11/27 22:17:17 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ITOA_VARIATIONS_H
# define ITOA_VARIATIONS_H
# include <stdarg.h>
# include "../libft/libft.h"

char	*ft_itoa_base(long n, int base, char *digits);
char	*ft_itoa_address(unsigned long n, int base, char *digits);
char	*ft_itoa_unsigned_decimal(unsigned int n, int base, char *digits);
#endif
