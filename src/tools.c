/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:57:42 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/21 14:52:52 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_number *s)
{
	t_number	*ptr;
	int			min;
	int			i;

	i = 0;
	ptr = s;
	min = ptr->num;
	while (ptr)
	{
		if (ptr->num < min)
			min = ptr->num;
		ptr = ptr->next;
	}
	ptr = s;
	while (ptr)
	{
		if (ptr->num == min)
			return (i);
		i++;
		ptr = ptr->next;
	}
	return (-1);
}

int	get_max_index(t_number *head)
{
	t_number	*ptr;
	int			max;
	int			i;

	i = 0;
	ptr = head;
	max = ptr->num;
	while (ptr)
	{
		if (ptr->num > max)
			max = ptr->num;
		ptr = ptr->next;
	}
	ptr = head;
	while (ptr)
	{
		if (ptr->num == max)
			return (i);
		i++;
		ptr = ptr->next;
	}
	return (-1);
}

int	get_stack_size(t_number *head)
{
	t_number	*ptr;
	int			size;

	size = 0;
	if (!head)
		return (0);
	ptr = head;
	while (ptr)
	{
		ptr = ptr->next;
		size++;
	}
	return (size);
}

int	get_max(t_number *head)
{
	t_number	*ptr;
	int			max;
	int			i;

	i = 0;
	ptr = head;
	max = ptr->num;
	while (ptr)
	{
		if (ptr->num > max)
			max = ptr->num;
		ptr = ptr->next;
	}
	return (max);
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}
