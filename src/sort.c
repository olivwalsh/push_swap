/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:30:33 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/20 13:54:50 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_number	*cheapest_to_move(t_number *head_b)
// {

// }

// void	sort(t_number **head_a, t_number **head_b)
// {
// 	t_number	*b;

// 	b = head_a;
// 	while (!is_sorted(head_a))
// 	{
// 		update_move_cost(*head_a, head_b);
// 		while (b)
// 		{
			
// 		}
// 	}
	
// }


/*
find moves for each element

int ra (3)
int rb (2)
int rra (0)
int rrb (0)

optimize moves by doing rr for ra-rb
						rrr for rra rrb

int rr 		(2) 
int rrr     (0)

count move cost again

int ra (1)
int rb (0)
int rra (0)
int rrb (0)
int rr  (2)
int rrr (0)

while (rr--)
	move_rr(a, b);
while (rrr-)
	move_rrr(a ,b);
while (ra--)
	move_r(a)
while (rb--)
	move_r(b);

*/