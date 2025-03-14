/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:26:46 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/12 13:46:45 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_cluster_sizes_recursive(int total_size, int *sizes, int *index)
{
	if (total_size <= 5)
	{
		sizes[*index] = total_size;
		(*index)++;
		return ;
	}
	sizes[*index] = total_size / 2;
	(*index)++;
	get_cluster_sizes_recursive(total_size - (total_size / 2),
		sizes, index);
}

int	*get_cluster_sizes(int total_size)
{
	int	*sizes;
	int	index;

	sizes = malloc((total_size + 1) * sizeof(int));
	if (!sizes)
		return (NULL);
	index = 0;
	get_cluster_sizes_recursive(total_size, sizes, &index);
	sizes[index] = 0;
	return (sizes);
}

int	check_duplicates(t_stack *stack)
{
	t_list	*cur;
	t_list	*runner;

	cur = stack->top;
	while (cur)
	{
		runner = cur->next;
		while (runner)
		{
			if ((int)(long)(cur->content) == (int)(long)(runner->content))
				return (0);
			runner = runner->next;
		}
		cur = cur->next;
	}
	return (1);
}

char	*normalize_zero(char *s)
{
	int			i;
	const char	*ptr;

	i = 0;
	ptr = s;
	while (ptr[i] == '0' && ptr[i + 1] != '\0')
	{
		i = i + 1;
	}
	return ((char *)(ptr + i));
}

int	is_sorted(t_stack *stack)
{
	t_list	*cur;

	if (!stack->top)
		return (1);
	cur = stack->top;
	while (cur->next)
	{
		if ((int)(long)(cur->content) > (int)(long)(cur->next->content))
			return (0);
		cur = cur->next;
	}
	return (1);
}
