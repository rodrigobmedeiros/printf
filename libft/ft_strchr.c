/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:08:39 by robernar          #+#    #+#             */
/*   Updated: 2023/11/14 20:15:50 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*char_s;

	char_s = (char *)s;
	if (c == '\0')
		return (char_s + ft_strlen(char_s));
	while (*char_s)
	{
		if (*char_s == c)
			return (char_s);
		char_s++;
	}
	return (NULL);
}
