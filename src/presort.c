/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:00:30 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/21 12:25:41 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int **tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i + 1 < size)
	{
		j = i + 1;
		if (tab[0][i] > tab[0][j])
		{
			tmp = tab[0][i];
			tab[0][i] = tab[0][j];
			tab[0][j] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	presort(t_number *a, int *tab, int size, int max)
{
	t_number	*ptr;
	int			i;

	bubble_sort(&tab, size);
	ptr = NULL;
	if (a && a)
		ptr = a;
	i = 0;
	while (ptr && i < size)
	{
		if (ptr->num == tab[i])
		{
			ptr->index = i + 1;
			ptr->max = max;
			ptr = ptr->next;
			i = 0;
		}
		else
			i++;
	}
}
