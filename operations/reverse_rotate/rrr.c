/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rrr.c                                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mtorfs <marvin@42.fr>                     #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/06 14:37:48 by mtorfs           #+#    #+#              */
/*   Updated: 2026/11/12 21:53:48 by mtorfs          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate_single_stack(t_list **stack)
{
	t_list	*last;
	t_list	*before_last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	before_last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

void	rrr(t_list **a, t_list **b)
{
	int	changed_a;
	int	changed_b;

	changed_a = reverse_rotate_single_stack(a);
	changed_b = reverse_rotate_single_stack(b);
	if (changed_a || changed_b)
	{
		ft_bench_ops(OP_RRR, 1);
		ft_putendl_fd("rrr", 1);
	}
}
