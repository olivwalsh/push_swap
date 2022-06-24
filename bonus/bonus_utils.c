/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalsh <owalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:01:42 by owalsh            #+#    #+#             */
/*   Updated: 2022/06/24 17:34:16 by owalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	int				ret;
	char			*line;

	if ((fd < 0 || fd > 1024) || BUFFER_SIZE <= 0)
		return (NULL);
	ret = 1;
	line = NULL;
	line = ft_strjoin(line, buf);
	while (ret && !has_nl(line))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
		{
			free(line);
			return (NULL);
		}
		if (ret)
		{
			buf[ret] = '\0';
			line = ft_strjoin(line, buf);
		}
	}
	clean_buf(buf);
	return (line);
}

void	clean_stack(t_number **head)
{
	t_number	*next;
	t_number	*tmp;

	tmp = head[0];
	while (tmp && tmp->next)
	{
		next = tmp->next;
		free(tmp->moves);
		free(tmp);
		tmp = next;
	}
	free(tmp->moves);
	free(tmp);
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
