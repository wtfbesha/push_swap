/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   init_stack.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mtorfs <mtorfs@student.42belgium.be>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/06 14:37:48 by mtorfs           #+#    #+#              */
/*   Updated: 2026/11/12 17:47:18 by mtorfs          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_lstnew_int(int value)
{
	int		*content;
	t_list	*node;

	content = malloc(sizeof(int));
	if (!content)
		return (NULL);
	*content = value;
	node = ft_lstnew(content);
	if (!node)
	{
		free(content);
		return (NULL);
	}
	return (node);
}

t_list	*init_stack_a(int *numbers, int count)
{
	t_list	*a;
	t_list	*new_node;
	int		i;

	a = NULL;
	i = 0;
	while (i < count)
	{
		new_node = ft_lstnew_int(numbers[i]);
		if (!new_node)
		{
			ft_lstclear(&a, free);
			return (NULL);
		}
		ft_lstadd_back(&a, new_node);
		i++;
	}
	return (a);
}
