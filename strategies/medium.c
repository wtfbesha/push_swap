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

#include "push_swap.h"

static int	get_block_size(int size)
{
	int	block_size;

	block_size = 1;
	while (block_size * block_size < size)
		block_size++;
	return (block_size);
}

static void	push_chunk(t_list **a, t_list **b, int low, int high)
{
	int	size;
	int	i;
	int	rank;

	size = ft_lstsize(*a);
	i = 0;
	while (i < size)
	{
		rank = *(int *)(*a)->content;
		if (rank >= low && rank <= high)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

static void	restore_chunk(t_list **a, t_list **b)
{
	int	size;
	int	pos;

	while (*b)
	{
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
}

void	sort_medium(t_list **a, t_list **b)
{
	int	size;
	int	block_size;
	int	high;
	int	low;

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
	block_size = get_block_size(size);
	high = size - 1;
	while (high >= 0)
	{
		low = high - block_size + 1;
		if (low < 0)
			low = 0;
		push_chunk(a, b, low, high);
		restore_chunk(a, b);
		high = low - 1;
	}
}
