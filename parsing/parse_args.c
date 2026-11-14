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

int	is_bench(char *arg, int *bench);
int	set_strategy(char *arg, int *strategy, int *selected);

static int	process_option(char *arg, int *params, int *selected)
{
	int	result;

	result = is_bench(arg, &params[1]);
	if (result != -1)
		return (result);
	return (set_strategy(arg, &params[0], selected));
}

int	parse_args(int argc, char **argv, int *params)
{
	int	i;
	int	selected;
	int	result;

	i = 1;
	selected = 0;
	params[0] = ADAPTIVE;
	params[1] = 0;
	while (i < argc)
	{
		result = process_option(argv[i], params, &selected);
		if (result == 0)
			return (0);
		if (result == -1)
			break ;
		i++;
	}
	params[2] = i;
	return (i < argc);
}
