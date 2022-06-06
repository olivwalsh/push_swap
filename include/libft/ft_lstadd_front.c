/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:25:39 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/10 11:04:39 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst)
	{
		temp = *lst;
		*lst = new;
		new->next = temp;
	}
	else
	{
		new->next = 0;
		*lst = new;
	}
}
