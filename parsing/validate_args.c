/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   validate_args.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mtorfs <marvin@42.fr>                     #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/06 14:37:48 by mtorfs           #+#    #+#              */
/*   Updated: 2026/11/12 21:56:55 by mtorfs          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	safe_atoi(char *str, int *number)
{
	int			i;
	int			sign;
	long int	value;
	long int	limit;

	i = 0;
	if (!str || !str[i])
		return (0);
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	limit = 2147483647L;
	if (sign == -1)
		limit = 2147483648L;
	value = 0;
	while (str[i])
	{
		if (!ft_isdigit((unsigned char) str[i]))
			return (0);
		if (value > (limit - (str[i] - '0')) / 10)
			return (0);
		value = value * 10 + (str[i] - '0');
		i++;
	}
	if (sign == -1 && value == 2147483648L)
		*number = -2147483647 - 1;
	else
		*number = (int)(value * sign);
	return (1);
}

static void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens && tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

static int	store_number(char *token, int *numbers, int *count)
{
	int	value;
	int	i;

	if (!safe_atoi(token, &value))
		return (0);
	i = 0;
	while (i < *count)
	{
		if (numbers[i] == value)
			return (0);
		i++;
	}
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

int validate_args(int argc, char **argv, int start,
	int	**numbers, int *count)
{
	int	i;
	int	total;
	int	*array;

	*numbers = NULL;
	*count = 0;
	total = 0;
	i = start;
	while (i < argc)
	{
		if (!parse_argument(argv[i], NULL, &total))
			return (0);
		i++;
	}
	if (total == 0)
		return (0);
	array = malloc(sizeof(int)*total);
	if (!array)
		return (0);
	i = start;
	while (i < argc)
	{
		if (!parse_argument(argv[i], array, count))
		{
			free(array);
			*count = 0;
			return (0);
		}
		i++;
	}
	*numbers = array;
	return (1);
}
