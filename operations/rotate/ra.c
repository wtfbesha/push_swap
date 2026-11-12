/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ra.c                                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mtorfs <mtorfs@student.42belgium.be>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/06 14:37:48 by mtorfs           #+#    #+#              */
/*   Updated: 2026/11/12 17:46:45 by mtorfs          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a)
{
	t_list	*first;
	t_list	*last;

    if (!a || !*a || !(*a)->next)
        return ;
    first = *a;
    *a = first->next;
    first->next = NULL;
    last = *a;
    while (last->next)
        last = last->next;
    last->next = first;
    ft_bench_ops(OP_RA, 1);
    ft_putendl_fd("ra", 1);
}