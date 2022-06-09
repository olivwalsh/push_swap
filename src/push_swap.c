/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:56:14 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/09 19:53:25 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(t_stack *a)
{
	int	size;

	size = stack_size(a);
	
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
		initialize(&a, &tab, size);
	else
	{
		free(tab);
		printf("Error\n");
	}

	// TESTING
	printf("stack a\n");
	display_stack(&a);
	swap(&a, &b, 3);
	printf("stack a\n");
	display_stack(&a);
	push_b(&a, &b);
	printf("stack b\n");
	display_stack(&b);

	return (0);
}