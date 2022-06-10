/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:27:35 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/10 12:26:37 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	sort_three(t_stack *a, t_stack *b)
{
	if ((a->first->num < a->first->next->num) && \
		(a->first->next->num < a->first->next->next->num))
		return ;
	if ((a->first->num > a->first->next->num) && \
		(a->first->next->num > a->first->next->next->num))
	{
		rotate(a, b, 0);
		swap(a, b, 0);
		return ;
	}
	if ((a->first->num < a->first->next->next->num) && \
		(a->first->next->num > a->first->num))
	{
		rotate_reverse(a, b, 0);
		swap(a, b, 0);
		return ;
	}
	if (a->first->next->next->num < a->first->num)
		rotate_reverse(a, b, 0);
	if (a->first->next->next->num < a->first->num)
		rotate_reverse(a, b, 0);
	if (a->first->num > a->first->next->num)
		swap(a, b, 0);
}
