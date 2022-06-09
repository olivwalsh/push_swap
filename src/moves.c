/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:06:27 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/09 20:03:25 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_a(t_stack *a, t_stack *b)
{
	t_number	*a_first;
	t_number	*new;

	if (b && b->first)
	{
		new = b->first;
		b->first = b->first->next;
		if (a->first)
		{
			a_first = a->first;
			a_first->previous = new;
			a->first = new;
			a->first->next = a_first;
		}
		else
		{
			a->first = new;
			a->first->next = NULL;
			a->first->previous = NULL;
		}
		write(1, "pa\n", 3);
	}
}

void	push_b(t_stack *a, t_stack *b)
{
	t_number	*b_first;
	t_number	*new;

	if (a && a->first)
	{
		new = a->first;
		a->first = a->first->next;
		if (b->first)
		{
			b_first = b->first;
			b_first->previous = new;
			b->first = new;
			new->next = b_first;
		}
		else
		{
			b->first = new;
			b->first->next = NULL;
			b->first->previous = NULL;
		}
		write(1, "pb\n", 3);
	}
}

void	swap_s(t_stack *b)
{
	t_number	*first;
	t_number	*second;
	
	if (b->first &&  b->first->next)
	{
		first = b->first;
		second = b->first->next;
		b->first = second;
		first->next = second->next;
		b->first->next = first;
		second->previous = NULL;
		first->previous = second;
	}
}

void	swap(t_stack *a, t_stack *b, int i)
{
	if (i == 0)
	{
		swap_s(a);
		write(1, "sa\n", 3);
	}
	else if (i == 1)
	{
		swap_s(b);
		write(1, "sb\n", 3);
	}
	else if (i == 2)
	{
		swap_s(a);
		swap_s(b);
		write(1, "ss\n", 3);
	}
}

void	rotate_s(t_stack *b)
{
	t_number	*first;
	t_number	*ptr;

	if (b->first)
	{
		first = b->first;
		b->first = first->next;
		ptr = b->first;
		ptr->previous = NULL;
		stack_last(ptr)->next = first;
		first->next = NULL;
	}
}

void	rotate(t_stack *a, t_stack *b, int i)
{
	if (i == 0)
	{
		rotate_s(a);
		write(1, "ra\n", 3);
	}
	else if (i == 1)
	{
		rotate_s(b);
		write(1, "rb\n", 3);
	}
	else if (i == 2)
	{
		rotate_s(a);
		rotate_s(b);
		write(1, "rr\n", 3);
	}
}

void	reverse_rotate_s(t_stack *b)
{
	t_number	*last;
	t_number	*before_last;

	if (b->first && b->first->next)
	{
		last = stack_last(b->first);
		before_last = last->previous;
		before_last->next = NULL;
		last->previous = NULL;
		last->next = b->first;
		b->first = last;
	}
}

void	rotate_reverse(t_stack *a, t_stack *b, int i)
{
	if (i == 0)
	{
		reverse_rotate_s(a);
		write(1, "rra\n", 3);
	}
	else if (i == 1)
	{
		reverse_rotate_s(b);
		write(1, "rrb\n", 3);
	}
	else if (i == 2)
	{
		reverse_rotate_s(a);
		rotate_s(b);
		write(1, "rrr\n", 3);
	}
}
