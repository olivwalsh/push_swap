/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:26:31 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/17 18:47:50 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicates(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	fill_tab(int size, char **argv, int **tab)
{
	int	i;

	tab[0] = malloc(sizeof(int) * size);
	if (!tab[0])
		return (0);
	i = 0;
	while (argv[i])
	{
		tab[0][i] = ft_atoi(argv[i]);
		i++;
	}
	return (check_duplicates(*tab, size));
}

int	check_args(int argc, char **argv, int *size)
{
	int	i;
	int	j;

	i = 1;
	*size = 0;
	if (argc < 3)
		return (0);
	while (argv[i])
	{
		if (argv[i][0] == '-')
				j = 1;
		else
			j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
		*size += 1;
	}
	return (1);
}
