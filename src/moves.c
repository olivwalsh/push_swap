/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:06:27 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/09 09:15:28 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//pa
void	push_a(t_stack *a, t_stack *b)
{
	t_number	*a_first;
	t_number	*new;

	if (b && b->first)
	{
		new = b->first;
		b->first = b->first->next;
		if (a->first)
		{
			a_first = a->first;
			a->first = new;
			a->first->next = a_first;
		}
		else
		{
			a->first = new;
			a->first->next = NULL;
			a->first->previous = NULL;
		}
	}
}

//pb
void	push_b(t_stack *a, t_stack *b)
{
	t_number	*b_first;
	t_number	*new;

	if (a && a->first)
	{
		new = a->first;
		a->first = a->first->next;
		if (b->first)
		{
			b_first = b->first;
			b->first = new;
			new->next = b_first;
		}
		else
			b->first = new;
			b->first->next = NULL;
			b->first->previous = NULL;
	}
}

// //sa
// void	swap_a()
// {
	
// }

// //sb
// void	swap_b()
// {
	
// }

// //ss
// void	swap_both()
// {
	
// }

// //ra
// void	rotate_a()
// {
	
// }

// //rb
// void	rotate_b()
// {
	
// }

// //rr
// void	rotate_both()
// {
	
// }

// //rra
// void	rotate_reverse_a()
// {
	
// }

// //rrb
// void	rotate_reverse_b()
// {
	
// }

// //rrr
// void	rotate_reverse_both()
// {
	
// }
