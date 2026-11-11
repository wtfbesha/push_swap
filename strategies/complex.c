/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:37:48 by neric             #+#    #+#             */
/*   Updated: 2026/11/06 14:37:58 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static int	val(t_list *node)
{
	return (*(int *)node->content);
}

static int	top_sorted(t_list *stack, int n)
{
	int	previous;
	int	i;

	if (n < 1)
		return (1);
	if (!stack)
		return (0);
	previous = val(stack);
	stack = stack->next;
	i = 1;
	while (i < n)
	{
		if (!stack || previous > val(stack))
			return (0);
		previous = val(stack);
		stack = stack->next;
		i++;
	}
	return (1);
}

static t_list	**get_stack(t_list **a, t_list **b, int which)
{
	if (which == 0)
		return (a);
	return (b);
}

static int	top_less(t_list **a, t_list **b, int which)
{
	t_list	**current;
	t_list	**other;

	current = get_stack(a, b, which);
	other = get_stack(a, b, 1 - which);
	if (!*current || !*other)
		return (0);
	return (val(*current) < val(*other));
}
