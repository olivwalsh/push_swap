/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:07:31 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/15 12:16:50 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_number	*stack_last(t_number *number)
{
	if (!number)
		return (NULL);
	while (number->next)
		number = number->next;
	return (number);
}

void	stack_add_back(t_number **stack, t_number *new)
{
	t_number	*last;

	if (*stack)
	{
		last = stack_last((*stack));
		new->previous = last;
		last->next = new;
	}
	else
		*stack = new;
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
	new->index = -1;
	new->index_a = -1;
	new->index_b = -1;
	return (new);
}

void	initialize(t_number *head_a, int **tab, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		stack_add_back(&head_a, new_number(tab[0][i]));
		i++;
	}
}
