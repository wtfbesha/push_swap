/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorfs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:38:46 by mtorfs            #+#    #+#             */
/*   Updated: 2026/11/13 14:47:08 by mtorfs           ###   ########.fr       */
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

# define OP_SA 0
# define OP_SB 1
# define OP_SS 2
# define OP_PA 3
# define OP_PB 4
# define OP_RA 5
# define OP_RB 6
# define OP_RR 7
# define OP_RRA 8
# define OP_RRB 9
# define OP_RRR 10

int		parse_args(int argc, char **argv, int *strategy,
			int *bench, int *numbers_start);
int		validate_args(int argc, char **argv, int start,
			int **numbers, int *count);
t_list	*init_stack_a(int *numbers, int count);

void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);

void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);

void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);

void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

void	sort_three(t_list **a);
void	sort_five(t_list **a, t_list **b);

void	sort_simple(t_list **a, t_list **b);
void	ft_merge_sort(t_list **a, t_list **b);
void	sort_medium(t_list **a, t_list **b);

int		is_sorted(t_list *stack);
int		get_max_pos(t_list *stack);
int		index_stack(t_list *stack);

void	ft_adaptive_sort(t_list **a, t_list **b);
double	compute_disorder(t_list *stack);
void	print_benchmark(int strategy, double disorder);

long int	ft_bench_ops(int op_type, int action);

#endif
