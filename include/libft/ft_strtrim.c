/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:34:21 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/10 11:42:26 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	from_set(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_len(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	mallocsize(char const *s1, char const *set, int *end, int *start)
{
	*start = 0;
	while (from_set(set, s1[*start]))
		(*start)++;
	*end = ft_len(s1) - 1;
	while (from_set(set, s1[*end]))
		(*end)--;
	(*end)++;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*trim;
	int		start;
	int		end;
	int		size;

	if (!s1 || !set)
		return (NULL);
	mallocsize(s1, set, &end, &start);
	size = end - start;
	if (size < 0)
		size = 0;
	trim = malloc(sizeof(char) * (size + 1));
	if (!trim)
		return (NULL);
	i = 0;
	while ((i + start) < end)
	{
		trim[i] = s1[i + start];
		i++;
	}
	trim[i] = 0;
	return (trim);
}
