/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_medium_utils.c                               :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: mtorfs <mtorfs@student.42belgium.be>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/06 14:37:48 by mtorfs           #+#    #+#              */
/*   Updated: 2026/11/12 18:10:42 by mtorfs           ###   ########.fr       */
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
	int	max;
	int	pos;
	int	max_pos;

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

static void	apply_stack_ranks(t_list *stack, int *values, int size)
{
	t_list	*current;
	int		i;
	int		j;
	int		rank;

	current = stack;
	i = 0;
	while (current)
	{
		rank = 0;
		j = 0;
		while (j < size)
		{
			if (values[i] > values[j])
				rank++;
			j++;
		}
		*(int *)current->content = rank;
		current = current->next;
		i++;
	}
}

int	index_stack(t_list *stack)
{
	t_list	*current;
	int		*values;
	int		size;
	int		i;

	size = ft_lstsize(stack);
	if (size <= 0)
		return (0);
	values = malloc(sizeof(int) * size);
	if (!values)
		return (0);
	current = stack;
	i = 0;
	while (current)
	{
		values[i++] = *(int *)current->content;
		current = current->next;
	}
	apply_stack_ranks(stack, values, size);
	free(values);
	return (1);
}
