/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 10:43:23 by neric             #+#    #+#             */
/*   Updated: 2026/10/19 19:25:52 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	result = malloc(end - start + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (start < end)
		result[i++] = s1[start++];
	result[i] = '\0';
	return (result);
}

/*
#include <stdio.h>

int main(void)
{
    char *result;

    result = ft_strtrim("..hello..", ".");
    printf("1:  [%s]\n", result);
    free(result);

    result = ft_strtrim("hello", ".");
    printf("2:  [%s]\n", result);
    free(result);

    result = ft_strtrim("", "abc");
    printf("3:  [%s]\n", result);
    free(result);

    result = ft_strtrim("hello", "");
    printf("4:  [%s]\n", result);
    free(result);

    result = ft_strtrim("aaaa", "a");
    printf("5:  [%s]\n", result);
    free(result);

    result = ft_strtrim("a", "a");
    printf("6:  [%s]\n", result);
    free(result);

    result = ft_strtrim("a", "b");
    printf("7:  [%s]\n", result);
    free(result);

    result = ft_strtrim("...hello", ".");
    printf("8:  [%s]\n", result);
    free(result);

    result = ft_strtrim("hello...", ".");
    printf("9:  [%s]\n", result);
    free(result);

    result = ft_strtrim("str.aexam.ple..", "a.");
    printf("10: [%s]\n", result);
    free(result);

    result = ft_strtrim("abchellocba", "abc");
    printf("11: [%s]\n", result);
    free(result);

    result = ft_strtrim("abhelloab", "ba");
    printf("12: [%s]\n", result);
    free(result);

    result = ft_strtrim("   hello   ", " ");
    printf("13: [%s]\n", result);
    free(result);

    result = ft_strtrim("\t\thello\t", "\t");
    printf("14: [%s]\n", result);
    free(result);

    result = ft_strtrim("ab", "abcdef");
    printf("15: [%s]\n", result);
    free(result);

    result = ft_strtrim("hello..world", ".");
    printf("16: [%s]\n", result);
    free(result);

    result = ft_strtrim("abcabc", "cba");
    printf("17: [%s]\n", result);
    free(result);

    result = ft_strtrim("xxhelloxx", "x");
    printf("18: [%s]\n", result);
    free(result);

    result = ft_strtrim("AAhelloAA", "a");
    printf("19: [%s]\n", result);
    free(result);

    result = ft_strtrim("!?hello?!", "!?");
    printf("20: [%s]\n", result);
    free(result);

    return (0);
}
*/
