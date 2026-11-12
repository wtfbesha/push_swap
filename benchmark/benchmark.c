/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:37:48 by neric             #+#    #+#             */
/*   Updated: 2026/11/12  by neric                           ###   ########.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_bench_ops(int op_type, int action)
{
	static long int	counts[11];
	long int		total;
	int				i;

	if (action == 1 && op_type >= 0 && op_type <= 10)
	{
		counts[op_type]++;
		return (1);
	}
	if (action == -1)
	{
		i = 0;
		while (i < 11)
			counts[i++] = 0;
		return (0);
	}
	total = 0;
	i = 0;
	while (i < 11)
		total += counts[i++];
	return (total);
}

static void	print_strategy_info(int strategy)
{
	if (strategy == SIMPLE)
		ft_putendl_fd("[bench] Strategy: Simple | O(n^2)", 2);
	else if (strategy == MEDIUM)
		ft_putendl_fd("[bench] Strategy: Medium | O(n sqrt(n))", 2);
	else if (strategy == COMPLEX)
		ft_putendl_fd("[bench] Strategy: Complex | O(n log n)", 2);
	else
		ft_putendl_fd("[bench] Strategy: Adaptive | Dynamic", 2);
}

static void	print_disorder(double disorder)
{
	int	integer_part;
	int	decimal_part;

	if (disorder < 0.0)
		disorder = 0.0;
	if (disorder > 1.0)
		disorder = 1.0;
	integer_part = (int)(disorder * 100);
	decimal_part = (int)(disorder * 10000) % 100;
	ft_putstr_fd("[bench] Disorder: ", 2);
	ft_putnbr_fd(integer_part, 2);
	write(2, ".", 1);
	if (decimal_part < 10)
		write(2, "0", 1);
	ft_putnbr_fd(decimal_part, 2);
	ft_putendl_fd("%", 2);
}

void	print_benchmark(int strategy, double disorder)
{
	long int	total_ops;

	total_ops = ft_bench_ops(0, 0);
	ft_putendl_fd("=== PUSH_SWAP BENCHMARK ===", 2);
	print_disorder(disorder);
	print_strategy_info(strategy);
	ft_putstr_fd("[bench] Total Operations: ", 2);
	ft_putnbr_fd(total_ops, 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("===========================", 2);
}