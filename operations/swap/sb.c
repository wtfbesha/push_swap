/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:37:48 by neric             #+#    #+#             */
/*   Updated: 2026/11/09 14:00:00 by neric            ###   ###.fr            */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sb(t_list **b)
{
    t_list  *first;
    t_list  *second;

    if (!b || !*b || !(*b)->next)
        return ;
    first = *b;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *b = second;
    ft_putendl_fd("sb", 1);
}