/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:06:27 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/15 12:19:43 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_number *a, t_number *b)
{
	t_number	*a_first;
	t_number	*new;

	if (b)
	{
		new = b;
		
		b = b->next;
		if (a)
		{
			a_first = a;
			a_first->previous = new;
			a = new;
			a->next = a_first;
			
		}
		else
		{
			a = new;
			a->next = NULL;
			a->previous = NULL;
		}
		write(1, "pa\n", 3);
	}
}

void	push_b(t_number *a, t_number *b)
{
	t_number	*b_first;
	t_number	*new;

	if (a && a)
	{
		new = a;
		a = a->next;
		if (b)
		{
			b_first = b;
			b_first->previous = new;
			b = new;
			new->next = b_first;
		}
		else
		{
			b = new;
			b->next = NULL;
			b->previous = NULL;
		}
		write(1, "pb\n", 3);
	}
}

void	swap_s(t_number *b)
{
	t_number	*first;
	t_number	*second;
	
	if (b &&  b->next)
	{
		first = b;
		second = b->next;
		b = second;
		first->next = second->next;
		b->next = first;
		second->previous = NULL;
		first->previous = second;
	}
}

void	swap(t_number *a, t_number *b, int i)
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

void	rotate_s(t_number *s)
{
	t_number	*head;
	t_number	*tail;

	if (s)
	{
		head = s;
		tail = stack_last(head);
		tail->next = head;
		head->previous = tail;
		s = head->next;
		s->previous = NULL;
		head->next = NULL;
	}
}

void	rotate(t_number *a, t_number *b, int i)
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

void	reverse_rotate_s(t_number *s)
{
	t_number	*head;
	t_number	*tail;

	if (s && s->next)
	{
		head = s;
		tail = stack_last(s);
		tail->previous->next = NULL;
		s = tail;
		tail->previous = NULL;
		tail->next = head;
		head->previous = s;
	}
}

void	reverse_rotate(t_number *a, t_number *b, int i)
{
	if (i == 0)
	{
		reverse_rotate_s(a);
		write(1, "rra\n", 4);
	}
	else if (i == 1)
	{
		reverse_rotate_s(b);
		write(1, "rrb\n", 4);
	}
	else if (i == 2)
	{
		reverse_rotate_s(a);
		reverse_rotate_s(b);
		write(1, "rrr\n", 4);
	}
}
