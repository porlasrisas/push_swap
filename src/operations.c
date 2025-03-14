/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:16:49 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/11 20:33:52 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_stack(t_stack *s)
{
	t_list	*first;
	t_list	*second;
	int		tmp;

	if (s->size < 2)
		return ;
	first = s->top;
	second = first->next;
	tmp = (int)(long)(first->content);
	first->content = second->content;
	second->content = (void *)(long)tmp;
}

void	sa(t_stack *a)
{
	swap_stack(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	swap_stack(b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
	ft_printf("ss\n");
}
