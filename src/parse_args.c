/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:26:31 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/24 15:42:42 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

static long	ps_atoi(const char *nptr)
{
	char	*str;
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	str = (char *)nptr;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

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
	int		i;
	long	num;

	tab[0] = malloc(sizeof(int) * size);
	if (!tab[0])
		return (0);
	i = 0;
	while (argv[i])
	{
		num = ps_atoi(argv[i]);
		if (argv[i][0] == '\0')
			return (0);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		tab[0][i] = (int)num;
		i++;
	}
	return (check_duplicates(*tab, size));
}

int	check_args(char **argv, int *size)
{
	int	i;
	int	j;

	i = 1;
	*size = 0;
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
