/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: mtorfs <marvin@42.fr>                     +#+  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/06 14:37:48 by mtorfs           #+#    #+#              */
/*   Updated: 2026/11/13 13:34:23 by mtorfs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		safe_atoi(char *str, int *number);
void	free_tokens(char **tokens);
int		is_duplicate(int value, int *numbers, int count);

static int	store_number(char *token, int *numbers, int *count)
{
	int	value;

	if (!safe_atoi(token, &value))
		return (0);
	if (is_duplicate(value, numbers, *count))
		return (0);
	numbers[*count] = value;
	(*count)++;
	return (1);
}

static int	parse_argument(char *arg, int *numbers, int *count)
{
	char	**tokens;
	int		i;

	if (!arg || !arg[0])
		return (0);
	tokens = ft_split(arg, ' ');
	if (!tokens || !tokens[0])
	{
		free_tokens(tokens);
		return (0);
	}
	i = 0;
	while (tokens[i])
	{
		if (numbers && !store_number(tokens[i], numbers, count))
		{
			free_tokens(tokens);
			return (0);
		}
		if (!numbers)
			(*count)++;
		i++;
	}
	free_tokens(tokens);
	return (1);
}

static int	count_numbers(int argc, char **argv, int start)
{
	int	i;
	int	count;

	i = start;
	count = 0;
	while (i < argc)
	{
		if (!parse_argument(argv[i], NULL, &count))
			return (0);
		i++;
	}
	return (count);
}

static int	fill_numbers(int argc, char **argv, int *params, int *array)
{
	int	i;

	i = params[0];
	while (i < argc)
	{
		if (!parse_argument(argv[i], array, &params[1]))
			return (0);
		i++;
	}
	return (1);
}

int	validate_args(int argc, char **argv, int *params, int **numbers)
{
	int	*array;

	*numbers = NULL;
	params[1] = count_numbers(argc, argv, params[0]);
	if (params[1] == 0)
		return (0);
	array = malloc(sizeof(int) * params[1]);
	if (!array)
		return (0);
	params[1] = 0;
	if (!fill_numbers(argc, argv, params, array))
	{
		free(array);
		params[1] = 0;
		return (0);
	}
	*numbers = array;
	return (1);
}
