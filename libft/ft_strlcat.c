/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:21:05 by robernar          #+#    #+#             */
/*   Updated: 2023/11/14 20:17:48 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_length;
	size_t	length_to_add;
	size_t	total_size;

	dst_length = ft_strlen(dst);
	length_to_add = ft_strlen(src);
	total_size = dst_length + length_to_add;
	if (dst_length >= size)
		return (length_to_add + size);
	dst += dst_length;
	size -= dst_length;
	if (length_to_add >= size)
		length_to_add = size - 1;
	ft_memcpy(dst, (void *)src, length_to_add);
	dst[length_to_add] = '\0';
	return (total_size);
}
