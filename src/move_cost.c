/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:26:06 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/21 11:31:11 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_number_moves(t_number *b)
{
	while (b->moves->ra > 0 && b->moves->rb > 0)
	{
		b->moves->rr++;
		b->moves->ra--;
		b->moves->rb--;
	}
	while (b->moves->rra > 0 && b->moves->rrb > 0)
	{
		b->moves->rrr++;
		b->moves->rra--;
		b->moves->rrb--;
	}
	b->cost = b->moves->ra + b->moves->rb + b->moves->rr;
	b->cost += b->moves->rra + b->moves->rrb + b->moves->rrr + 1;
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

void	first_sort(t_number **head_a, t_number **head_b)
{
	t_number	*tail;

	while (is_sorted(*head_a) == 0)
	{
		tail = stack_last(*head_a);
		if (((*head_a)->index > tail->index) || tail->num == tail->max)
			rotate(head_a, head_b, 0);
		else
			push_b(head_a, head_b);
	}
	update_move_cost(*head_a, *head_b);
}
