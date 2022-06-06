/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:59:51 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/10 11:22:45 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_lines(char const *s, char c)
{
	int	i;
	int	lines;

	i = 1;
	lines = 0;
	if (s[0] != c)
		lines++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			lines++;
		i++;
	}
	return (lines);
}

char	**free_previous(char **str, int x)
{
	while (x <= 0)
		free(str[x--]);
	free(str);
	return (NULL);
}

static char	**linemalloc(char **split, char *s, char c)
{
	int	i;
	int	x;

	x = 0;
	while (*s)
	{
		i = 0;
		if (*s && s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			split[x] = malloc(sizeof(char) * (i + 1));
			if (!split[x])
				return (free_previous(split, x));
			x++;
			s += i;
		}
		else
			s++;
	}
	return (split);
}

static void	linefill(char **split, char *s, char c)
{
	int	i;
	int	x;
	int	y;

	x = 0;
	while (*s)
	{
		i = 0;
		if (*s && s[i] != c)
		{
			y = 0;
			while (s[i] && s[i] != c)
			{
				split[x][y] = s[i];
				i++;
				y++;
			}
			split[x][y] = 0;
			x++;
			s += i;
		}
		else
			s++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*cast;
	int		lines;

	if (!s)
		return (NULL);
	cast = (char *)s;
	if (*s == 0)
		lines = 0;
	else
		lines = count_lines(s, c);
	split = malloc(sizeof(char *) * (lines + 1));
	if (!split)
		return (NULL);
	if (!linemalloc(split, cast, c))
		return (NULL);
	else
	{
		linefill(split, cast, c);
		split[lines] = NULL;
		return (split);
	}
}
