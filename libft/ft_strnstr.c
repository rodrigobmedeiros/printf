/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 05:26:13 by robernar          #+#    #+#             */
/*   Updated: 2023/11/14 20:19:41 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)(big));
	if (len == 0)
		return (NULL);
	if (!*big)
		return (NULL);
	while (len > 0 && len-- >= little_len)
	{
		if (!ft_strncmp(big++, little, little_len))
			return ((char *)(big - 1));
	}
	return (NULL);
}
