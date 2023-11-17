/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:35:35 by robernar          #+#    #+#             */
/*   Updated: 2023/11/14 20:13:56 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_strrev(char *str)
{
	int	half;
	int	size;
	int	i;
	int	temp;

	i = 0;
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

static char	char_from_int(int nbr)
{
	return (nbr + 48);
}

void	ft_putnbr_fd(int nbr, int fd)
{
	int		signal;
	int		i_num;
	char	reverse_num[12];

	signal = 1;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		signal = -1;
	}
	i_num = 0;
	while (nbr / 10 != 0)
	{
		reverse_num[i_num] = char_from_int(signal * (nbr % 10));
		nbr = nbr / 10;
		i_num++;
	}
	reverse_num[i_num++] = char_from_int(signal * (nbr % 10));
	reverse_num[i_num] = '\0';
	ft_strrev(reverse_num);
	ft_putstr_fd(reverse_num, fd);
}
