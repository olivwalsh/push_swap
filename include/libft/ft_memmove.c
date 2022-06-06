/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 00:48:28 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/10 11:11:58 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	if (!dest || !src)
		return (NULL);
	d = (char *)dest;
	s = (const char *)src;
	i = n;
	if (d < s)
		d = ft_memcpy(dest, src, n);
	else
	{
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	return (d);
}
