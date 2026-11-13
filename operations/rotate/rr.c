/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorfs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:37:48 by mtorfs           #+#    #+#             */
/*   Updated: 2026/11/12 21:53:57 by mtorfs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_single_stack(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	return (1);
}

void	rr(t_list **a, t_list **b)
{
	int	changed_a;
	int	changed_b;

	changed_a = rotate_single_stack(a);
	changed_b = rotate_single_stack(b);
	if (changed_a || changed_b)
	{
		ft_bench_ops(OP_RR, 1);
		ft_putendl_fd("rr", 1);
	}
}
