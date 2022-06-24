/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:29:05 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/24 14:41:41 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_charset(char c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	return (0);
}

int	str_count(char *str)
{
	int	i;
	int strs;

	strs = 0;
	i = 1;
	if (!is_charset(str[0]))
		strs++;
	while (str[i])
	{
		if (is_charset(str[i - 1]) && !is_charset(str[i]))
			strs++;
		i++;
	}
	return (strs);
}

char	**free_previous(char **str, int x)
{
	while (x <= 0)
		free(str[x--]);
	free(str);
	return (NULL);
}

void	fill(char *s, char **split, int index)
{
	int	i;

	i = 0;
	while (!is_charset(*s))
	{
		split[index][i] = *s;
		s++;
		i++;
	}
	split[index][i] = '\0';
}

char	**split_str(char **split, char *s)
{
	int	i;
	int	x;

	x = 0;
	while (*s)
	{
		i = 0;
		if (s && !is_charset(s[i]))
		{
			while (s[i] && !is_charset(s[i]))
				i++;
			split[x] = malloc(sizeof(char) * (i + 1));
			if (!split[x])
				return (free_previous(split, x));
			fill(s, split, x);
			x++;
			s += i;
		}
		else
			s++;
	}
	split[x] = NULL;
	return (split);
}

char	**ft_split(char *str)
{
	char	**split;
	int		count;

	if (!str)
		return (NULL);
	count = str_count(str);
	split = malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	return (split_str(split, str));
}
