/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:00:30 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/14 15:35:41 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	presort(t_stack *a, int *tab, int size)
{
	t_number	*ptr;
	int			i;
	
	bubble_sort(&tab, size);
	ptr = NULL;
	if (a && a->first)
		ptr = a->first;
	i = 0;
	while (i < size)
	{
		printf("ptr->num = %d\ntab[%d] = %d\n", ptr->num, i, tab[i]);
		if (ptr->num == tab[i])
		{
			printf("ptr->num = %d, i = %d\n", ptr->num, i);
			ptr->from_index = i;
			printf("ptr->index = %d\n", ptr->from_index);
			ptr = ptr->next;
			i = 0;
		}
		i++;
	}
}

void	bubble_sort(int **tab, int size)
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
