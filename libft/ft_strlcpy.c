/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:23:14 by neric             #+#    #+#             */
/*   Updated: 2026/10/17 16:13:37 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src [i];
			i++;
		}
		dst [i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

/*
#include <stdio.h>
int main() {
	char dest[10] = "";
	char src[] = "Hello wereld aarde..";

	unsigned int size = 10;

	int res;
	res = ft_strlcpy(dest, src, size);

	printf("result: %d ", res);
}
*/
