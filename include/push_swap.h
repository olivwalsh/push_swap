/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:34:09 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/07 18:31:18 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdio.h>

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

void	initialize(t_stack *a, int **tab, int size);
int		check_args(int argc, char **argv, int *size);
int		fill_stack(int size, char **argv, int **tab);


#endif
