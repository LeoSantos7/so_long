/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:12:38 by lesantos          #+#    #+#             */
/*   Updated: 2022/01/23 22:42:04 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(unsigned long n, t_flags *flags)
{
	int	print;

	if (!n)
	{
		print = 0;
		if (flags->width > NULL_PTR_LENGTH)
			print += print_char_count(' ', flags->width - NULL_PTR_LENGTH);
		print += write(1, NULL_PTR_PRINT, NULL_PTR_LENGTH);
		return (print);
	}
	return (print_hex(n, flags));
}
