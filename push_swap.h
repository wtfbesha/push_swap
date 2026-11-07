/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:37:48 by neric             #+#    #+#             */
/*   Updated: 2026/11/06 14:37:58 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
typedef struct s_stack
{
    t_list *top;
    int size;
}   t_stack;
*/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

void ft_buble_sort(t_list *a, t_list *b);
void ft_block_based_sort(t_list *a, t_list *b);
void ft_merge_sort(t_list *a, t_list *b);
void ft_adaptive_sort(t_list *a, t_list *b, double disorder);

#endif
