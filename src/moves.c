/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:06:27 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/09 11:39:45 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//pa
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
	}
}

//pb
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
	}
}

//sa
void	swap_a(t_stack *a)
{
	t_number	*first;
	t_number	*second;

	if (a->first && a->first->next)
	{
		first = a->first;
		second = a->first->next;
		a->first = second;
		first->next = second->next;
		a->first->next = first;
		second->previous = NULL;
		first->previous = second;
	}
}

//sb
void	swap_b(t_stack *b)
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

//ss
void	swap_both(t_stack *a, t_stack *b)
{
	swap_a(a);
	swap_a(b);
}

//ra
void	rotate_a(t_stack *a)
{
	t_number	*first;
	t_number	*ptr;

	if (a->first && a->first->next)
	{
		first = a->first;
		a->first = first->next;
		ptr = a->first;
		first->previous = NULL;
		stack_last(ptr)->next = first;
		first->next = NULL;
	}
}

//rb
void	rotate_b(t_stack *b)
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

//rr
void	rotate_both(t_stack *a, t_stack *b)
{
	rotate_a(a);
	rotate_b(b);
}

//rra
void	reverse_rotate_a(t_stack *a)
{
	t_number	*last;
	t_number	*before_last;

	if (a->first && a->first->next)
	{
		last = stack_last(a->first);
		before_last = last->previous;
		before_last->next = NULL;
		last->previous = NULL;
		last->next = a->first;
		a->first = last;
	}
}

//rrb
void	reverse_rotate_b(t_stack *b)
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

//rrr
void	rotate_reverse_both(t_stack *a, t_stack *b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
}
