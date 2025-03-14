/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:17:13 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/11 19:17:20 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *a)
{
	t_list	*cur;
	t_list	*prev;

	if (a->size < 2)
		return ;
	cur = a->top;
	while (cur->next->next)
		cur = cur->next;
	prev = cur;
	cur = cur->next;
	prev->next = NULL;
	cur->next = a->top;
	a->top = cur;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	t_list	*cur;
	t_list	*prev;

	if (b->size < 2)
		return ;
	cur = b->top;
	while (cur->next->next)
		cur = cur->next;
	prev = cur;
	cur = cur->next;
	prev->next = NULL;
	cur->next = b->top;
	b->top = cur;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}

int	find_min(t_stack *a)
{
	t_list	*cur;
	int		min;

	if (!a->top)
		return (0);
	cur = a->top;
	min = (int)(long)(cur->content);
	while (cur)
	{
		if ((int)(long)(cur->content) < min)
			min = (int)(long)(cur->content);
		cur = cur->next;
	}
	return (min);
}

int	find_position(t_stack *a, int value)
{
	t_list	*cur;
	int		pos;

	cur = a->top;
	pos = 0;
	while (cur)
	{
		if ((int)(long)(cur->content) == value)
			return (pos);
		pos++;
		cur = cur->next;
	}
	return (-1);
}
