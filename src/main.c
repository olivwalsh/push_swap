/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:56:14 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/14 21:49:48 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b, int *tab)
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
	t_stack 	a;
	t_stack 	b;
	int		*tab;
	int		size;
	
	ft_bzero(&a, sizeof(t_stack));
	ft_bzero(&b, sizeof(t_stack));
	tab = NULL;
	if (check_args(argc, argv, &size) && fill_stack(size, ++argv, &tab))
	{
		initialize(&a, &tab, size);
		push_swap(&a, &b, tab);
	}
	else
		write(2, "Error\n", 6);
	free(tab);
	// TESTING
	
	//display_stack(a);
	clean_stack(a.first);
	// sort_three(&a, &b);
	
	
	return (0);
}