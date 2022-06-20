/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:27:35 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/20 18:48:01 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_number **a, t_number **b)
{
	if (is_sorted(*a))
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
	while (get_stack_size(*a) > 3)
	{
		while (get_min_index(*a) >= 2
			&& get_min_index(*a) < get_stack_size(*a))
			reverse_rotate(a, b, 0);
		if (get_min_index(*a) == 1)
			swap(a, b, 0);
		push_b(a, b);
	}
	sort_three(a, b);
	while (get_stack_size(*b) > 0)
		push_a(a, b);
}
