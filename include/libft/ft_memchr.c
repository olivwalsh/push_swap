/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:22:27 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/10 11:05:20 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			*casts;

	casts = (char *)s;
	i = 0;
	if (c > 256)
		c %= 256;
	while (s && i < n)
	{
		if (casts[i] == c)
			return (&casts[i]);
		i++;
	}
	return (NULL);
}
