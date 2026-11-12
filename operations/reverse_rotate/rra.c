/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rra.c                                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mtorfs <mtorfs@student.42belgium.be>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/06 14:37:48 by mtorfs           #+#    #+#              */
/*   Updated: 2026/11/12 17:46:39 by mtorfs          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **a)
{
	t_list	*last;
	t_list	*prev;

    if (!a || !*a || !(*a)->next)
        return ;
    prev = NULL;
    last = *a;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *a;
    *a = last;
    ft_bench_ops(OP_RRA, 1);
    ft_putendl_fd("rra", 1);
}