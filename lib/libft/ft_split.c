/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashirzad <ashirzad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:14:49 by ashirzad          #+#    #+#             */
/*   Updated: 2024/03/20 19:50:27 by ashirzad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	skip_delimiter(char const **ps, char c);
static int	count_words(char const *str, char c);
static void	free_split(char **mem, int size);
static int	word_len(char const *str, char c);

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word_count;
	int		word_length;
	char	**split_array;

	i = -1;
	word_count = count_words(s, c);
	split_array = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!split_array)
		return (split_array);
	while (++i < word_count)
	{
		skip_delimiter(&s, c);
		word_length = word_len(s, c);
		split_array[i] = (char *)malloc(word_length + 1);
		if (!split_array[i])
		{
			free_split(split_array, i);
			return (0);
		}
		ft_strlcpy(*(split_array + i), s, word_length + 1);
		s += word_length;
	}
	split_array[i] = NULL;
	return (split_array);
}

static void	skip_delimiter(char const **ps, char c)
{
	while (**ps == c || **ps == 0)
		(*ps)++;
}

static int	word_len(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str == c)
		str++;
	while (*str && *str++ != c)
		count++;
	return (count);
}

static int	count_words(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

void	free_split(char **result, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(result[i]);
		i++;
	}
	free(result);
}
