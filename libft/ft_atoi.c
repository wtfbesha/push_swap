/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:23:14 by neric             #+#    #+#             */
/*   Updated: 2026/10/16 14:23:27 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	output;

	i = 0;
	sign = 1;
	output = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		output = output * 10 + (str[i] - '0');
		i++;
	}
	return (output * sign);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%d\n", ft_atoi(""));			  // 0
// 	printf("%d\n", ft_atoi("42"));			  // 42
// 	printf("%d\n", ft_atoi("-42"));			  // -42
// 	printf("%d\n", ft_atoi("+42"));			  // 42
// 	printf("%d\n", ft_atoi("   42"));		  // 42
// 	printf("%d\n", ft_atoi("\t\n\v\f\r 42")); // 42
// 	printf("%d\n", ft_atoi("42abc"));		  // 42
// 	printf("%d\n", ft_atoi("abc42"));		  // 0
// 	printf("%d\n", ft_atoi("++42"));		  // 0
// 	printf("%d\n", ft_atoi("--42"));		  // 0
// 	printf("%d\n", ft_atoi("+-42"));		  // 0
// 	printf("%d\n", ft_atoi("-+42"));		  // 0
// 	printf("%d\n", ft_atoi("  -42abc"));	  // -42
// 	printf("%d\n", ft_atoi("0"));			  // 0
// 	printf("%d\n", ft_atoi("-0"));			  // 0
// 	printf("%d\n", ft_atoi("+0"));			  // 0
// 	printf("%d\n", ft_atoi("2147483647"));	  // INT_MAX
// 	printf("%d\n", ft_atoi("-2147483648"));	  // INT_MIN
// 	printf("%d\n", ft_atoi("   +"));		  // 0
// 	printf("%d\n", ft_atoi("  -"));			  // 0
// 	printf("%d\n", ft_atoi("12 34"));		  // 12
// 	printf("%d\n", ft_atoi("007"));			  // 7
// }