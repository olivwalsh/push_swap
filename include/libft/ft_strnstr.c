/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:21:16 by owalsh            #+#    #+#             */
/*   Updated: 2022/05/10 11:40:07 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	i;

	if (!big || !little)
		return (NULL);
	b = (char *)big;
	l = (char *)little;
	i = 0;
	if (l[i] == '\0')
		return (b);
	while (l[i])
		i++;
	while (*b && len > 0)
	{
		if (*b == l[0] && !ft_strncmp(b, l, i) && i <= len)
			return (b);
		b++;
		len--;
	}
	return (NULL);
}
