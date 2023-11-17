/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:51:09 by robernar          #+#    #+#             */
/*   Updated: 2023/11/14 20:05:45 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static int	ft_isminusplus(char c)
{
	return (c == '+' || c == '-');
}

static int	ft_isvalid(char c)
{
	return (ft_isspace(c) || ft_isminusplus(c) || ft_isdigit(c));
}

static int	ft_ctoi(char c)
{
	return (c - '0');
}

int	ft_atoi(const char *nptr)
{
	int	signal;
	int	num;

	signal = 1;
	num = 0;
	if (!ft_isvalid(*nptr))
		return (num);
	while (ft_isspace(*nptr))
	{
		nptr++;
	}
	if (!ft_isvalid(*nptr))
		return (num);
	if (ft_isminusplus(*nptr))
	{
		if (*nptr++ == '-')
			signal = -1 * signal;
	}
	if (!ft_isdigit(*nptr))
		return (num);
	while (ft_isdigit(*nptr) && *nptr)
	{
		num = num * 10 + signal * (ft_ctoi(*nptr++));
	}
	return (num);
}
