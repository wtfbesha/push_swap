/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:37:48 by neric             #+#    #+#             */
/*   Updated: 2026/11/06 14:37:58 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_adaptive_sort(t_list **a, t_list **b)
{
	int		size;
	double	disorder;

	if (!a || !b || !*a)
		return ;
	size = ft_lstsize(*a);
	if (size <= 1)
		return ;
	if (size <= 5)
	{
		if (size <= 3)
			sort_three(a);
		else
			sort_five(a, b);
		return ;
	}
	disorder = compute_disorder(*a);
	// if (disorder < 0.2)
	// 	sort_simple(a, b);
	// else if (disorder < 0.5)
	// 	sort_medium(a, b);
	// else
	// 	ft_merge_sort(a, b);

	// if (disorder < 0.2)
    // 	sort_simple(a, b);
	// else
	// 	sort_medium(a, b);


	// if (disorder < 0.2)
	// 	sort_simple(a, b);
	// else if (size < 2000)
	// 	sort_medium(a, b);
	// else
	// 	ft_merge_sort(a, b);

	if (disorder < 0.2)
		sort_simple(a, b);
	else if (disorder < 0.5)
		sort_medium(a, b);
	else
		ft_merge_sort(a, b);
}