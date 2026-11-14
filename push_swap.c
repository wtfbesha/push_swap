/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:37:48 by neric             #+#    #+#             */
/*   Updated: 2026/11/13 13:36:36 by mtorfs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	run_strategy(t_list **a, t_list **b, int strategy)
{
	if (strategy == SIMPLE)
		sort_simple(a, b);
	else if (strategy == MEDIUM)
		sort_medium(a, b);
	else if (strategy == COMPLEX)
		ft_merge_sort(a, b);
	else
		ft_adaptive_sort(a, b);
}

static t_list	*init_stack(int argc, char **argv, int start)
{
	int		params[2];
	int		*numbers;
	t_list	*a;

	params[0] = start;
	params[1] = 0;
	if (!validate_args(argc, argv, params, &numbers))
		return (NULL);
	a = init_stack_a(numbers, params[1]);
	free(numbers);
	return (a);
}

static void	execute_sort(t_list **a, t_list **b, int *params)
{
	double	disorder;

	disorder = 0.0;
	if (params[1])
		disorder = compute_disorder(*a);
	ft_bench_ops(0, -1);
	if (!is_sorted(*a))
		run_strategy(a, b, params[0]);
	if (params[1])
		print_benchmark(params[0], disorder);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		params[3];

	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv, params))
		ft_error_exit();
	a = init_stack(argc, argv, params[2]);
	if (!a)
		ft_error_exit();
	b = NULL;
	execute_sort(&a, &b, params);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
