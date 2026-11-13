/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_complex_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 15:00:00 by neric             #+#    #+#             */
/*   Updated: 2026/11/13 15:00:00 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	complex_val(t_list *node)
{
	return (*(int *)node->content);
}

t_list	**complex_stk(t_list **a, t_list **b, int w)
{
	if (w == 0)
		return (a);
	return (b);
}

void	complex_mv(t_list **a, t_list **b, int from)
{
	if (from == 0)
		pb(a, b);
	else
		pa(a, b);
}
