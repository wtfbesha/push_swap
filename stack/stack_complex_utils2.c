/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_complex_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 15:00:00 by neric             #+#    #+#             */
/*   Updated: 2026/11/13 15:00:00 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complex_rot(t_list **a, t_list **b, int w)
{
	if (w == 0)
		ra(a);
	else
		rb(b);
}

void	complex_rrot(t_list **a, t_list **b, int w)
{
	if (w == 0)
		rra(a);
	else
		rrb(b);
}

void	complex_swp(t_list **a, t_list **b, int w)
{
	if (w == 0)
		sa(a);
	else
		sb(b);
}

void	complex_move_chunks(t_list **a, t_list **b, int w, int left)
{
	while (left > 0)
	{
		complex_mv(a, b, w);
		left--;
	}
}
