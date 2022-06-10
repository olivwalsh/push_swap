/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:34:09 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/10 11:25:44 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>

typedef struct s_number
{
	struct s_number	*previous;
	struct s_number	*next;
	int				num;
	int				from_index;
	int				to_index;
}				t_number;

typedef struct s_stack
{
	t_number *first;
	int		size;	
}			t_stack;

void		initialize(t_stack *a, int **tab, int size);
int			check_args(int argc, char **argv, int *size);
int			fill_stack(int size, char **argv, int **tab);
t_number	*new_number(int num);
void		stack_add_back(t_stack **stack, t_number *new);
t_number	*stack_last(t_number *number);
void		push_a(t_stack *a, t_stack *b);
void		push_b(t_stack *a, t_stack *b);
void		display_stack(t_stack *s);
void		swap_s(t_stack *b);
void		swap(t_stack *a, t_stack *b, int i);
void		rotate_s(t_stack *b);
void		rotate(t_stack *a, t_stack *b, int i);
void		reverse_rotate_s(t_stack *b);
void		rotate_reverse(t_stack *a, t_stack *b, int i);
int			stack_size(t_stack *s);
void		push_swap(t_stack *a, t_stack *b);
void		sort_three(t_stack *a, t_stack *b);

#endif
