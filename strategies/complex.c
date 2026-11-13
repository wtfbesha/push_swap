/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:37:48 by neric             #+#    #+#             */
/*   Updated: 2026/11/13 15:00:00 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	top_sorted(t_list *s, int n)
{
	int	prev;

	if (n <= 1)
		return (1);
	if (!s)
		return (0);
	prev = complex_val(s);
	s = s->next;
	n--;
	while (n > 0 && s)
	{
		if (prev > complex_val(s))
			return (0);
		prev = complex_val(s);
		s = s->next;
		n--;
	}
	return (n == 0);
}

static void	merge(t_list **a, t_list **b, int w, int sizes[2])
{
	int	n_w;
	int	n_s;

	n_w = sizes[0];
	n_s = sizes[1];
	while (n_w > 0 || n_s > 0)
	{
		if (n_s == 0 || (n_w > 0
				&& complex_val(*complex_stk(a, b, w))
				< complex_val(*complex_stk(a, b, 1 - w))))
		{
			complex_rot(a, b, w);
			n_w--;
		}
		else
		{
			complex_mv(a, b, 1 - w);
			complex_rot(a, b, w);
			n_s--;
		}
	}
}

static void	restore(t_list **a, t_list **b, int w, int n)
{
	while (n > 0)
	{
		complex_rrot(a, b, w);
		n--;
	}
}

static void	msort(t_list **a, t_list **b, int w, int n)
{
	int	left;
	int	right;
	int	sizes[2];

	if (n <= 1 || top_sorted(*complex_stk(a, b, w), n))
		return ;
	if (n == 2)
	{
		complex_swp(a, b, w);
		return ;
	}
	left = n / 2;
	right = n - left;
	complex_move_chunks(a, b, w, left);
	msort(a, b, w, right);
	msort(a, b, 1 - w, left);
	sizes[0] = right;
	sizes[1] = left;
	merge(a, b, w, sizes);
	if ((int)ft_lstsize(*complex_stk(a, b, w)) > n)
		restore(a, b, w, n);
}

void	ft_merge_sort(t_list **a, t_list **b)
{
	int	size;

	if (!a || !b || !*a)
		return ;
	size = (int)ft_lstsize(*a);
	msort(a, b, 0, size);
}
