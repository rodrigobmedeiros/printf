/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_variations.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:23:32 by robernar          #+#    #+#             */
/*   Updated: 2023/11/28 18:52:44 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_ITOA_VARIATIONS_H
# define FT_ITOA_VARIATIONS_H
# include <stdarg.h>
# include "../libft/libft.h"

void	ft_strrev(char *str);
char	char_from_int_base(int nbr, char *digits);
int		ft_add_signal_if_negative(char *num, int index);
char	*ft_realloc(char *s);
char	*ft_itoa_base(long n, int base, char *digits);
char	*ft_itoa_address(unsigned long n, int base, char *digits);
char	*ft_itoa_unsigned_decimal(unsigned int n, int base, char *digits);
#endif
