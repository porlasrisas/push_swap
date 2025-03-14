/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:15:57 by guigonza          #+#    #+#             */
/*   Updated: 2025/01/09 17:30:48 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putchar_fd_p(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putnbr_fd_p(int n, int fd)
{
	long	copy;
	int		count;

	count = 0;
	copy = n;
	if (copy < 0)
	{
		count += ft_putchar_fd_p('-', fd);
		copy = -copy;
	}
	if (copy > 9)
		count += ft_putnbr_fd_p(copy / 10, fd);
	count += ft_putchar_fd_p((copy % 10) + '0', fd);
	return (count);
}

int	ft_putstr_fd_p(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		return (ft_putstr_fd_p("(null)", fd));
	}
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_hex(unsigned long n, int uppercase)
{
	char	*hex;
	int		count;

	count = 0;
	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_putnbr_hex(n / 16, uppercase);
	count += ft_putchar_fd_p(hex[n % 16], 1);
	return (count);
}
