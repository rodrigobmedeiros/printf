/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 07:34:48 by robernar          #+#    #+#             */
/*   Updated: 2023/11/14 20:18:54 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s_m;

	s_m = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s_m)
		return ((void *)0);
	i = 0;
	while (s[i])
	{
		s_m[i] = f(i, s[i]);
		i++;
	}
	s_m[i] = '\0';
	return (s_m);
}
