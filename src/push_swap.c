/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:56:14 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/06 16:29:19 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	stack *a;
	stack *b;
	
	if (check_args(argc, argv))
	{
		initialize(a, b);
	}
}
