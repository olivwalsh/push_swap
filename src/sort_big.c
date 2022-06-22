/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:00:53 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/22 15:48:48 by owalsh           ###   ########.fr       */
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

	size = get_stack_size(*head);
	i = size / chunck_size;
	pivots = malloc(sizeof(int) * (i + 1));
	if (!pivots)
		return (NULL);
	i = 0;
	while (i < (size / chunck_size) + 1)
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
	t_number	*a;
	int			cheapest;

	if (!head)
		return (NULL);
	a = head;
	// initialize cheapest to first cheapest that belongs to current chunk
	while (a && !is_inchunk(a, min, max))
		a = a->next;
	if (!a)
		return (NULL);
	cheapest = a->index_a;
	a = head;
	while (a)
	{
		if (is_inchunk(a, min, max) && a->index_a < cheapest)
			cheapest = a->index_a;
		a = a->next;
	}
	a = head;
	while (a)
	{
		if (is_inchunk(a, min, max) && a->index_a == cheapest)
				return (a);
		a = a->next;
	}
	return (NULL);
}

void	sort_big(t_number **a, t_number **b)
{
	int	*pivots;
	int	pivot;
	int	stack_size;
	int	i, diff;
	int tab_size;
	t_number	*cheapest;

	stack_size = get_stack_size(*a);
	tab_size = stack_size / chunck_size + 1;
	display_stack(*a);
	pivots = find_pivot(a);
	i = 1;
	while (i < tab_size)
	{
		pivot = pivots[i];
		diff = pivots[i] - pivots[i - 1];
		while (diff + 2)
		{
			printf("chunk size left = %d", diff);
			cost_to_pushb(*a);
			cheapest = cheapest_in_chunk(*a, pivots[i - 1], pivots[i]);
			if (!cheapest)
			{
				printf("cheapest not found\n");
				break;
			}
			else
				printf("cheapest found, executing moves\n");
			execute_moves(a, b, cheapest);
			push_b(a, b);
			diff--;
			
		}
		i++;
	}
	free(pivots);
}
