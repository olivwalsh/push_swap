/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:53:06 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/24 18:57:51 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# define BUFFER_SIZE 2048

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

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

// FILE parse_args.c
int			check_args(char **argv, int *size);
int			fill_tab(int size, char **argv, int **tab);
// FILE init.c
void		initialize(t_number **head_a, int **tab, int size);
t_moves		*new_moves(void);
t_number	*new_number(int num);
void		stack_add_back(t_number **stack, t_number *new);
t_number	*stack_last(t_number *number);
// FILE bonus_utils.c
char		*get_next_line(int fd);
void		clean_stack(t_number **head);
int			get_max(t_number *head);
int			is_sorted(t_number *head);
// FILE bonus_utils2.c
void		clean_buf(char *buf);
int			has_nl(char *s);
int			ft_strncmp(char *s1, char *s2, int n);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *s);
// FILE bonus_presort.c
void		presort(t_number *a, int *tab, int size, int max);
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

#endif