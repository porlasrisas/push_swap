/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:31:05 by guigonza          #+#    #+#             */
/*   Updated: 2025/03/12 13:59:03 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	validate_range(const char *p, int sign)
{
	long	num;

	num = ft_atoi(p) * sign;
	if (num > INT_MAX)
		return (0);
	if (num < INT_MIN)
		return (0);
	return (1);
}

static int	process_sign(const char *s, int *i)
{
	int	sign;

	sign = 1;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
		if (!s[*i])
			return (0);
	}
	return (sign);
}

static int	count_digits(const char *s, int i, int *dcount)
{
	*dcount = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		*dcount = *dcount + 1;
		i++;
	}
	return (1);
}

int	is_valid_integer(const char *s)
{
	int			i;
	int			sign;
	int			dcount;
	const char	*cmp;

	i = 0;
	if (!s || s[0] == '\0')
		return (0);
	sign = process_sign(s, &i);
	if (sign == 0)
		return (0);
	if (!count_digits(s, i, &dcount))
		return (0);
	if (dcount == 10)
	{
		if (s[0] == '+' || s[0] == '-')
			cmp = s + 1;
		else
			cmp = s;
		if (!validate_range(cmp, sign))
			return (0);
	}
	return (1);
}
