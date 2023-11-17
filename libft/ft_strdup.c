/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:50:32 by robernar          #+#    #+#             */
/*   Updated: 2023/11/14 20:16:26 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	size_t	t_len;
	char	*new_s;	

	s_len = ft_strlen(s);
	t_len = s_len + 1;
	new_s = (char *)malloc((t_len) * sizeof(char));
	if (!new_s)
		return ((void *)0);
	ft_strlcpy(new_s, s, t_len);
	return (new_s);
}
