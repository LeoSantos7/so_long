/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 15:52:42 by lesantos          #+#    #+#             */
/*   Updated: 2021/09/20 14:26:13 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_divisor(int nb);

void	ft_putnbr_fd(int n, int fd)
{
	int	divisor;
	int	digit;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	divisor = get_divisor(n);
	while (divisor > 0)
	{
		digit = (n / divisor) + '0';
		write(fd, &digit, 1);
		n %= divisor;
		divisor /= 10;
	}
}

int	get_divisor(int n)
{
	int	divisor;

	divisor = 1;
	while (n >= 10)
	{
		n /= 10;
		divisor *= 10;
	}
	return (divisor);
}
