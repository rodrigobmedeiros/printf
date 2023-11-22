/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 00:19:24 by robernar          #+#    #+#             */
/*   Updated: 2023/11/22 10:51:20 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_strrev(char *str)
{
	int	half;
	int	size;
	int	i;
	int	temp;

	i = 0;
	if (*str == '-')
		str++;
	size = ft_strlen(str);
	half = size / 2;
	while (i < half)
	{
		temp = str[i];
		str[i] = str[size - i -1];
		str[size - i - 1] = temp;
		i++;
	}
}

static char	char_from_int_base(int nbr, char *digits)
{
	return (digits[nbr]);
}

static int	ft_add_signal_if_negative(char *num, int index)
{
	num[index] = '-';
	return (-1);
}

static char	*ft_realloc(char *s)
{
	char	*re_s;

	re_s = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!re_s)
		return (NULL);
	ft_strlcpy(re_s, s, ft_strlen(s) + 1);
	free(s);
	return (re_s);
}

char	*ft_itoa_base(long int n, int base, char *digits)
{
	int		signal;
	int		i_num;
	char	*num;

	num = (char *)malloc(sizeof(char) * 12);
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
