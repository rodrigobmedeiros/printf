/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 07:24:51 by robernar          #+#    #+#             */
/*   Updated: 2023/11/14 20:20:44 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	is_upper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_tolower(int c)
{
	int	ascii_offset;

	ascii_offset = 32;
	return (c + is_upper(c) * ascii_offset);
}
