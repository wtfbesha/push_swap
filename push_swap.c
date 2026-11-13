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

static void	ft_error_exit(int *numbers)
{
	if (numbers)
		free(numbers);
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

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		strategy;
	int		bench;
	int		start;
	int		count;
	int		*numbers;
	double	disorder;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	if (!parse_args(argc, argv, &strategy, &bench, &start))
		ft_error_exit(NULL);
	if (!validate_args(argc, argv, start, &numbers, &count))
		ft_error_exit(NULL);
	a = init_stack_a(numbers, count);
	free(numbers);
	if (!a)
		ft_error_exit(NULL);
	disorder = 0.0;
	if (bench)
		disorder = compute_disorder(a);
	ft_bench_ops(0, -1);
	if (!is_sorted(a))
		run_strategy(&a, &b, strategy);
	if (bench)
		print_benchmark(strategy, disorder);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
