/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:37:48 by neric             #+#    #+#             */
/*   Updated: 2026/11/09 14:00:00 by neric            ###   ###.fr            */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ss(t_list **a, t_list **b)
{
    t_list  *tmp;

    if (a && *a && (*a)->next)
    {
        tmp = (*a)->next;
        (*a)->next = tmp->next;
        tmp->next = *a;
        *a = tmp;
    }
    if (b && *b && (*b)->next)
    {
        tmp = (*b)->next;
        (*b)->next = tmp->next;
        tmp->next = *b;
        *b = tmp;
    }
    ft_putendl_fd("ss", 1);
}