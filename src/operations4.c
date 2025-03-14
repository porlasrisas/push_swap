/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:17:45 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/11 20:17:18 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	final_sweep(t_stack *a)
{
	int	pos;
	int	min;

	min = find_min(a);
	pos = find_position(a, min);
	if (pos < 0)
		return ;
	if (pos <= a->size / 2)
		while (pos-- > 0)
			ra(a);
	else
		while (pos++ < a->size)
			rra(a);
}

void	sort_cluster_three(t_stack *b)
{
	int	first;
	int	second;
	int	third;

	first = (int)(long)(b->top->content);
	second = (int)(long)(b->top->next->content);
	third = (int)(long)(b->top->next->next->content);
	if (first > second && second < third && third > first)
		sb(b);
	else if (first > second && second > third)
	{
		sb(b);
		rrb(b);
	}
	else if (first > second && second < third && third < first)
		rb(b);
	else if (first < second && second > third && third > first)
	{
		sb(b);
		rb(b);
	}
	else if (first < second && second > third && first > third)
		rrb(b);
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

void	sort_three_a(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = (int)(long)(a->top->content);
	second = (int)(long)(a->top->next->content);
	third = (int)(long)(a->top->next->next->content);
	if (first < second && second < third)
		return ;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}
