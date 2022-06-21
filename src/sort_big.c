/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:00:53 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/21 20:22:42 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// find cheapest element in stack a to send to b which belongs to first pivot
// do same for other pivots
// then same algo as for 100

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
	int size;
	int	*pivots;
	int	j;

	size = get_stack_size(*head);
	i = size / chunck_size;
	pivots = malloc(sizeof(int) * (i + 1));
	if (!pivots)
		return (NULL);
	pivots[0] = 0;
	j = 0;
	while (j < i)
	{
		pivots[j + 1] = size / (i - j);
		j++;
	}
	j = 0;
	while (j <= i)
	{
		printf("pivots[%d] = %d\n", j, pivots[j]);
		j++;
	}
	return (pivots);
}

t_number	*cheapest_in_chunk(t_number *head, int min, int max)
{
	t_number	*a;
	int			cheapest;

	if (!head)
		return (NULL);
	cheapest = head->index_a;
	printf("in fct cheapest in chunk\ncheapest initialized to = %d\nmin = %d max = %d\n", cheapest, min, max);
	a = head;
	while (a)
	{
		printf("a->index = %d\n", a->index);
		if (a->index >= min && a->index <= max)
		{
			if (a->index_a < cheapest)
				cheapest = a->index_a;
		}
		a = a->next;
	}
	a = head;
	while (a)
	{
		if (a->index >= min && a->index <= max)
		{
			if (a->index_a == cheapest)
				return (a);
		}
		a = a->next;
	}
	return (NULL);
}

void	sort_big(t_number **a, t_number **b)
{
	int	*pivots;
	int	pivot;
	int	i;
	int tab_size;
	t_number	*cheapest;

	tab_size = get_stack_size(*a) / chunck_size;
	display_stack(*a);
	printf("1\n");
	pivots = find_pivot(a);
	i = 1;
	printf("2\n");
	while (i < tab_size)
	{
		printf("3\n");
		pivot = pivots[i];
		printf("4\n");
		while (pivot)
		{
			printf("pivot = %d\n", pivot);
			cost_to_pushb(*a);
			printf("after cost to pushb\n");
			cheapest = cheapest_in_chunk(*a, pivots[i - 1], pivots[i]);
			printf("found cheapest = %d\n", cheapest->num);
			execute_moves(a, b, cheapest);
			printf("after cost to pushb\n");
			push_b(a, b);
			pivot--;
		}
		i++;
	}
}
