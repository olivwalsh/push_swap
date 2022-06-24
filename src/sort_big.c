/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:00:53 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/24 19:04:23 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_to_pushb(t_number *head)
{
	int			size;
	int			i;

	size = get_stack_size(head);
	i = 0;
	while (head && i <= size)
	{
		if (i > size / 2)
		{
			head->index_a = size - i;
			head->moves->rra = size - i;
		}
		else
		{
			head->index_a = i;
			head->moves->ra = i;
		}
		head = head->next;
		i++;
	}
}

// find number of pivots
int	*find_pivot(t_number **head)
{
	int	i;
	int	size;
	int	tab_size;
	int	*pivots;

	size = get_stack_size(*head);
	tab_size = size / chunck_size;
	if (size % chunck_size != 0)
		tab_size++;
	pivots = malloc(sizeof(int) * (tab_size + 1));
	if (!pivots)
		return (NULL);
	i = 0;
	while (i < tab_size)
	{
		pivots[i] = i * chunck_size;
		i++;
	}
	pivots[i] = size;
	return (pivots);
}

int	is_inchunk(t_number *number, int min, int max)
{
	if (number->index > min && number->index <= max)
		return (1);
	return (0);
}

t_number	*cheapest_in_chunk(t_number *head, int min, int max)
{
	t_number	*first;
	t_number	*last;

	if (!head)
		return (NULL);
	first = head;
	while (first && !is_inchunk(first, min, max))
		first = first->next;
	if (!first)
		return (NULL);
	last = stack_last(head);
	while (last && !is_inchunk(last, min, max))
		last = last->previous;
	if (!last)
		return (NULL);
	if (first->index_a < last->index_a)
		return (first);
	else
		return (last);
	return (NULL);
}

void	sort_big(t_number **a, t_number **b)
{
	int		*p;
	int		i;
	int		diff;
	int		tab_size;

	tab_size = get_stack_size(*a) / chunck_size;
	if (get_stack_size(*a) % chunck_size != 0)
		tab_size++;
	p = find_pivot(a);
	i = 0;
	while (i < tab_size)
	{
		diff = p[i + 1] - p[i];
		while (diff)
		{
			reset_indexes(*a);
			cost_to_pushb(*a);
			execute_moves(a, b, cheapest_in_chunk(*a, p[i], p[i + 1]));
			push_b(a, b);
			diff--;
		}
		i++;
	}
	free(p);
}
