/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:34:09 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/24 19:06:14 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define CHUNCK_SIZE 150
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
}			t_moves;

typedef struct s_number
{
	struct s_number	*previous;
	struct s_number	*next;
	int				num;
	int				index;
	int				index_a;
	int				index_b;
	int				cost;
	t_moves			*moves;
	int				max;
}				t_number;

// FILE indexes.c
void		index_a(t_number *a, t_number *b);
void		index_a_to_moves(t_number *a, t_number *b, int min_dif, int size);
void		index_b(t_number *head);
void		reset_indexes(t_number *head);
// FILE init.c
void		initialize(t_number **head_a, int **tab, int size);
t_moves		*new_moves(void);
t_number	*new_number(int num);
void		stack_add_back(t_number **stack, t_number *new);
t_number	*stack_last(t_number *number);
// FILE main.c
void		push_swap(t_number **a, t_number **b);
// FILE move_cost.c
void		first_sort(t_number **head_a, t_number **head_b);
void		optimize_number_moves(t_number *b);
void		update_move_cost(t_number *a, t_number *b);
// FILE basic_moves.c
void		push_a(t_number **a, t_number **b);
void		push_b(t_number **a, t_number **b);
void		swap(t_number **a, t_number **b, int i);
void		swap_s(t_number **head);
// FILE r_moves.c
void		reverse_rotate(t_number **a, t_number **b, int i);
void		reverse_rotate_s(t_number **head);
void		rotate_s(t_number **head);
void		rotate(t_number **a, t_number **b, int i);
// FILE parse_args.c
int			check_args(char **argv, int *size);
int			fill_tab(int size, char **argv, int **tab);
// FILE presort.c
void		presort(t_number *a, int *tab, int size, int max);
// FILE push_swap.c
void		clean_stack(t_number **head);
int			is_sorted(t_number *head);
void		sort_five(t_number **head_a, t_number **head_b);
void		sort_three(t_number **a, t_number **b);
// FILE sort.c
t_number	*cheapest_to_move(t_number *head_b);
void		execute_moves(t_number **a, t_number **b, t_number *to_move);
void		final_sort_step(t_number **head_a, t_number **head_b);
void		sort(t_number **head_a, t_number **head_b);
// FILE sort_big.c
void		sort_big(t_number **a, t_number **b);
// FILE tools.c
int			ft_abs(int x);
int			get_max(t_number *head);
int			get_max_index(t_number *head);
int			get_min_index(t_number *s);
int			get_stack_size(t_number *head);

#endif
