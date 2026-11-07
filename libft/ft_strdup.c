/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:23:14 by neric             #+#    #+#             */
/*   Updated: 2026/10/19 17:31:26 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int				len;
	char			*new_src;
	unsigned int	i;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		len++;
	new_src = (char *)malloc(len + 1);
	if (new_src == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		new_src[i] = src[i];
		i++;
	}
	new_src[i] = '\0';
	return (new_src);
}

/*
#include<stdio.h>
int main()
{
    char source[] = "GeeksForGeeks";
    char* target = ft_strdup(source); 
    printf("%s\n", target);

    char src[] = "Base 10";
	char *res;
	res = ft_strdup(src);
	printf("%s\n", res);


    // char *copy;
    // copy = ft_strdup("Hello");
    // printf("%s\n", copy);
    // free(copy);

	return (0);
}
*/
