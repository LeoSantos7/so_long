/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:31:25 by lesantos          #+#    #+#             */
/*   Updated: 2021/09/14 11:02:42 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastelem;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	lastelem = ft_lstlast(*lst);
	lastelem->next = new;
}
