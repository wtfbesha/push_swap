/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:23:14 by neric             #+#    #+#             */
/*   Updated: 2026/10/17 15:24:47 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

/*
#include <stdio.h>
int main()
{
    // // create a test string
    // char *string = "This is MY string!";
    // // first_M should be a pointer to the 
    // //first 'M' character in the test string
    // char *first_M = ft_strchr(string, 'M');
    // // If we output the string starting from 
    // // first_M we will get "MY string!"
    // printf("first_M: %s\n", first_M);
    // // There is no 'Z' character in the string, 
    // // so the function should return NULL
    // char *first_Z = ft_strchr(string, 'Z');
    // // check that first_Z is set to NULL by outputting 
    // "No 'Z' found!" if it is
    // if (first_Z == NULL)
    //     printf("No 'Z' found!\n");


	char	str[] = "hello";
	char	*ptr;
	ptr = ft_strchr(str, 'l');
	if (ptr != NULL)
		printf("Character found at position: %td\n", ptr - str);
	else
		printf("Character not found\n");

    return 0;
}
*/
