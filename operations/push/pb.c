/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   pb.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mtorfs <mtorfs@student.42belgium.be>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/06 14:37:48 by mtorfs           #+#    #+#              */
/*   Updated: 2026/11/12 17:46:38 by mtorfs          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

    if (!a || !*a)
        return ;
    tmp = *a;
    *a = (*a)->next;
    tmp->next = *b;
    *b = tmp;
    ft_bench_ops(OP_PB, 1);
    ft_putendl_fd("pb", 1);
}