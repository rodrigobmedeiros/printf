/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_variations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 00:19:24 by robernar          #+#    #+#             */
/*   Updated: 2023/11/28 19:06:37 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_itoa_variations.h"

char	*ft_itoa_base(long n, int base, char *digits)
{
	int		signal;
	int		i_num;
	char	*num;

	num = (char *)malloc(sizeof(char) * 24);
	if (!num)
		return (NULL);
	signal = 1;
	i_num = 0;
	if (n < 0)
		signal = ft_add_signal_if_negative(num, i_num++);
	while (n / base != 0)
	{
		num[i_num++] = char_from_int_base(signal * (n % base), digits);
		n = n / base;
	}
	num[i_num++] = char_from_int_base(signal * (n % base), digits);
	num[i_num] = '\0';
	ft_strrev(num);
	num = ft_realloc(num);
	if (!num)
		return (NULL);
	return (num);
}

char	*ft_itoa_address(unsigned long n, int base, char *digits)
{
	int		i_num;
	char	*num;

	num = (char *)malloc(sizeof(char) * 50);
	if (!num)
		return (NULL);
	i_num = 0;
	while (n / base != 0)
	{
		num[i_num++] = char_from_int_base((n % base), digits);
		n = n / base;
	}
	num[i_num++] = char_from_int_base((n % base), digits);
	num[i_num] = '\0';
	ft_strrev(num);
	num = ft_realloc(num);
	if (!num)
		return (NULL);
	return (num);
}

char	*ft_itoa_unsigned_decimal(unsigned int n, int base, char *digits)
{
	int		i_num;
	char	*num;

	num = (char *)malloc(sizeof(char) * 24);
	if (!num)
		return (NULL);
	i_num = 0;
	while (n / base != 0)
	{
		num[i_num++] = char_from_int_base((n % base), digits);
		n = n / base;
	}
	num[i_num++] = char_from_int_base((n % base), digits);
	num[i_num] = '\0';
	ft_strrev(num);
	num = ft_realloc(num);
	if (!num)
		return (NULL);
	return (num);
}
