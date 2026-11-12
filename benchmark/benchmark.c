/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:37:48 by neric             #+#    #+#             */
/*   Updated: 2026/11/12 15:30:00 by neric            ###   ########.fr       */
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
		ft_putendl_fd("[bench] Strategy: Simple | Complexity: O(n^2)", 2);
	else if (strategy == MEDIUM)
		ft_putendl_fd("[bench] Strategy: Medium | Complexity: O(n sqrt(n))", 2);
	else if (strategy == COMPLEX)
		ft_putendl_fd("[bench] Strategy: Complex | Complexity: O(n log n)", 2);
	else
		ft_putendl_fd("[bench] Strategy: Adaptive | Complexity: Dynamic", 2);
}

static void	print_disorder(double disorder)
{
	int	integer_part;
	int	decimal_part;

	integer_part = (int)(disorder * 100);
	decimal_part = (int)((disorder * 10000) - (integer_part * 100));
	ft_putstr_fd("[bench] Disorder: ", 2);
	ft_putnbr_fd(integer_part, 2);
	write(2, ".", 1);
	if (decimal_part < 10)
		write(2, "0", 1);
	ft_putnbr_fd(decimal_part, 2);
	write(2, "%\n", 2);
}

void	print_benchmark(int strategy, double disorder)
{
	long	total_ops;

	if (disorder < 0.0)
		disorder = 0.0;
	total_ops = ft_bench_ops(0, 0);
	write(2, "=== PUSH_SWAP BENCHMARK ===\n", 29);
	print_disorder(disorder);
	print_strategy_info(strategy);
	ft_putstr_fd("[bench] Total Operations: ", 2);
	ft_putnbr_fd(total_ops, 2);
	write(2, "\n===========================\n", 29);
}