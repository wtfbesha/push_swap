/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:23:14 by neric             #+#    #+#             */
/*   Updated: 2026/10/16 21:38:39 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	ch;

	p = s;
	ch = c;
	while (n != 0)
	{
		*p++ = ch;
		n--;
	}
	return (s);
}

/*
// #include <string.h>
// void    *ft_memset(void *s, int c, size_t n)
// void    *ft_memset(void *s, int c, unsigned int n)
// ft_memset(s, '7', sizeof(5));

#include<unistd.h>
void ft_putchar(char c)
{
    write(1, &c, 1);
}

void printArray (char *str, int n) {
    int i = 0;
    while (i < n)
    {
        ft_putchar(str[i]);
        i++;
    }
    write(1, "\n", 1);
}

int main () {
    char s[100] = "Hello world";

    // print array before memset
    printArray(s, 12);

    //print memset itself
    ft_memset(s, '7', 5);

    // print same array after memset
    printArray(s, 12);

   return 0;
}
*/
