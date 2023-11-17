/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:53:47 by robernar          #+#    #+#             */
/*   Updated: 2023/11/14 20:19:52 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*char_s;
	char	*last_occurence;

	char_s = (char *)s;
	last_occurence = (void *)0;
	if (c == '\0')
		return (char_s + ft_strlen(char_s));
	while (*char_s)
	{
		if (*char_s == c)
			last_occurence = char_s;
		char_s++;
	}
	return (last_occurence);
}
