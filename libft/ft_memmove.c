/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 05:06:36 by robernar          #+#    #+#             */
/*   Updated: 2023/11/14 20:12:39 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_cpy_char_down(char *d, char *s, size_t i)
{
	d[i] = s[i];
	return (--i);
}

static int	ft_cpy_char_up(char *d, char *s, size_t i)
{
	d[i] = s[i];
	return (++i);
}

static void	ft_segfault_when_needed(char *d, char *s)
{
	if (!d && !s)
		return ;
	if (!d)
		d[0] = s[0];
	if (!s)
		d[0] = s[0];
}

void	*ft_memmove(void *dest, void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	d = dest;
	s = src;
	if ((!d && !s) || n == 0)
		return (dest);
	ft_segfault_when_needed(d, s);
	if (s < d)
	{
		i = n - 1;
		while (i > 0)
			i = ft_cpy_char_down(d, s, i);
		d[i] = s[i];
	}
	else
	{
		while (i < n)
		{
			i = ft_cpy_char_up(d, s, i);
		}
	}
	return (dest);
}
