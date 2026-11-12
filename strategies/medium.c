/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:37:48 by neric             #+#    #+#             */
/*   Updated: 2026/11/12 10:00:00 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

include "push_swap.h"

static int	get_block_size(int size)
{
	if (size <= 100)
		return (size / 5 + 1);
	return (size / 11 + 1);
}

static void	push_blocks(t_list **a, t_list **b, int size)
{
	int	pushed;
	int	block_size;
	int	rank;

	pushed = 0;
	block_size = get_block_size(size);
	while (*a)
	{
		rank = *(int *)(*a)->content;
		if (rank <= pushed)
		{
			pb(a, b);
			rb(b);
			pushed++;
		}
		else if (rank <= pushed + block_size)
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
	if (pos < 0)
		return ;
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
	int	size;

	if (!a || !b || !*a || is_sorted(*a))
		return ;
	size = ft_lstsize(*a);
	if (size <= 5)
	{
		sort_simple(a, b);
		return ;
	}
	if (!index_stack(*a))
		return ;
	push_blocks(a, b, size);
	while (*b)
		push_max_to_a(a, b);
}
