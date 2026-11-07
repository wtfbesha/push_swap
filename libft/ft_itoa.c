/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 18:46:57 by neric             #+#    #+#             */
/*   Updated: 2026/10/17 21:57:47 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_dec(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*base(char *str, long int n_, int i)
{
	while (n_ > 0)
	{
		str[i] = (n_ % 10) + '0';
		n_ = n_ / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	n_;

	n_ = n;
	i = ft_dec(n_);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
	{
		return (NULL);
	}
	str[i--] = '\0';
	if (n_ == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n_ < 0)
	{
		str[0] = '-';
		n_ *= -1;
	}
	base(str, n_, i);
	return (str);
}

/*
#include <stdio.h>
int main()
{
    printf("Base: %s\n", ft_itoa(+1567));
    printf("Base:10 %s\n", ft_itoa(2324));
    printf("Base:10 %s\n", ft_itoa(2324));
    return 0;
}
*/
