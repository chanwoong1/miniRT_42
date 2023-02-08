/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_is_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 09:44:06 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/17 15:03:04 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(const char *str)
{
	size_t	cnt;
	bool	is_after_word;

	if (!*str)
		return (0);
	cnt = 0;
	is_after_word = false;
	while (*str)
	{
		if (!ft_isspace(*str))
			is_after_word = true;
		if (is_after_word && (ft_isspace(*str) || *(str + 1) == '\0'))
		{
			is_after_word = false;
			++cnt;
		}
		++str;
	}
	return (cnt);
}

static size_t	get_word_len(const char *word_start)
{
	size_t	word_len;

	word_len = 0;
	while (*word_start && ft_isspace(*word_start))
		++word_start;
	while (*word_start && !ft_isspace(*word_start))
	{
		++word_start;
		++word_len;
	}
	return (word_len);
}

static char	*each_word_malloc(const char **word_start)
{
	size_t	len;
	size_t	cnt;
	char	*pa_word;

	cnt = 0;
	len = get_word_len(*word_start);
	pa_word = malloc((sizeof(*pa_word) * len) + 1);
	if (!pa_word)
		return (NULL);
	while (cnt < len)
	{
		if (!ft_isspace(**word_start))
		{
			pa_word[cnt] = **word_start;
			++cnt;
		}
		++(*word_start);
	}
	pa_word[len] = '\0';
	return (pa_word);
}

static void	free_all(char **strs, size_t idx)
{
	size_t	i;

	i = 0;
	while (i <= idx)
	{
		if (strs[i] != NULL)
		{
			free(strs[i]);
			strs[i] = NULL;
		}
		i++;
	}
	free(strs);
	strs = NULL;
}

char	**ft_split_is_space(char const *s)
{
	char			**pa_result;
	size_t			word_count;
	size_t			i;

	word_count = count_word(s);
	pa_result = malloc((sizeof(*pa_result) * (word_count + 1)));
	if (!pa_result)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		pa_result[i] = each_word_malloc(&s);
		if (pa_result[i] == NULL)
		{
			free_all(pa_result, i);
			return (NULL);
		}
		++i;
	}
	pa_result[word_count] = NULL;
	return (pa_result);
}
