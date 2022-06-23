/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:30:33 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/23 11:26:20 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_number	*cheapest_to_move(t_number *head_b)
{
	t_number	*b;
	int			cheapest;

	if (!head_b)
		return (NULL);
	cheapest = head_b->cost;
	b = head_b;
	while (b)
	{
		if (b->cost < cheapest)
			cheapest = b->cost;
		b = b->next;
	}
	b = head_b;
	while (b)
	{
		if (b->cost == cheapest)
			return (b);
		b = b->next;
	}
	return (NULL);
}

static void	execute_optimize(t_number **a, t_number **b, t_number *to_move)
{
	while (to_move->moves->rr)
	{
		rotate(a, b, 2);
		to_move->moves->rr--;
	}
	while (to_move->moves->rrr)
	{
		reverse_rotate(a, b, 2);
		to_move->moves->rrr--;
	}
}	

void	execute_moves(t_number **head_a, t_number **head_b, t_number *to_move)
{
	execute_optimize(head_a, head_b, to_move);
	while (to_move->moves->ra)
	{
		rotate(head_a, head_b, 0);
		to_move->moves->ra--;
	}
	while (to_move->moves->rb)
	{
		rotate(head_a, head_b, 1);
		to_move->moves->rb--;
	}
	while (to_move->moves->rra)
	{
		reverse_rotate(head_a, head_b, 0);
		to_move->moves->rra--;
	}
	while (to_move->moves->rrb)
	{
		reverse_rotate(head_a, head_b, 1);
		to_move->moves->rrb--;
	}
}

void	sort(t_number **head_a, t_number **head_b)
{
	reset_indexes(*head_a);
	while (get_stack_size(*head_b))
	{
		update_move_cost(*head_a, *head_b);
		execute_moves(head_a, head_b, cheapest_to_move(*head_b));
		push_a(head_a, head_b);
	}
	final_sort_step(head_a, head_b);
}

void	final_sort_step(t_number **head_a, t_number **head_b)
{
	if (get_max_index(*head_a) < get_stack_size(*head_a) / 2)
	{
		while (!is_sorted(*head_a))
			rotate(head_a, head_b, 0);
	}	
	else
	{
		while (!is_sorted(*head_a))
			reverse_rotate(head_a, head_b, 0);
	}
}
