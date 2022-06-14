/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:57:42 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/14 21:40:48 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_stack(t_number *n)
{
	t_number	*next;
	t_number	*tmp;

	tmp = n;
	while (tmp)
	{
		//printf("curr = %p\t nxt = %p\n", tmp, tmp->next);
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
//	free(ptr);
}
