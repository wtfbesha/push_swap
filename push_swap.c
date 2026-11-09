/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:37:48 by neric             #+#    #+#             */
/*   Updated: 2026/11/06 14:37:58 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		strategy;
	int		bench;
	int		start;
	int		count;
	int		*numbers;
	t_list	*a;
	t_list	*current;

	if (argc == 1)
		return (0);
	if (!parse_args(argc, argv, &strategy, &bench, &start))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!validate_args(argc, argv, start, &numbers, &count))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a = init_stack_a(numbers, count);
	free(numbers);
	if (!a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	current = a;
	ft_putendl_fd("Stack A (top -> bottom):", 1);
	while (current)
	{
		ft_putnbr_fd(*(int *)current->content, 1);
		ft_putchar_fd('\n', 1);
		current = current->next;
	}
	ft_putendl_fd("Stack B: empty", 1);
	ft_lstclear(&a, free);
	return (0);
}