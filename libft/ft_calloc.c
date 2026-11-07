/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:23:14 by neric             #+#    #+#             */
/*   Updated: 2026/10/17 14:13:30 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	size_in_bytes;

	if (nmemb != 0 && size > (size_t) -1 / nmemb)
		return (NULL);
	size_in_bytes = nmemb * size;
	result = malloc (size_in_bytes);
	if (result == NULL)
		return (NULL);
	ft_memset (result, 0, size_in_bytes);
	return (result);
}

/*
#include <stdio.h>
int main() {

    int numItems = 15;
    int *myArray = ft_calloc(numItems, sizeof(int));

    // Write into the memory
    for(int i = 0; i < numItems; i++) {
    myArray[i] = i + 1;
    }

    // Display the contents of the memory
    for(int i = 0; i < numItems; i++) {
    printf("%d ", myArray[i]);
    }

    free(myArray);
    return (0);
}
*/
