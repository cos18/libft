/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:57:59 by sunpark           #+#    #+#             */
/*   Updated: 2020/02/28 22:29:02 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	int	result;
	int	is_word;

	result = 0;
	is_word = 0;
	while (*s)
	{
		if (is_word == 0 && *s != c)
			is_word = 1;
		if (is_word && *s == c)
		{
			result++;
			is_word = 0;
		}
		s++;
	}
	if (is_word)
		result++;
	return (result);
}

static void	get_sep_word(char **sep, char const *s, char c)
{
	int		word_size;
	char	*start;

	word_size = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		if (word_size == 0 && *s != c)
			start = (char *)s;
		if (word_size && *s == c)
		{
			*(sep++) = ft_substr(start, 0, word_size);
			word_size = 0;
		}
		if (*s != c)
			word_size++;
		s++;
	}
	if (word_size)
		*(sep++) = ft_substr(start, 0, word_size);
	*sep = NULL;
}

char		**ft_split(char const *s, char c)
{
	int		words;
	char	**result;
	
	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (result)
		get_sep_word(result, s, c);
	return (result);
}
