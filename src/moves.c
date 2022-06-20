/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:06:27 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/20 17:50:55 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_number **head_a, t_number **head_b)
{
	t_number	*a_first;
	t_number	*new;

	if (*head_b)
	{
		new = *head_b;
		if ((*head_b)->next)
		{
			*head_b = (*head_b)->next;
			(*head_b)->previous = NULL;
		}
		else
			*head_b = NULL;
		if (*head_a)
		{
			a_first = *head_a;
			a_first->previous = new;
			*head_a = new;
			(*head_a)->next = a_first;
			(*head_a)->previous = NULL;
		}
		else
		{
			(*head_a) = new;
			(*head_a)->next = NULL;
			(*head_a)->previous = NULL;
		}
		write(1, "pa\n", 3);
	}
}

void	push_b(t_number **head_a, t_number **head_b)
{
	t_number	*b_first;
	t_number	*new;

	if (*head_a)
	{
		new = *head_a;
		if ((*head_a)->next)
		{
			*head_a = (*head_a)->next;
			(*head_a)->previous = NULL;
		}
		else
			*head_a = NULL;
		if (*head_b)
		{
			b_first = *head_b;
			b_first->previous = new;
			*head_b = new;
			new->next = b_first;
			new->previous = NULL;
		}
		else
		{
			*head_b = new;
			(*head_b)->next = NULL;
			(*head_b)->previous = NULL;
		}
		write(1, "pb\n", 3);
	}
}

void	swap_s(t_number **head)
{
	t_number	*tmp;
	t_number	*next;

	if (!(*head) || !((*head)->next))
		return ;
	tmp = *head;
	next = (*head)->next;
	tmp->previous = next;
	next->next->previous = tmp;
	tmp->next = next->next;
	next->previous = NULL;
	next->next = *head;
	*head = next;
}

void	swap(t_number **a, t_number **b, int i)
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

void	rotate_s(t_number **head)
{
	t_number	*tmp;
	t_number	*tail;

	if (!(*head) || !((*head)->next))
		return ;
	tail = stack_last(*head);
	tail->next = *head;
	(*head)->previous = tail;
	tmp = (*head)->next;
	(*head)->next = NULL;
	tmp->previous = NULL;
	*head = tmp;
}

void	rotate(t_number **a, t_number **b, int i)
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

void	reverse_rotate_s(t_number **head)
{
	t_number	*tail;
	t_number	*ptr;

	ptr = *head;
	if (ptr && ptr->next)
	{
		tail = stack_last(ptr);
		tail->previous->next = NULL;
		tail->previous = NULL;
		tail->next = ptr;
		ptr->previous = tail;
		*head = tail;
	}
}

void	reverse_rotate(t_number **a, t_number **b, int i)
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
