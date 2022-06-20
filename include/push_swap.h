/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:34:09 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/20 12:23:25 by owalsh           ###   ########.fr       */
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
	int				cost;
	int				max;
}				t_number;

int			ft_abs(int x);
void		bubble_sort(int **tab, int size);
int			check_args(int argc, char **argv, int *size);
void		clean_stack(t_number **head);
void		display_stack(t_number *s);
void		display_tab(int *tab, int size);
int			fill_tab(int size, char **argv, int **tab);
void		first_sort(t_number **head_a, t_number **head_b);
int			get_max(t_number *head);
int			get_max_index(t_number *head);
int			get_min(t_number *head);
int			get_min_index(t_number *s);
int			get_stack_size(t_number *head);
void		index_a(t_number *head_a, t_number *head_b);
void		index_b(t_number *head);
void		initialize(t_number **head_a, int **tab, int size);
int			is_sorted(t_number **head);
t_number	*new_number(int num);
void		presort(t_number *a, int *tab, int size, int max);
void		push_a(t_number **a, t_number **b);
void		push_b(t_number **a, t_number **b);
void		push_swap(t_number **a, t_number **b);
void		reverse_rotate(t_number **a, t_number **b, int i);
void		reverse_rotate_s(t_number **head);
void		rotate_s(t_number **head);
void		rotate(t_number **a, t_number **b, int i);
void		sort_five(t_number **head_a, t_number **head_b);
void		sort_three(t_number **a, t_number **b);
void		stack_add_back(t_number **stack, t_number *new);
t_number	*stack_last(t_number *number);
void		swap(t_number **a, t_number **b, int i);
void		swap_s(t_number **head);
void		update_move_cost(t_number *a, t_number *b);

#endif
