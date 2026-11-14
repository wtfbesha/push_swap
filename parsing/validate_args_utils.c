/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   validate_args_utils.c                              :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: mtorfs <mtorfs@student.42belgium.be>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/06 14:37:48 by mtorfs           #+#    #+#              */
/*   Updated: 2026/11/12 18:09:35 by mtorfs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_sign(char *str, int *i, long int *limit)
{
	int	sign;

	sign = 1;
	*limit = 2147483647L;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
		{
			sign = -1;
			*limit = 2147483648L;
		}
		(*i)++;
	}
	return (sign);
}

static int	convert_digits(char *str, int i, long int limit,
		long int *value)
{
	*value = 0;
	while (str[i])
	{
		if (!ft_isdigit((unsigned char)str[i]))
			return (0);
		if (*value > (limit - (str[i] - '0')) / 10)
			return (0);
		*value = *value * 10 + (str[i] - '0');
		i++;
	}
	return (1);
}

int	safe_atoi(char *str, int *number)
{
	int			i;
	int			sign;
	long int	value;
	long int	limit;

	i = 0;
	if (!str || !str[i])
		return (0);
	sign = get_sign(str, &i, &limit);
	if (!str[i] || !convert_digits(str, i, limit, &value))
		return (0);
	if (sign == -1 && value == 2147483648L)
		*number = -2147483647 - 1;
	else
		*number = (int)(value * sign);
	return (1);
}

void	free_tokens(char **tokens)
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

int	is_duplicate(int value, int *numbers, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (numbers[i] == value)
			return (1);
		i++;
	}
	return (0);
}
