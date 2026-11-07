/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:23:14 by neric             #+#    #+#             */
/*   Updated: 2026/10/16 21:40:47 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int a)
{
	if (a >= 0 && a < 128)
		return (1);
	else
		return (0);
}

/*
#include<unistd.h>
int main () {
    int res = ft_isascii('=');
    if (res == 1)
    {
        write(1, "1\n", 2);
    } else {
        write(1, "0\n", 2);
    }
    return 0;
}
*/
