/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorfs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 18:39:29 by mtorfs            #+#    #+#             */
/*   Updated: 2026/11/06 18:39:48 by mtorfs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int stack_size(t_stack *stack)
{
    int size;

    size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return (size);
}
void    bubble_sort(t_stack **a)
{
    int     i;
    int     j;
    int     size;

    size = stack_size(*a);
    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if ((*a)->value > (*a)->next->value)
                sa(a);
            ra(a);
            j++;
        }
        j = 0;
        while (j < size - i - 1)
        {
            rra(a);
            j++;
        }
        i++;
    }
}
