/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:57:42 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/14 12:45:59 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_stack(t_stack *s)
{
	t_number	*ptr;
	t_number	*tmp;

	ptr = s->first;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
	free(ptr);
}
