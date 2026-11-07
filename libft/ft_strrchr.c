/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:23:14 by neric             #+#    #+#             */
/*   Updated: 2026/10/17 15:26:03 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*find_r_p;

	find_r_p = 0;
	while (*s)
	{
		if (*s == (char) c)
			find_r_p = s;
		s++;
	}
	if ((char)c == '\0')
		find_r_p = s;
	return ((char *)(find_r_p));
}

/*
#include <stdio.h>
int main()
{       
    // char myStr[] = "Hello World";
    // char *myPtr2 = ft_strrchr(myStr, 'o');
    // if (myPtr2 != NULL) {
    //     printf("Last: %s\n", myPtr2);
    // }

    // int len;
    // const char str[] = "https://www.tutorialspoint.com";
    // const char ch = '.';
    // char *ret;
    // ret = strrchr(str, ch);
    // printf("String after |%c| is - |%s|\n", ch, ret);

    const char str[] = "Hello, World!";
    const char ch = 'W';

    // Search in the substring "World!"
    char* ptr = ft_strrchr(str + 7, ch); 

    if (ptr) {
        printf("'%c' found at position %ld\n", ch, ptr - str);
    } else {
        printf("'%c' not found in the substring\n", ch);
    }

  return 0;
}
*/