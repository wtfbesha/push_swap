/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:37:48 by neric             #+#    #+#             */
/*   Updated: 2026/11/06 14:37:58 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_max_pos(t_list *stack)
{
	int		max;
	int		pos;
	int		max_pos;

	if (!stack)
		return (-1);
	max = *(int *)stack->content;
	pos = 0;
	max_pos = 0;
	while (stack)
	{
		if (*(int *)stack->content > max)
		{
			max = *(int *)stack->content;
			max_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (max_pos);
}
