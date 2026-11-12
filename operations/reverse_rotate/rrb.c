/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rrb.c                                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mtorfs <marvin@42.fr>                     #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/06 14:37:48 by mtorfs           #+#    #+#              */
/*   Updated: 2026/11/12 21:53:46 by mtorfs          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_list **b)
{
	t_list	*last;
	t_list	*prev;

	if (!b || !*b || !(*b)->next)
		return ;
	prev = NULL;
	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
	ft_bench_ops(OP_RRB, 1);
	ft_putendl_fd("rrb", 1);
}
