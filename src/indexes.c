/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:30:40 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/23 12:54:23 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	index_a_to_moves(t_number *a, t_number *b, int min_dif, int size)
{
	int	i;

	i = 0;
	while (a)
	{
		if (ft_abs(b->index - a->index) == min_dif)
		{
			if (b->index > a->index)
				i++;
			if (i > size / 2)
				b->moves->rra = size - i;
			else
				b->moves->ra = i;
			b->index_a = i;
			break ;
		}	
		i++;
		a = a->next;
	}
}

void	index_a(t_number *a, t_number *b)
{
	int			min_dif;
	t_number	*head_a;
	int			size;

	head_a = a;
	size = get_stack_size(a);
	if (!a)
	{
		b->index_a = 0;
		return ;
	}
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
		index_a_to_moves(head_a, b, min_dif, size);
		b = b->next;
	}
}
