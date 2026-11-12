/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rr.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mtorfs <mtorfs@student.42belgium.be>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/06 14:37:48 by mtorfs           #+#    #+#              */
/*   Updated: 2026/11/12 17:46:50 by mtorfs          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **a, t_list **b)
{
	t_list	*first;
	t_list	*last;
	int		changed;

	changed = 0;
	if (a && *a && (*a)->next)
	{
		first = *a;
		*a = (*a)->next;
		last = *a;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
		changed = 1;
	}
	if (b && *b && (*b)->next)
	{
		first = *b;
		*b = (*b)->next;
		last = *b;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
		changed = 1;
	}
	if (changed)
		ft_putendl_fd("rr", 1);
}
