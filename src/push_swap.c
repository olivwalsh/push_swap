/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:56:14 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/07 18:41:48 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack 	a;
	t_stack 	b;

	int		*tab;
	int		size;
	t_number	*ptr;
	
	(void)b;
	ft_bzero(&a, sizeof(t_stack));
	if (check_args(argc, argv, &size) && fill_stack(size, ++argv, &tab))
		initialize(&a, &tab, size);
	else
	{
		free(tab);
		printf("Error\n");
	}
	ptr = a.first;
	while (ptr)
	{
		printf("ptr->num = %d\n", ptr->num);
		ptr = ptr->next;
	}
	return (0);
}