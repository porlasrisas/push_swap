/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:25:51 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/12 12:55:35 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_into_clusters_recursive(t_stack *a, t_stack *b, int *sizes,
		int index)
{
	int	i;

	if (sizes[index] == 0)
		return ;
	i = 0;
	while (i < sizes[index])
	{
		pb(a, b);
		rb(b);
		i++;
	}
	divide_into_clusters_recursive(a, b, sizes, index + 1);
}

void	sort_cluster_recursive(t_stack *b, int cluster_size)
{
	if (cluster_size <= 1 || is_stack_sorted(b))
		return ;
	if (cluster_size == 2)
	{
		if ((int)(long)(b->top->content) < (int)(long)(b->top->next->content))
			sb(b);
		return ;
	}
	if (cluster_size == 3)
	{
		sort_cluster_three(b);
		return ;
	}
	sort_cluster_recursive(b, cluster_size / 2);
	sort_cluster_recursive(b, cluster_size - (cluster_size / 2));
}

void	sort_all_clusters(t_stack *a, t_stack *b, int *sizes)
{
	int	i;
	int	cluster_size;

	i = 0;
	while (sizes[i] > 0)
	{
		cluster_size = sizes[i];
		while (cluster_size-- > 0)
			pa(a, b);
		final_sweep(a);
		i++;
	}
}

int	is_only_spaces(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != '\v'
			&& s[i] != '\f' && s[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}

int	parse_arguments(t_stack *a, int argc, char **argv)
{
	int	ret;

	if (argc == 2)
	{
		if (argv[1][0] == '\0' || is_only_spaces(argv[1]))
			return (0);
		if (ft_strchr(argv[1], ' ') != NULL)
			ret = parse_arguments_split(a, argv[1]);
		else
			ret = parse_arguments_multi(a, argc, argv);
		return (ret);
	}
	return (parse_arguments_multi(a, argc, argv));
}
