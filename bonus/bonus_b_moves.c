/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_b_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:06:27 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/24 18:09:52 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	update_head(t_number **head)
{
	if ((*head)->next)
	{
		*head = (*head)->next;
		(*head)->previous = NULL;
	}
	else
		*head = NULL;
}

void	push_a(t_number **head_a, t_number **head_b)
{
	t_number	*a_first;
	t_number	*new;

	if (!*head_b)
		return ;
	new = *head_b;
	update_head(head_b);
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
}

void	push_b(t_number **head_a, t_number **head_b)
{
	t_number	*b_first;
	t_number	*new;

	if (!*head_a)
		return ;
	new = *head_a;
	update_head(head_a);
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
		swap_s(a);
	else if (i == 1)
		swap_s(b);
	else if (i == 2)
	{
		swap_s(a);
		swap_s(b);
	}
}
