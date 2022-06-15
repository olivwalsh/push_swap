/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:57:42 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/15 17:36:06 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_stack(t_number **head)
{
	t_number	*next;
	t_number	*tmp;

	tmp = head[0];
	while (tmp)
	{
		//printf("curr = %p\t nxt = %p\n", tmp, tmp->next);
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
//	free(ptr);
}

int	is_sorted(t_number *head)
{
	t_number	*tmp;

	tmp = head;
	while (tmp && tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);	
}
