/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 11:08:13 by lesantos          #+#    #+#             */
/*   Updated: 2021/09/20 13:01:22 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	fill_digits(char *dest, int n, int len, int minus_sign)
{
	while (len)
	{
		dest[len - 1 + minus_sign] = n % 10 + '0';
		n /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*r;
	int		minus_sign;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	minus_sign = 0;
	if (n < 0)
	{
		n *= -1;
		minus_sign = 1;
	}
	len = count_digits(n);
	r = malloc(len + minus_sign + 1);
	if (!r)
		return (NULL);
	r[len + minus_sign] = '\0';
	if (minus_sign)
		r[0] = '-';
	fill_digits(r, n, len, minus_sign);
	return (r);
}
