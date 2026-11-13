/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: mtorfs <mtorfs@student.42belgium.be>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/06 14:37:48 by mtorfs           #+#    #+#              */
/*   Updated: 2026/11/12 18:09:35 by mtorfs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_bench(char *arg, int *bench)
{
	if (ft_strncmp(arg, "--bench", 8) == 0)
	{
		if (*bench)
			return (0);
		*bench = 1;
		return (1);
	}
	return (-1);
}

static int	set_strategy(char *arg, int *strategy, int *selected)
{
	int	new_strategy;

	if (ft_strncmp(arg, "--simple", 9) == 0)
		new_strategy = SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		new_strategy = MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		new_strategy = COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		new_strategy = ADAPTIVE;
	else
		return (-1);
	if (*selected)
		return (0);
	*strategy = new_strategy;
	*selected = 1;
	return (1);
}

int	parse_args(int argc, char **argv, int *strategy,
	int	*bench, int *numbers_start)
{
	int	i;
	int	result;
	int	selected;

	i = 1;
	selected = 0;
	*strategy = ADAPTIVE;
	*bench = 0;
	while (i < argc)
	{
		result = is_bench(argv[i], bench);
		if (result == 0)
			return (0);
		if (result == -1)
		{
			result = set_strategy(argv[i], strategy, &selected);
			if (result == 0)
				return (0);
			if (result == -1)
				break ;
		}
		i++;
	}
	*numbers_start = i;
	return (i < argc);
}
