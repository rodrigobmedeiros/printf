/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 07:54:30 by robernar          #+#    #+#             */
/*   Updated: 2023/11/14 20:08:47 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocated;
	int		total_size;

	total_size = (int)nmemb * (int)size;
	if (total_size / size != nmemb)
		return (NULL);
	allocated = (void *)malloc(total_size);
	if (!allocated)
		return (NULL);
	return (ft_memset(allocated, '\0', total_size));
}
