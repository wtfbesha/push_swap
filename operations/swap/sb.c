/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sb.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mtorfs <mtorfs@student.42belgium.be>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/06 14:37:48 by mtorfs           #+#    #+#              */
/*   Updated: 2026/11/12 17:46:56 by mtorfs          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list **b)
{
	t_list	*first;
	t_list	*second;

    if (!b || !*b || !(*b)->next)
        return ;
    first = *b;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *b = second;
    ft_bench_ops(OP_SB, 1);
    ft_putendl_fd("sb", 1);
}
