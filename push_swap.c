/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:04:02 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/12 18:31:15 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_cost(t_stack *a, t_stack *b, int candidate, int idx)
{
	int	target;

	target = find_target_index(a, candidate);
	return (cost_rotation(b->size, idx) + cost_rotation(a->size, target));
}

int	choose_best_index(t_stack *a, t_stack *b)
{
	t_list	*cur;
	int		idx;
	int		best_idx;
	int		best_cost;
	int		cost;

	if (b->size == 0)
		return (0);
	cur = b->top;
	best_idx = 0;
	idx = best_idx;
	best_cost = INT_MAX;
	while (cur)
	{
		cost = calc_cost(a, b, (int)(long)(cur->content), idx);
		if (cost < best_cost)
		{
			best_cost = cost;
			best_idx = idx;
		}
		idx++;
		cur = cur->next;
	}
	return (best_idx);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (free_stacks(a, b), 0);
	a = init_stack();
	b = init_stack();
	if (!parse_arguments(a, argc, argv) || !check_duplicates(a))
		return (ft_putstr_fd("Error\n", 2), free_stacks(a, b), 1);
	if (is_stack_sorted(a))
		return (free_stacks (a, b), 0);
	if (a->size <= 5)
		sort_small(a, b);
	else
	{
		if (a->size >= 5 && a->size <= 100)
			process_clusters_by_value(a, b, 2);
		else if (a->size >= 100)
			process_clusters_by_value(a, b, 5);
		greedy_insertion_optimized(a, b);
	}
	return (free_stacks(a, b), 0);
}
