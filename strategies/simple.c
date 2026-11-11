/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorfs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 18:39:29 by mtorfs            #+#    #+#             */
/*   Updated: 2026/11/06 18:39:48 by mtorfs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_min_pos(t_list *a)
{
	int		min;
	int		min_pos;
	int		pos;
	t_list	*current;

	min = *(int *)a->content;
	min_pos = 0;
	pos = 0;
	current = a;
	while (current)
	{
		if (*(int *)current->content < min)
		{
			min = *(int *)current->content;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

void	sort_three(t_list **a)
{
	int	first;
	int	second;
	int	third;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	first = *(int *)(*a)->content;
	second = *(int *)(*a)->next->content;
	third = *(int *)(*a)->next->next->content;
	if (first > second && first > third)
		ra(a);
	else if (second > first && second > third)
		rra(a);
	if (*(int *)(*a)->content > *(int *)(*a)->next->content)
		sa(a);
}

static void	push_min_to_b(t_list **a, t_list **b)
{
	int	size;
	int	pos;

	size = ft_lstsize(*a);
	pos = get_min_pos(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(a);
	}
	pb(a, b);
}

void	sort_five(t_list **a, t_list **b)
{
	if (!a || !b || !*a)
		return ;
	while (ft_lstsize(*a) > 3)
		push_min_to_b(a, b);
	sort_three(a);
	while (*b)
		pa(a, b);
}

void	sort_simple(t_list **a, t_list **b)
{
	if (!a || !b || !*a)
		return ;
	if (ft_lstsize(*a) <= 3)
		sort_three(a);
	else if (ft_lstsize(*a) <= 5)
		sort_five(a, b);
	else
	{
		while (ft_lstsize(*a) > 3)
			push_min_to_b(a, b);
		sort_three(a);
		while (*b)
			pa(a, b);
	}
}
