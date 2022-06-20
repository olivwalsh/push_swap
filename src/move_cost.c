/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:26:06 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/20 18:56:39 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_number_moves(t_number *b)
{
	while (b->moves->ra > 0 && b->moves->rb > 0)
	{
		b->moves->rr += 1;
		b->moves->ra--;
		b->moves->rb--;	
	}
	while (b->moves->rra > 0 && b->moves->rrb > 0)
	{
		b->moves->rrr += 1;
		b->moves->rra--;
		b->moves->rrb--;	
	}
	b->cost = b->moves->ra + b->moves->rb + b->moves->rr + b->moves->rra + b->moves->rrb + b->moves->rrr + 1;
}

void	reset_indexes(t_number *head)
{
	while (head)
	{
		head->moves->ra = 0;
		head->moves->rb = 0;
		head->moves->rr = 0;
		head->moves->rra = 0;
		head->moves->rrb = 0;
		head->moves->rrr = 0;
		head = head->next;
	}
}

void	update_move_cost(t_number *a, t_number *b)
{
	reset_indexes(b);
	index_b(b);
	index_a(a, b);
	while (b)
	{
		b->cost = b->index_a + b->index_b + 1;
		optimize_number_moves(b);
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
		{
			head->index_b = size - i;
			head->moves->rrb = size - i;
		}
		else
		{
			head->index_b = i;
			head->moves->rb = i;
		}
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
				if (b->index <= a->index)
				{
					b->moves->ra = i;
					b->index_a = i;
				}
				else
				{
					b->index_a = i + 1;
					b->moves->ra = i + 1;
				}
				break;
			}	
			i++;
			a = a->next;
		}
		b = b->next;
	}
}

void	first_sort(t_number **head_a, t_number **head_b)
{
	t_number	*tail;

	while (is_sorted(*head_a) == 0)
	{
		tail = stack_last(*head_a);
		if ((*head_a)->index > tail->index)
			rotate(head_a, head_b, 0);
		else
			push_b(head_a, head_b);
	}
	update_move_cost(*head_a, *head_b);
}
