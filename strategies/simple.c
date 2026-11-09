/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorfs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 18:39:29 by mtorfs            #+#    #+#             */
/*   Updated: 2026/11/06 18:39:48 by mtorfs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void ft_buble_sort(t_list *a, t_list *b) 
{
    int size;
    int i;
    int j;
    int *first;
    int *second;

    size = ft_lstsize(*a);
    i = 0;
    while (i < size - i - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            first = (*a)->content;
            second = (*a)->next->content;
            if (*first > *second)
			    sa(a);
			pb(a, b);
			j++;
        }
        while (*b)
            pa(a, b);
    }
}
/*
int main(void)
{
    t_list	*a;
	t_list	*b;
	int		values[] = {5, 2, 8, 1, 4};
	int		i;

	a = NULL;
	b = NULL;
	i = 0;
	while (i < 5)
	{
		ft_lstadd_back(&a, ft_lstnew(&values[i]));
		i++;
	}
	printf("Before sorting: ");
	t_list *tmp = a;
	while (tmp)
	{
		printf("%d ", *(int *)tmp->content);
		tmp = tmp->next;
	}
	printf("\n");

	ft_bubble_sort(&a, &b);

	printf("After sorting: ");
	tmp = a;
	while (tmp)
	{
		printf("%d ", *(int *)tmp->content);
		tmp = tmp->next;
	}
	printf("\n");

	ft_lstclear(&a, NULL);
	return (0);
}*/