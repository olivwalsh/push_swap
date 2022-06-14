/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:34:09 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/14 21:48:10 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_number
{
	struct s_number	*previous;
	struct s_number	*next;
	int				num;
	int				index;
	int				index_a;
	int				index_b;
}				t_number;

typedef struct s_stack
{
	t_number	*first;
	int			size;
}			t_stack;

void		bubble_sort(int **tab, int size);
int			check_args(int argc, char **argv, int *size);
void		clean_stack(t_number *n);
void		display_stack(t_stack s);
int			fill_stack(int size, char **argv, int **tab);
void		initialize(t_stack *a, int **tab, int size);
t_number	*new_number(int num);
void		presort(t_stack *a, int *tab, int size);
void		push_a(t_stack *a, t_stack *b);
void		push_b(t_stack *a, t_stack *b);
void		push_swap(t_stack *a, t_stack *b, int *tab);
void		reverse_rotate(t_stack *a, t_stack *b, int i);
void		reverse_rotate_s(t_stack *b);
void		rotate_s(t_stack *b);
void		rotate(t_stack *a, t_stack *b, int i);
void		sort_five(t_stack *a, t_stack *b);
void		sort_three(t_stack *a, t_stack *b);
void		stack_add_back(t_stack **stack, t_number *new);
t_number	*stack_last(t_number *number);
int			stack_size(t_stack *s);
void		swap(t_stack *a, t_stack *b, int i);
void		swap_s(t_stack *b);

#endif
