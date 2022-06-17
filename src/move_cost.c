/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:26:06 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/17 20:55:37 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_b(t_number **head)
{
	t_number	*ptr;
	int			size;
	int			i;
	int			j;

	ptr = *head;
	size = stack_size(*head);
	i = 1;
	while (ptr && i <= size / 2 + 1)
	{
		ptr->cost = i;
		ptr = ptr->next;
		i++;
	}
	j = 2;
	ptr = stack_last(*head);
	while (i <= size)
	{
		ptr->cost = j;
		ptr = ptr->previous;
		i++;
		j++;
	}
}

// void	cost_a(t_number **head_a, t_number *ptr)
// {
// 	t_number	*tmp;
// 	int			i;

// 	tmp = *head_a;
// 	i = 1;
// 	while (ptr)
// 	{
// 		if (ptr->index <  )
// 		ptr = ptr->next;
// 		i++;
// 	}
// }

void	first_sort(t_number **head_a, t_number **head_b)
{
	int			size;
	t_number	*tail;
	
	size = stack_size(*head_a);
	while (size > 0 && !is_sorted(head_a))
	{
		tail = stack_last(*head_a);
		if ((*head_a)->index > tail->index)
			reverse_rotate(head_a, head_b, 0);
		else
			push_b(head_a, head_b);
		size--;
	}
}