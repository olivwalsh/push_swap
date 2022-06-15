/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:27:35 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/15 19:54:08 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_number *s)
{
	t_number	*ptr;
	int			size;

	size = 0;
	if (s && s)
	{
		ptr = s;
		while (ptr)
		{
			ptr = ptr->next;
			size++;
		}
	}
	return (size);
}

int	stack_min_index(t_number *s)
{
	t_number	*ptr;
	int			min;
	int			i;

	i = 0;
	ptr = s;
	min = ptr->num;
	while (ptr)
	{
		if (ptr->num < min)
			min = ptr->num;
		ptr = ptr->next;
	}
	ptr = s;
	while (ptr)
	{
		if (ptr->num == min)
			return (i);
		i++;
		ptr = ptr->next;
	}
	return (-1);
}

void	sort_three(t_number *a, t_number *b)
{
	if (is_sorted(a))
		return ;
	if (a && (a->num > a->next->num)
		&& (a->next->num > a->next->next->num))
	{
		rotate(&a, &b, 0);
		swap(&a, &b, 0);
		return ;
	}
	if (a && (a->num < a->next->next->num)
		&& (a->next->num > a->num))
	{
		reverse_rotate(&a, &b, 0);
		swap(&a, &b, 0);
		return ;
	}
	if (a && (a->next->next->num < a->num))
		reverse_rotate(&a, &b, 0);
	if (a && a->next->next->num < a->num)
		reverse_rotate(&a, &b, 0);
	if (a && a->num > a->next->num)
		swap(&a, &b, 0);
}

void	min_after_mid(t_number *a, t_number *b, int min, int mid)
{
	t_number	*ptr;

	ptr = a;
	while (min >= mid && min < stack_size(a))
	{
		reverse_rotate(&a, &b, 0);
		min++;
	}
	push_b(a, b);
}

void	sort_five(t_number *a, t_number *b)
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
			swap(&a, &b, 0);
		push_b(a, b);
	}
	min = stack_min_index(a);
	mid = (stack_size(a) / 2);
	if (min >= mid)
		min_after_mid(a, b, min, mid);
	else
	{
		if (min == 1)
			swap(&a, &b, 0);
		push_b(a, b);
	}
	sort_three(a, b);
	if (b->num < b->next->num)
		swap(&a, &b, 0);
	push_a(a, b);
	push_a(a, b);
}
