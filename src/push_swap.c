/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:27:35 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/14 21:50:46 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *s)
{
	t_number	*ptr;
	int			size;

	size = 0;
	if (s && s->first)
	{
		ptr = s->first;
		while (ptr)
		{
			ptr = ptr->next;
			size++;
		}
	}
	return (size);
}

int	stack_min_index(t_stack *s)
{
	t_number	*ptr;
	int			min;
	int			i;

	i = 0;
	ptr = s->first;
	min = ptr->num;
	while (ptr)
	{
		if (ptr->num < min)
			min = ptr->num;
		ptr = ptr->next;
	}
	ptr = s->first;
	while (ptr)
	{
		if (ptr->num == min)
			return (i);
		i++;
		ptr = ptr->next;
	}
	return (-1);
}

void	sort_three(t_stack *a, t_stack *b)
{
	display_stack(*a);
	if (a->first && (a->first->num < a->first->next->num)
		&& (a->first->next->num < a->first->next->next->num))
		return ;
	if (a->first && (a->first->num > a->first->next->num)
		&& (a->first->next->num > a->first->next->next->num))
	{
		rotate(a, b, 0);
		swap(a, b, 0);
		return ;
	}
	if (a->first && (a->first->num < a->first->next->next->num)
		&& (a->first->next->num > a->first->num))
	{
		reverse_rotate(a, b, 0);
		swap(a, b, 0);
		return ;
	}
	if (a->first && (a->first->next->next->num < a->first->num))
		reverse_rotate(a, b, 0);
	if (a->first && a->first->next->next->num < a->first->num)
		reverse_rotate(a, b, 0);
	if (a->first && a->first->num > a->first->next->num)
		swap(a, b, 0);
}

void	min_after_mid(t_stack *a, t_stack *b, int min, int mid)
{
	t_number	*ptr;

	ptr = a->first;
	while (min >= mid && min < stack_size(a))
	{
		reverse_rotate(a, b, 0);
		min++;
	}
	push_b(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int			min;
	int			mid;

	min = stack_min_index(a);
	mid = (stack_size(a) / 2);
	if (min >= mid)
		min_after_mid(a, b, min, mid);
	else
	{
		if (min == 1)
			swap(a, b, 0);
		push_b(a, b);
	}
	min = stack_min_index(a);
	mid = (stack_size(a) / 2);
	if (min >= mid)
		min_after_mid(a, b, min, mid);
	else
	{
		if (min == 1)
			swap(a, b, 0);
		push_b(a, b);
	}
	sort_three(a, b);
	if (b->first->num < b->first->next->num)
		swap(a, b, 1);
	push_a(a, b);
	push_a(a, b);
}
