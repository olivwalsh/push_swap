/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:26:06 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/20 12:25:37 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_move_cost(t_number *a, t_number *b)
{
	index_b(b);
	index_a(a, b);
	while (b)
	{
		b->cost = b->index_a + b->index_b + 1;
		b = b->next;
	}
}

void	index_b(t_number *head)
{
	int			size;
	int			i;

	size = get_stack_size(head);
	i = 0;
	while (head && i <= size)
	{
		if (i > size / 2)
			head->index_b = size - i;
		else
			head->index_b = i;
		head = head->next;
		i++;
	}
}

void	index_a(t_number *a, t_number *b)
{
	int			min_dif;
	int			i;
	t_number	*head_a;

	head_a = a;
	while (b)
	{
		a = head_a;
		min_dif = ft_abs(b->index - a->index);
		while (a)
		{
			if (ft_abs(b->index - a->index) < min_dif)
				min_dif = ft_abs(b->index - a->index);
			a = a->next;
		}
		a = head_a;
		i = 0;
		while (a)
		{
			if (ft_abs(b->index - a->index) == min_dif)
			{
				if (b->index < a->index)
					b->index_a = i;
				else
					b->index_a = i + 1;
			}	
			i++;
			a = a->next;
		}
		b = b->next;
	}
}

void	first_sort(t_number **head_a, t_number **head_b)
{
	int			size;
	t_number	*tail;

	size = get_stack_size(*head_a);
	while (!is_sorted(head_a))
	{
		tail = stack_last(*head_a);
		if ((*head_a)->index > tail->index)
			reverse_rotate(head_a, head_b, 0);
		else
			push_b(head_a, head_b);
		size--;
	}
	update_move_cost(*head_a, *head_b);
}
