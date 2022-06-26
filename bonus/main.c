/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:53:54 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/26 11:32:15 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	move(char *move, t_number **head_a, t_number **head_b)
{
	if (ft_strncmp("pa", move, ft_strlen(move)))
		return (push_a(head_a, head_b));
	else if (ft_strncmp("pb", move, ft_strlen(move)))
		return (push_b(head_a, head_b));
	else if (ft_strncmp("sa", move, ft_strlen(move)))
		return (swap(head_a, head_b, 0));
	else if (ft_strncmp("sb", move, ft_strlen(move)))
		return (swap(head_a, head_b, 1));
	else if (ft_strncmp("ss", move, ft_strlen(move)))
		return (swap(head_a, head_b, 2));
	else if (ft_strncmp("ra", move, ft_strlen(move)))
		return (rotate(head_a, head_b, 0));
	else if (ft_strncmp("rb", move, ft_strlen(move)))
		return (rotate(head_a, head_b, 1));
	else if (ft_strncmp("rr", move, ft_strlen(move)))
		return (rotate(head_a, head_b, 2));
	else if (ft_strncmp("rra", move, ft_strlen(move)))
		return (reverse_rotate(head_a, head_b, 0));
	else if (ft_strncmp("rrb", move, ft_strlen(move)))
		return (reverse_rotate(head_a, head_b, 1));
	else if (ft_strncmp("rrr", move, ft_strlen(move)))
		return (reverse_rotate(head_a, head_b, 2));
	else
		return (0);
}

int	checker(t_number **head_a, t_number **head_b)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		if (!move(instruction, head_a, head_b))
		{
			free(instruction);
			return (0);
		}
		free(instruction);
		instruction = get_next_line(0);
	}
	if (is_sorted(*head_a))
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
