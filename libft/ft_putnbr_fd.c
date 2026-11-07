/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 18:02:13 by neric             #+#    #+#             */
/*   Updated: 2026/10/20 19:26:09 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	str;
	long	long_nb;

	long_nb = n;
	if (long_nb < 0)
	{
		ft_putchar_fd('-', fd);
		long_nb = -long_nb;
	}
	if (long_nb >= 10)
	{
		ft_putnbr_fd(long_nb / 10, fd);
	}
	str = (long_nb % 10) + '0';
	ft_putchar_fd(str, fd);
}
/*
int	main(void)
{
	ft_putnbr_fd(0, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(2147483647, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
*/