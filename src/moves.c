/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:06:27 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/07 18:45:13 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_number	*stack_last(t_number *number)
{
	if (!number)
		return (NULL);
	while (number->next)
		number = number->next;
	return (number);
}

void	stack_add_back(t_stack **stack, t_number *new)
{
	t_number	*last;

	if ((*stack)->first)
	{
		last = stack_last((*stack)->first);
		new->previous = last;
		last->next = new;
		
	}
	else
		(*stack)->first = new;
}

t_number	*new_number(int num)
{
	t_number	*new;

	new = malloc(sizeof(t_number));
	if (!new)
		return (NULL);
	new->num  = num;
	new->next = NULL;
	new->previous = NULL;
	new->from_index = -1;
	new->to_index = -1;
	return (new);
}

void	initialize(t_stack *a, int **tab, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		stack_add_back(&a, new_number(tab[0][i]));
		i++;
	}
	a->size = i;
}