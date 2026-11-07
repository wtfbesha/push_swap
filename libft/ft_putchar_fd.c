/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:26:05 by neric             #+#    #+#             */
/*   Updated: 2026/10/20 17:04:38 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int main(void)
{
    	ft_putchar_fd('c', 1);
    	ft_putchar_fd('\n', 1);
	ft_putchar_fd('A', 1); // terminal output
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('B', 0); // error output
	ft_putchar_fd('\n', 1);
    return (0);
}
*/
