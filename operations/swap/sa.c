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

void    sa(t_list **a)
{
    t_list  *first;
    t_list  *second;

    if (!a || !*a || !(*a)->next)
        return ;
    first = *a;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *a = second;
    ft_putendl_fd("sa", 1);
}