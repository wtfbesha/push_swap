/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:23:14 by neric             #+#    #+#             */
/*   Updated: 2026/10/16 21:39:49 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int a)
{
	if (a >= 32 && a < 127)
		return (1);
	else
		return (0);
}

/*
#include<unistd.h>
int main () {
    int res = ft_isprint('\t');
    if (res == 1)
    {
        write(1, "1\n", 2);
    } else {
        write(1, "0\n", 2);
    }
    return 0;
}
*/
