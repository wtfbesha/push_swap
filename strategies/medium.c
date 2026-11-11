/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:37:48 by neric             #+#    #+#             */
/*   Updated: 2026/11/06 14:37:58 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_window(t_list **a, t_list **b, int n)
{
	int	pushed;
	int	range;

	pushed = 0;
	range = n * 3 / 100 + 14;
	while (*a)
	{
		if (*(int *)(*a)->content <= pushed)
		{
			pb(a, b);
			rb(b);
			pushed++;
		}
		else if (*(int *)(*a)->content <= pushed + range)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
	}
}

static void	push_max_to_a(t_list **a, t_list **b)
{
	int	size;
	int	pos;

	size = ft_lstsize(*b);
	pos = get_max_pos(*b);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(b);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(b);
	}
	pa(a, b);
}

void	sort_medium(t_list **a, t_list **b)
{
	if (!a || !b || !*a || is_sorted(*a))
		return ;
	if (ft_lstsize(*a) <= 5)
	{
		sort_simple(a, b);
		return ;
	}
	if (!index_stack(*a))
		return ;
	push_window(a, b, ft_lstsize(*a));
	while (*b)
		push_max_to_a(a, b);
}