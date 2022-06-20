/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 21:46:35 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/20 09:04:58 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(t_number *head)
{
	t_number	*ptr;

	ptr = head;
	if (!ptr)
		printf("nothing to be displayed\n");
	while (ptr)
	{
		printf("ptr->num = %d\t\tptr->index = %d\t\tptr->index_b = %d\t\t", ptr->num, ptr->index, ptr->index_b);
		printf("ptr->index_a = %d\t\tptr->cost = %d\t\t", ptr->index_a, ptr->cost);
		printf("ptr->max = %d\n", ptr->max);
		printf("ptr->prev = %p\t\tptr = %p\t\tptr->next = %p\n", ptr->previous, ptr, ptr->next);
		printf("- - - - - - - - - - - - - - - - - \n");
		ptr = ptr->next;
	}
}

void	display_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("tab[%d] = %d\n", i, tab[i]);
		i++;
	}
}