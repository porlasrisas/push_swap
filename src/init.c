/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:15:51 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/12 17:55:41 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_stack_sorted(t_stack *a)
{
	t_list	*current;

	if (!a->top || !a->top->next)
		return (1);
	current = a->top;
	while (current->next)
	{
		if ((int)(long)(current->content) > (int)(long)(current->next->content))
			return (0);
		current = current->next;
	}
	return (1);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

static void	push_min_until_three(t_stack *a, t_stack *b)
{
	int	min;
	int	pos;

	while (a->size > 3)
	{
		min = find_min(a);
		pos = find_position(a, min);
		if (pos <= a->size / 2)
			while (pos-- > 0)
				ra(a);
		else
			while (pos++ < a->size)
				rra(a);
		pb(a, b);
	}
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (!is_sorted(a))
			sa(a);
	}
	else if (a->size == 3)
		sort_three_a(a);
	else if (a->size <= 5)
	{
		push_min_until_three(a, b);
		sort_three_a(a);
		while (b->size > 0)
			pa(a, b);
		final_sweep(a);
	}
}

void	free_stacks(t_stack *a, t_stack *b)
{
	if (a)
	{
		ft_lstclear(&a->top, dummy_del);
		free(a);
	}
	if (b)
	{
		ft_lstclear(&b->top, dummy_del);
		free(b);
	}
}
