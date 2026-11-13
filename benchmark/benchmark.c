/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 15:00:00 by neric             #+#    #+#             */
/*   Updated: 2026/11/13 15:00:00 by neric            ###   ########.fr       */
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
	if (action == 2 && op_type >= 0 && op_type <= 10)
		return (counts[op_type]);
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

static void	print_op_breakdown(void)
{
	char	*names[11];
	int		i;

	names[0] = "sa";
	names[1] = "sb";
	names[2] = "ss";
	names[3] = "pa";
	names[4] = "pb";
	names[5] = "ra";
	names[6] = "rb";
	names[7] = "rr";
	names[8] = "rra";
	names[9] = "rrb";
	names[10] = "rrr";
	i = 0;
	while (i < 11)
	{
		ft_putstr_fd("[bench] ", 2);
		ft_putstr_fd(names[i], 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(ft_bench_ops(i, 2), 2);
		ft_putendl_fd("", 2);
		i++;
	}
}

void	print_benchmark(int strategy, double disorder)
{
	long int	total_ops;

	total_ops = ft_bench_ops(0, 0);
	ft_putendl_fd("=== PUSH_SWAP BENCHMARK ===", 2);
	print_disorder(disorder);
	print_strategy_info(strategy);
	print_op_breakdown();
	ft_putstr_fd("[bench] Total Operations: ", 2);
	ft_putnbr_fd(total_ops, 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("===========================", 2);
}
