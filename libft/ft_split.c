/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 07:13:39 by robernar          #+#    #+#             */
/*   Updated: 2023/11/14 20:26:26 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	counter;

	counter = 0;
	if (!*s)
		return (counter);
	while (*s)
	{
		if (*s == c)
		{
			counter++;
			while (*s == c)
				s++;
		}
		else
			s++;
	}
	if (*--s != c)
		counter++;
	return (counter);
}

static char	*ft_move_pointer_to_next_non_delimiter(char const *s, char c)
{
	char	*cpy_s;

	cpy_s = (char *)s;
	while (*cpy_s == c && (size_t)(cpy_s - s) < ft_strlen(s))
		cpy_s++;
	return (cpy_s);
}

static char	*ft_add_delimiter_to_end(char const *s, char c)
{
	char	*cpy_s;
	int		len;

	len = ft_strlen(s);
	cpy_s = (char *)malloc(sizeof(char) * (len + 2));
	if (!cpy_s)
		return (NULL);
	ft_strlcpy(cpy_s, s, len + 1);
	cpy_s[len] = c;
	cpy_s[len + 1] = '\0';
	return (cpy_s);
}

static char	*ft_allocate_word(char **words, char *cpy_s, int i, char c)
{
	char	*substr;

	substr = ft_substr(cpy_s, 0, ft_strchr(cpy_s, c) - cpy_s);
	if (!substr)
	{
		while (i > 0)
			free(words[--i]);
		return (NULL);
	}
	words[i] = substr;
	cpy_s = ft_strchr(cpy_s, c) + 1;
	cpy_s = ft_move_pointer_to_next_non_delimiter(cpy_s, c);
	return (cpy_s);
}

char	**ft_split(char const *s, char c)
{
	char	*cpy_s;
	char	*start;
	char	**words;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	cpy_s = ft_add_delimiter_to_end(s, c);
	if (!cpy_s)
		return (NULL);
	start = cpy_s;
	cpy_s = ft_move_pointer_to_next_non_delimiter(cpy_s, c);
	words = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!words)
		return (NULL);
	while (*cpy_s)
	{
		cpy_s = ft_allocate_word(words, cpy_s, i++, c);
		if (!cpy_s)
			return (NULL);
	}
	words[i] = NULL;
	free(start);
	return (words);
}
