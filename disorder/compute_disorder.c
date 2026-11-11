/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:37:48 by neric             #+#    #+#             */
/*   Updated: 2026/11/06 14:37:58 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double compute_disorder(t_list *stack)
{
    t_list *i;
    t_list *j;
    long    mistakes;
    long    total;

    mistakes = 0;
    total = 0;
    i = stack;

    while (i)
    {
        j = i->next;
        while (j)
        {
            total++;
            if (*(int *)i->content > *(int *)j->content)
                mistakes++;
            j = j->next;
        }
        i = i->next;
    }
    if (total == 0)
        return (0.0);
    return ((double)mistakes / (double)total);
}
