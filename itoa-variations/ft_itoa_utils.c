/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:49:05 by robernar          #+#    #+#             */
/*   Updated: 2023/11/28 19:05:40 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_itoa_variations.h"

void	ft_strrev(char *str)
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

char	char_from_int_base(int nbr, char *digits)
{
	return (digits[nbr]);
}

int	ft_add_signal_if_negative(char *num, int index)
{
	num[index] = '-';
	return (-1);
}

char	*ft_realloc(char *s)
{
	char	*re_s;

	re_s = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!re_s)
		return (NULL);
	ft_strlcpy(re_s, s, ft_strlen(s) + 1);
	free(s);
	return (re_s);
}
