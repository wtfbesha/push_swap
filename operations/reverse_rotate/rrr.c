/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rrr.c                                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mtorfs <mtorfs@student.42belgium.be>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/06 14:37:48 by mtorfs           #+#    #+#              */
/*   Updated: 2026/11/12 17:46:43 by mtorfs          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_list **a, t_list **b)
{
	t_list	*last;
	t_list	*before_last;
	int		changed;

	changed = 0;
	if (a && *a && (*a)->next)
	{
		before_last = *a;
		while (before_last->next->next)
			before_last = before_last->next;
		last = before_last->next;
		before_last->next = NULL;
		last->next = *a;
		*a = last;
		changed = 1;
	}
	if (b && *b && (*b)->next)
	{
		before_last = *b;
		while (before_last->next->next)
			before_last = before_last->next;
		last = before_last->next;
		before_last->next = NULL;
		last->next = *b;
		*b = last;
		changed = 1;
	}
	if (changed)
		ft_putendl_fd("rrr", 1);
}
