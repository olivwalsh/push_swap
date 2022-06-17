/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:27:35 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/17 18:48:20 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_number *s)
{
	t_number	*ptr;
	int			size;

	size = 0;
	if (s && s->next)
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

void	sort_three(t_number **a, t_number **b)
{
	if (is_sorted(a))
		return ;
	if (a && ((*a)->num > (*a)->next->num)
		&& ((*a)->next->num > (*a)->next->next->num))
	{
		rotate(a, b, 0);
		swap(a, b, 0);
		return ;
	}
	if (a && ((*a)->num < (*a)->next->next->num)
		&& ((*a)->next->num > (*a)->num))
	{
		reverse_rotate(a, b, 0);
		swap(a, b, 0);
		return ;
	}
	if (a && ((*a)->next->next->num < (*a)->num))
		reverse_rotate(a, b, 0);
	if (a && ((*a)->next->next->num < (*a)->num))
		reverse_rotate(a, b, 0);
	if (a && (*a)->num > (*a)->next->num)
		swap(a, b, 0);
}

void	sort_five(t_number **a, t_number **b)
{
	while (stack_size(*a) > 3)
	{
		while (stack_min_index(*a) >= 2
			&& stack_min_index(*a) < stack_size(*a))
			reverse_rotate(a, b, 0);
		if (stack_min_index(*a) == 1)
			swap(a, b, 0);
		push_b(a, b);
	}
	sort_three(a, b);
	while (stack_size(*b) > 0)
		push_a(a, b);
}
