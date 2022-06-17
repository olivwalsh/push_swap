/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:56:14 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/17 20:43:02 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_number **a, t_number **b)
{
	int	size;

	size = stack_size(*a);
	if (size < 3)
		write(1, "Error\n", 6);
	else if (size == 3)
		sort_three(&(*a), &(*b));
	else if (size > 3 && size <= 5)
		sort_five(a, b);
	else if (size > 5 && size <= 100)
	{
		cost_b(a);
		//first_sort(a, b);
		
	}
}

int	main(int argc, char **argv)
{
	t_number	*head_a;
	t_number	*head_b;
	int			*tab;
	int			size;

	tab = NULL;
	head_b = NULL;
	head_a = NULL;
	if (check_args(argc, argv, &size) && fill_tab(size, ++argv, &tab))
	{
		initialize(&head_a, &tab, size);
		push_swap(&head_a, &head_b);
	}
	else
		write(2, "Error\n", 6);
	free(tab);
	// TESTING
	printf("STACK A:\n");
	display_stack(head_a);
	printf("STACK B:\n");
	display_stack(head_b);
	clean_stack(&head_a);
	return (0);
}
