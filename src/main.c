/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:56:14 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/15 12:21:23 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_number *a, t_number *b, int *tab)
{
	int	size;
	
	size = stack_size(a);
	if (size < 3)
		write(1, "Error\n", 6);
	else if (size == 3)
		sort_three(a, b);
	else if (size == 5)
		sort_five(a, b);
	else if (size > 5 && size <= 100)
	{
		presort(a, tab, size);
	}
	
}

int		main(int argc, char **argv)
{
	t_number 	head_a;
	t_number 	head_b;
	int		*tab;
	int		size;
	
	ft_bzero(&head_a, sizeof(t_number));
	ft_bzero(&head_b, sizeof(t_number));
	tab = NULL;
	if (check_args(argc, argv, &size) && fill_stack(size, ++argv, &tab))
	{
		initialize(&head_a, &tab, size);
		push_swap(&head_a, &head_b, tab);
	}
	else
		write(2, "Error\n", 6);
	free(tab);
	// TESTING
	
	display_stack(&a);
	clean_stack(head_a);
	// sort_three(&a, &b);
	
	
	return (0);
}
