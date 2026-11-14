/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parse_args_utils.c                                 :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: mtorfs <mtorfs@student.42belgium.be>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/06 14:37:48 by mtorfs           #+#    #+#              */
/*   Updated: 2026/11/12 18:09:35 by mtorfs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_bench(char *arg, int *bench)
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

int	set_strategy(char *arg, int *strategy, int *selected)
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
