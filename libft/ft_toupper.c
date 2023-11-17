/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 07:00:54 by robernar          #+#    #+#             */
/*   Updated: 2023/11/14 20:20:51 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	is_lower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_toupper(int c)
{
	int	ascii_offset;

	ascii_offset = 32;
	return (c - is_lower(c) * ascii_offset);
}
