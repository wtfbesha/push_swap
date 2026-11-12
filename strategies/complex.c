/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:37:48 by neric             #+#    #+#             */
/*   Updated: 2026/11/12 10:00:00 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	val(t_list *node)
{
	return (*(int *)node->content);
}

static t_list	**stk(t_list **a, t_list **b, int w)
{
	if (w == 0)
		return (a);
	return (b);
}

static void	mv(t_list **a, t_list **b, int from)
{
	if (from == 0)
		pb(a, b);
	else
		pa(a, b);
}

static void	rot(t_list **a, t_list **b, int w)
{
	if (w == 0)
		ra(a);
	else
		rb(b);
}

static void	rrot(t_list **a, t_list **b, int w)
{
	if (w == 0)
		rra(a);
	else
		rrb(b);
}

static void	swp(t_list **a, t_list **b, int w)
{
	if (w == 0)
		sa(a);
	else
		sb(b);
}

static int	top_sorted(t_list *s, int n)
{
	int	prev;

	if (n <= 1)
		return (1);
	if (!s)
		return (0);
	prev = val(s);
	s = s->next;
	n--;
	while (n > 0 && s)
	{
		if (prev > val(s))
			return (0);
		prev = val(s);
		s = s->next;
		n--;
	}
	return (n == 0);
}


static void	merge(t_list **a, t_list **b, int w, int n_w, int n_s)
{
	while (n_w > 0 || n_s > 0)
	{
		if (n_s == 0 || (n_w > 0
				&& val(*stk(a, b, w)) < val(*stk(a, b, 1 - w))))
		{
			rot(a, b, w);
			n_w--;
		}
		else
		{
			mv(a, b, 1 - w);
			rot(a, b, w);
			n_s--;
		}
	}
}

/*
** Bring the merged run back to the top.
** The rotations performed during merge leave the old tail
** above the merged run.
*/
static void	restore(t_list **a, t_list **b, int w, int n)
{
	while (n > 0)
	{
		rrot(a, b, w);
		n--;
	}
}

/*
** Sort the top n elements of stack w in ascending order.
**
** w = 0: stack A
** w = 1: stack B
*/
static void	msort(t_list **a, t_list **b, int w, int n)
{
	int	left;
	int	right;
	int	i;

	if (n <= 1 || top_sorted(*stk(a, b, w), n))
		return ;
	if (n == 2)
	{
		swp(a, b, w);
		return ;
	}
	left = n / 2;
	right = n - left;

	/*
	** Move the first half to the other stack.
	*/
	i = left;
	while (i > 0)
	{
		mv(a, b, w);
		i--;
	}

	/*
	** Sort the two halves independently.
	*/
	msort(a, b, w, right);
	msort(a, b, 1 - w, left);

	/*
	** Merge both sorted halves onto stack w.
	*/
	merge(a, b, w, right, left);

	/*
	** Restore the merged run if there are elements below it.
	*/
	if ((int)ft_lstsize(*stk(a, b, w)) > n)
		restore(a, b, w, n);
}

/*
** Public function.
** Sort all elements of A in ascending order.
*/
void	ft_merge_sort(t_list **a, t_list **b)
{
	int	size;

	if (!a || !b || !*a)
		return ;
	size = (int)ft_lstsize(*a);
	msort(a, b, 0, size);
}
