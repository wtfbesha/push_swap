/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:37:48 by neric             #+#    #+#             */
/*   Updated: 2026/11/09 14:00:00 by neric            ###   ###.fr            */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra(t_list **a)
{
    t_list  *last;
    t_list  *prev;

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
    ft_putendl_fd("rra", 1);
}