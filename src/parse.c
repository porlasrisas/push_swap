/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:52:10 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/12 17:55:58 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	parse_tokens(t_stack *a, char **toks)
{
	int		i;
	long	num;
	t_list	*node;

	i = 0;
	while (toks[i])
	{
		if (toks[i][0] == '\0')
		{
			i = i + 1;
			continue ;
		}
		if (!is_valid_integer(toks[i]))
			return (0);
		num = ft_atoi(toks[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		node = ft_lstnew((void *)(long)num);
		if (!node)
			return (0);
		ft_lstadd_back(&a->top, node);
		a->size = a->size + 1;
		i = i + 1;
	}
	return (1);
}

int	parse_arguments_split(t_stack *a, char *arg)
{
	char	**toks;
	int		ret;

	if (!arg || arg[0] == '\0' || is_only_spaces(arg))
		return (0);
	toks = ft_split(arg, ' ');
	if (!toks)
		return (0);
	ret = parse_tokens(a, toks);
	free_split(toks);
	return (ret);
}

int	process_argument(t_stack *a, char *arg)
{
	int		valid;
	long	num;
	t_list	*node;

	if (!arg || arg[0] == '\0')
		return (0);
	if (ft_strchr(arg, ' ') != NULL)
		return (parse_arguments_split(a, arg));
	valid = is_valid_integer(arg);
	if (valid == 0)
		return (0);
	num = ft_atoi(arg);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	node = ft_lstnew((void *)(long)ft_atoi(arg));
	if (!node)
		return (0);
	ft_lstadd_back(&a->top, node);
	a->size = a->size + 1;
	return (1);
}

int	parse_arguments_multi(t_stack *a, int argc, char **argv)
{
	int	i;
	int	ret;

	i = 1;
	while (i < argc)
	{
		ret = process_argument(a, argv[i]);
		if (ret == 0)
			return (0);
		i = i + 1;
	}
	return (1);
}

void	dummy_del(void *content)
{
	(void)content;
}
