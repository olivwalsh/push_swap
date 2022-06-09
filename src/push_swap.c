/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:56:14 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/09 09:14:54 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
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
	printf("STACK A:\n");
	display_stack(&a);
	printf("STACK B:\n");
	display_stack(&b);
	
	printf("push b\n");
	push_b(&a, &b);
	push_b(&a, &b);
	
	printf("STACK A:\n");
	display_stack(&a);
	printf("STACK B:\n");
	display_stack(&b);

	printf("push a\n");
	push_a(&a, &b);

	printf("STACK A:\n");
	display_stack(&a);
	printf("STACK B:\n");
	display_stack(&b);
	return (0);
}