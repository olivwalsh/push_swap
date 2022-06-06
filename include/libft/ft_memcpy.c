/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:37:23 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/10 11:05:53 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*cast_src;
	char		*cast_dest;
	size_t		i;

	cast_dest = dest;
	cast_src = src;
	i = 0;
	while (src && dest && i < n)
	{
		cast_dest[i] = cast_src[i];
		i++;
	}
	return (dest);
}
