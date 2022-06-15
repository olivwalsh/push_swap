/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 21:46:35 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/15 12:21:07 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(t_number *s)
{
	t_number	*ptr;

	ptr = s;
	while (ptr)
	{
		printf("ptr->num = %d ptr->index = %d\n", ptr->num, ptr->index);
		// printf("curr = %p\t nxt = %p\n", ptr, ptr->next);
		ptr = ptr->next;
	}
}