/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:53:10 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/21 11:54:05 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
