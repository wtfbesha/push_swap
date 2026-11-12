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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define ADAPTIVE 0
# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3


/**/
void    sa(t_list **a);
void    sb(t_list **b);
void    ss(t_list **a, t_list **b);
/**/
void    pa(t_list **a, t_list **b);
void    pb(t_list **a, t_list **b);
/**/
void    ra(t_list **a);
void    rb(t_list **b);
void    rr(t_list **a, t_list **b);
/**/
void    rra(t_list **a);
void    rrb(t_list **b);
void    rrr(t_list **a, t_list **b);


void	sort_three(t_list **a);
void	sort_five(t_list **a, t_list **b);
void	sort_simple(t_list **a, t_list **b);
void	ft_merge_sort(t_list **a, t_list **b);
void 	ft_adaptive_sort(t_list **a, t_list **b);

int		parse_args(int argc, char **argv, int *strategy,
			int *bench, int *numbers_start);
int		validate_args(int argc, char **argv, int start,
			int **numbers, int *count);
t_list	*init_stack_a(int *numbers, int count);

double compute_disorder(t_list *stack);

#endif
