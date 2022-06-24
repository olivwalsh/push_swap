/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:53:54 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/24 18:18:31 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	move(char *move, t_number **head_a, t_number **head_b)
{
	if (ft_strcmp("pa", move))
		push_a(head_a, head_b);
	if (ft_strcmp("pb", move))
		push_b(head_a, head_b);
	if (ft_strcmp("sa", move))
		swap(head_a, head_b, 0);
	if (ft_strcmp("sb", move))
		swap(head_a, head_b, 1);
	if (ft_strcmp("ss", move))
		swap(head_a, head_b, 2);
	if (ft_strcmp("ra", move))
		rotate(head_a, head_b, 0);
	if (ft_strcmp("rb", move))
		rotate(head_a, head_b, 1);
	if (ft_strcmp("rr", move))
		rotate(head_a, head_b, 2);
	if (ft_strcmp("rra", move))
		reverse_rotate(head_a, head_b, 0);
	if (ft_strcmp("rrb", move))
		reverse_rotate(head_a, head_b, 1);
	if (ft_strcmp("rrr", move))
		reverse_rotate(head_a, head_b, 2);	
}

int	checker(t_number **head_a, t_number **head_b)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		move(instruction, head_a, head_b);		
		instruction = get_next_line(0);
	}
	if (is_sorted(*head_a) && !*head_b)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_number	*head_a;
	t_number	*head_b;
	int			*tab;
	int			size;
	
	tab = NULL;
	head_a = NULL;
	if (argc < 2)
		return (0);
	if (check_args(argv, &size) && fill_tab(size, ++argv, &tab))
	{
		initialize(&head_a, &tab, size);
		if (checker(&head_a, &head_b))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		clean_stack(&head_a);
	}
	else
		write(2, "Error\n", 6);
	free(tab);
	return (0);
}