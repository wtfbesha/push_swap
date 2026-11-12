/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:37:48 by neric             #+#    #+#             */
/*   Updated: 2026/11/06 14:37:58 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// static void	error_exit(void)
// {
// 	write(2, "Error\n", 6);
// }

// static int	is_sorted(t_list *a)
// {
// 	while (a && a->next)
// 	{
// 		if (*(int *)a->content > *(int *)a->next->content)
// 			return (0);
// 		a = a->next;
// 	}
// 	return (1);
// }

// static void	run_strategy(t_list **a, t_list **b, int strategy)
// {
// 	if (strategy == SIMPLE)
// 		sort_simple(a, b);
// 	else if (strategy == COMPLEX)
// 		ft_merge_sort(a, b);
// }

// int	main(int argc, char **argv)
// {
// 	int		strategy;
// 	int		bench;
// 	int		start;
// 	int		count;
// 	int		*numbers;
// 	t_list	*a;
// 	t_list	*b;

// 	if (argc == 1)
// 		return (0);
// 	if (!parse_args(argc, argv, &strategy, &bench, &start))
// 		return (error_exit(), 1);
// 	if (!validate_args(argc, argv, start, &numbers, &count))
// 		return (error_exit(), 1);
// 	a = init_stack_a(numbers, count);
// 	free(numbers);
// 	if (!a)
// 		return (error_exit(), 1);
// 	b = NULL;
// 	if (!is_sorted(a))
// 		run_strategy(&a, &b, strategy);
// 	ft_lstclear(&a, free);
// 	ft_lstclear(&b, free);
// 	return (0);
// }



// #include "push_swap.h"


// // static void print_disorder(char *label, t_list *stack)
// // {
// //     ft_putstr_fd(label, 1);
// //     ft_putnbr_fd((int)(compute_disorder(stack) * 1000000), 1);
// //     ft_putchar_fd('\n', 1);
// // }

// int main(void)
// {
//     int one[1] = {42};
//     int sorted[4] = {1, 2, 3, 4};
//     int reverse[4] = {4, 3, 2, 1};
//     int partial[4] = {2, 1, 3, 4};

//     print_disorder("NULL: ", NULL);
//     run_test("One element: ", one, 1);
//     run_test("Sorted: ", sorted, 4);
//     run_test("Reverse: ", reverse, 4);
//     run_test("Partial: ", partial, 4);
//     return (0);
// }

// static void do_nothing(void *content)
// {
//     (void)content;
// }

// int	main(int argc, char **argv)
// {
// 	int		strategy;
// 	int		bench;
// 	int		start;
// 	int		count;
// 	int		*numbers;
// 	t_list	*a;
// 	t_list	*b;

// 	if (argc == 1)
// 		return (0);
// 	if (!parse_args(argc, argv, &strategy, &bench, &start))
// 	{
// 		write(2, "Error\n", 6);
// 		return (1);
// 	}
// 	if (!validate_args(argc, argv, start, &numbers, &count))
// 	{
// 		write(2, "Error\n", 6);
// 		return (1);
// 	}
// 	a = init_stack_a(numbers, count);
// 	free(numbers);
// 	if (!a)
// 	{
// 		write(2, "Error\n", 6);
// 		return (1);
// 	}
// 	b = NULL;
// 	if (strategy == MEDIUM || strategy == ADAPTIVE)
// 		sort_medium(&a, &b);
// 	else if (strategy == SIMPLE)
// 		sort_simple(&a, &b);
// 	else
// 		sort_medium(&a, &b);
// 	ft_lstclear(&a, free);
// 	ft_lstclear(&b, free);
// 	(void)bench;
// 	return (0);
// }

// #include "push_swap.h"

// int	main(int argc, char **argv)
// {
// 	int		strategy;
// 	int		bench;
// 	int		start;
// 	int		count;
// 	int		*numbers;
// 	t_list	*a;
// 	t_list	*b;

// 	if (argc == 1)
// 		return (0);
// 	if (!parse_args(argc, argv, &strategy, &bench, &start))
// 	{
// 		write(2, "Error\n", 6);
// 		return (1);
// 	}
// 	if (!validate_args(argc, argv, start, &numbers, &count))
// 	{
// 		write(2, "Error\n", 6);
// 		return (1);
// 	}
// 	a = init_stack_a(numbers, count);
// 	free(numbers);
// 	if (!a)
// 	{
// 		write(2, "Error\n", 6);
// 		return (1);
// 	}
// 	b = NULL;
// 	ft_lstclear(&a, free);
// 	ft_lstclear(&b, free);
// 	return (0);
// }




// static void do_nothing(void *content)
// {
//     (void)content;
// }

// static t_list *make_stack(int *values, int size)
// {
//     t_list *stack;
//     int i;

//     stack = NULL;
//     i = 0;
//     while (i < size)
//     {
//         ft_lstadd_back(&stack, ft_lstnew(&values[i]));
//         i++;
//     }
//     return (stack);
// }

// static void free_stack(t_list **stack)
// {
//     ft_lstclear(stack, do_nothing);
// }

// static void print_disorder(char *label, t_list *stack)
// {
//     ft_putstr_fd(label, 1);
//     ft_putnbr_fd((int)(compute_disorder(stack) * 1000000), 1);
//     ft_putchar_fd('\n', 1);
// }

// static void run_test(char *label, int *values, int size)
// {
//     t_list *stack;

//     stack = make_stack(values, size);
//     print_disorder(label, stack);
//     free_stack(&stack);
// }

// int main(void)
// {
//     int one[1] = {42};
//     int sorted[4] = {1, 2, 3, 4};
//     int reverse[4] = {4, 3, 2, 1};
//     int partial[4] = {2, 1, 3, 4};

//     print_disorder("NULL: ", NULL);
//     run_test("One element: ", one, 1);
//     run_test("Sorted: ", sorted, 4);
//     run_test("Reverse: ", reverse, 4);
//     run_test("Partial: ", partial, 4);
//     return (0);
// }



// #include "push_swap.h"

// int	main(void)
// {
// 	int		values1[] = {1, 2, 3, 4};
// 	int		values2[] = {4, 3, 2, 1};
// 	int		values3[] = {2, 1, 3, 4};
// 	t_list	*a;

// 	a = NULL;
// 	ft_lstadd_back(&a, ft_lstnew(&values1[0]));
// 	ft_lstadd_back(&a, ft_lstnew(&values1[1]));
// 	ft_lstadd_back(&a, ft_lstnew(&values1[2]));
// 	ft_lstadd_back(&a, ft_lstnew(&values1[3]));
// 	write(1, "Sorted: ", 8);
// 	ft_putnbr_fd((int)(compute_disorder(a) * 1000000), 1);
// 	write(1, "\n", 1);
// 	ft_lstclear(&a, NULL);

// 	a = NULL;
// 	ft_lstadd_back(&a, ft_lstnew(&values2[0]));
// 	ft_lstadd_back(&a, ft_lstnew(&values2[1]));
// 	ft_lstadd_back(&a, ft_lstnew(&values2[2]));
// 	ft_lstadd_back(&a, ft_lstnew(&values2[3]));
// 	write(1, "Reverse: ", 9);
// 	ft_putnbr_fd((int)(compute_disorder(a) * 1000000), 1);
// 	write(1, "\n", 1);
// 	ft_lstclear(&a, NULL);

// 	a = NULL;
// 	ft_lstadd_back(&a, ft_lstnew(&values3[0]));
// 	ft_lstadd_back(&a, ft_lstnew(&values3[1]));
// 	ft_lstadd_back(&a, ft_lstnew(&values3[2]));
// 	ft_lstadd_back(&a, ft_lstnew(&values3[3]));
// 	write(1, "Partial: ", 9);
// 	ft_putnbr_fd((int)(compute_disorder(a) * 1000000), 1);
// 	write(1, "\n", 1);
// 	ft_lstclear(&a, NULL);
// 	return (0);
// }











// #include <stdio.h> // temporary for printing stack values during tests

// static void print_stacks(t_list *a, t_list *b)
// {
//     ft_putstr_fd("-------------------\n", 1);
//     ft_putstr_fd("Stack A: ", 1);
//     while (a)
//     {
//         ft_putnbr_fd(*(int *)a->content, 1);
//         ft_putchar_fd(' ', 1);
//         a = a->next;
//     }
//     ft_putchar_fd('\n', 1);

//     ft_putstr_fd("Stack B: ", 1);
//     while (b)
//     {
//         ft_putnbr_fd(*(int *)b->content, 1);
//         ft_putchar_fd(' ', 1);
//         b = b->next;
//     }
//     ft_putchar_fd('\n', 1);
//     ft_putstr_fd("-------------------\n", 1);
// }

// int main(int argc, char **argv)
// {
//     int     strategy;
//     int     bench;
//     int     start;
//     int     count;
//     int     *numbers;
//     t_list  *a;
//     t_list  *b;

//     if (argc == 1)
//         return (0);
//     if (!parse_args(argc, argv, &strategy, &bench, &start))
//     {
//         write(2, "Error\n", 6);
//         return (1);
//     }
//     if (!validate_args(argc, argv, start, &numbers, &count))
//     {
//         write(2, "Error\n", 6);
//         return (1);
//     }
//     a = init_stack_a(numbers, count);
//     free(numbers);
//     if (!a)
//     {
//         write(2, "Error\n", 6);
//         return (1);
//     }
//     b = NULL;

//     // --- TESTING OPERATIONS ---
//     ft_putstr_fd("INITIAL STATE:\n", 1);
//     print_stacks(a, b);

//     // Test Push to B
//     if (a) {
//         ft_putstr_fd("-> Calling pb:\n", 1);
//         pb(&a, &b);
//         print_stacks(a, b);
//     }

//     // Test Rotate A
//     if (a && a->next) {
//         ft_putstr_fd("-> Calling ra:\n", 1);
//         ra(&a);
//         print_stacks(a, b);
//     }

//     // Test Swap A
//     if (a && a->next) {
//         ft_putstr_fd("-> Calling sa:\n", 1);
//         sa(&a);
//         print_stacks(a, b);
//     }

//     // Test Push back to A
//     if (b) {
//         ft_putstr_fd("-> Calling pa:\n", 1);
//         pa(&a, &b);
//         print_stacks(a, b);
//     }

//     // Clean up
//     ft_lstclear(&a, free);
//     ft_lstclear(&b, free);
//     return (0);
// }
























// #include "push_swap.h"

// int	main(int argc, char **argv)
// {
// 	int		strategy;
// 	int		bench;
// 	int		start;
// 	int		count;
// 	int		*numbers;
// 	t_list	*a;
// 	t_list	*b;

// 	if (argc == 1)
// 		return (0);
// 	if (!parse_args(argc, argv, &strategy, &bench, &start))
// 	{
// 		write(2, "Error\n", 6);
// 		return (1);
// 	}
// 	if (!validate_args(argc, argv, start, &numbers, &count))
// 	{
// 		write(2, "Error\n", 6);
// 		return (1);
// 	}
// 	a = init_stack_a(numbers, count);
// 	free(numbers);
// 	if (!a)
// 	{
// 		write(2, "Error\n", 6);
// 		return (1);
// 	}
// 	b = NULL;
// 	ft_lstclear(&a, free);
// 	ft_lstclear(&b, free);
// 	return (0);
// }












// static int	check_stack(t_list *stack, int *expected, int size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		if (!stack || *(int *)stack->content != expected[i])
// 			return (0);
// 		stack = stack->next;
// 		i++;
// 	}
// 	return (stack == NULL);
// }

// // static void	print_result(char *name, int passed)
// // {
// // 	ft_putstr_fd(name, 1);
// // 	if (passed)
// // 		ft_putendl_fd(": OK", 1);
// // 	else
// // 		ft_putendl_fd(": FAIL", 1);
// // }

// static int	print_result(char *name, int passed)
// {
// 	if (passed)
// 		ft_putstr_fd(name, 1);
// 	if (passed)
// 		ft_putstr_fd(": OK\n", 1);
// 	else
// 		ft_putstr_fd(": FAIL\n", 1);
// 	return (!passed);
// }

// static void	free_stacks(t_list **a, t_list **b)
// {
// 	ft_lstclear(a, free);
// 	ft_lstclear(b, free);
// }

// static t_list	*make_stack(int *values, int size)
// {
// 	t_list	*stack;
// 	t_list	*node;
// 	int		i;
// 	int		*value;

// 	stack = NULL;
// 	i = 0;
// 	while (i < size)
// 	{
// 		value = malloc(sizeof(int));
// 		if (!value)
// 		{
// 			ft_lstclear(&stack, free);
// 			return (NULL);
// 		}
// 		*value = values[i];
// 		node = ft_lstnew(value);
// 		if (!node)
// 		{
// 			free(value);
// 			ft_lstclear(&stack, free);
// 			return (NULL);
// 		}
// 		ft_lstadd_back(&stack, node);
// 		i++;
// 	}
// 	return (stack);
// }

// static int	test_sa(void)
// {
// 	int		values[] = {1, 2, 3};
// 	int		expected[] = {2, 1, 3};
// 	t_list	*a;
// 	t_list	*b;

// 	a = make_stack(values, 3);
// 	b = NULL;
// 	if (!a)
// 		return (0);
// 	sa(&a);
// 	if (!check_stack(a, expected, 3))
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }

// static int	test_sb(void)
// {
// 	int		values[] = {1, 2, 3};
// 	int		expected[] = {2, 1, 3};
// 	t_list	*a;
// 	t_list	*b;

// 	a = NULL;
// 	b = make_stack(values, 3);
// 	if (!b)
// 		return (0);
// 	sb(&b);
// 	if (!check_stack(b, expected, 3))
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }

// static int	test_ss(void)
// {
// 	int		av[] = {1, 2, 3};
// 	int		bv[] = {4, 5, 6};
// 	int		ea[] = {2, 1, 3};
// 	int		eb[] = {5, 4, 6};
// 	t_list	*a;
// 	t_list	*b;

// 	a = make_stack(av, 3);
// 	b = make_stack(bv, 3);
// 	if (!a || !b)
// 		return (free_stacks(&a, &b), 0);
// 	ss(&a, &b);
// 	if (!check_stack(a, ea, 3) || !check_stack(b, eb, 3))
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }

// static int	test_pa_pb(void)
// {
// 	int		av[] = {1, 2, 3};
// 	int		ea[] = {2, 3};
// 	int		eb[] = {1};
// 	t_list	*a;
// 	t_list	*b;

// 	a = make_stack(av, 3);
// 	b = NULL;
// 	if (!a)
// 		return (0);
// 	pb(&a, &b);
// 	if (!check_stack(a, ea, 2) || !check_stack(b, eb, 1))
// 		return (free_stacks(&a, &b), 0);
// 	pa(&a, &b);
// 	if (!check_stack(a, av, 3) || b != NULL)
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }

// static int	test_ra(void)
// {
// 	int		v[] = {1, 2, 3};
// 	int		e[] = {2, 3, 1};
// 	t_list	*a;
// 	t_list	*b;

// 	a = make_stack(v, 3);
// 	b = NULL;
// 	if (!a)
// 		return (0);
// 	ra(&a);
// 	if (!check_stack(a, e, 3))
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }

// static int	test_rb(void)
// {
// 	int		v[] = {1, 2, 3};
// 	int		e[] = {2, 3, 1};
// 	t_list	*a;
// 	t_list	*b;

// 	a = NULL;
// 	b = make_stack(v, 3);
// 	if (!b)
// 		return (0);
// 	rb(&b);
// 	if (!check_stack(b, e, 3))
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }

// static int	test_rr(void)
// {
// 	int		av[] = {1, 2, 3};
// 	int		bv[] = {4, 5, 6};
// 	int		ea[] = {2, 3, 1};
// 	int		eb[] = {5, 6, 4};
// 	t_list	*a;
// 	t_list	*b;

// 	a = make_stack(av, 3);
// 	b = make_stack(bv, 3);
// 	if (!a || !b)
// 		return (free_stacks(&a, &b), 0);
// 	rr(&a, &b);
// 	if (!check_stack(a, ea, 3) || !check_stack(b, eb, 3))
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }

// static int	test_rra(void)
// {
// 	int		v[] = {1, 2, 3};
// 	int		e[] = {3, 1, 2};
// 	t_list	*a;
// 	t_list	*b;

// 	a = make_stack(v, 3);
// 	b = NULL;
// 	if (!a)
// 		return (0);
// 	rra(&a);
// 	if (!check_stack(a, e, 3))
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }

// static int	test_rrb(void)
// {
// 	int		v[] = {1, 2, 3};
// 	int		e[] = {3, 1, 2};
// 	t_list	*a;
// 	t_list	*b;

// 	a = NULL;
// 	b = make_stack(v, 3);
// 	if (!b)
// 		return (0);
// 	rrb(&b);
// 	if (!check_stack(b, e, 3))
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }

// static int	test_rrr(void)
// {
// 	int		av[] = {1, 2, 3};
// 	int		bv[] = {4, 5, 6};
// 	int		ea[] = {3, 1, 2};
// 	int		eb[] = {6, 4, 5};
// 	t_list	*a;
// 	t_list	*b;

// 	a = make_stack(av, 3);
// 	b = make_stack(bv, 3);
// 	if (!a || !b)
// 		return (free_stacks(&a, &b), 0);
// 	rrr(&a, &b);
// 	if (!check_stack(a, ea, 3) || !check_stack(b, eb, 3))
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }

// static int	test_edge_cases(void)
// {
// 	int		v[] = {42};
// 	t_list	*a;
// 	t_list	*b;

// 	a = make_stack(v, 1);
// 	b = NULL;
// 	if (!a)
// 		return (0);
// 	sa(&a);
// 	sb(&b);
// 	ss(&a, &b);
// 	pa(&a, &b);
// 	pb(&a, &b);
// 	if (a != NULL || !check_stack(b, v, 1))
// 		return (free_stacks(&a, &b), 0);
// 	pa(&a, &b);
// 	if (!check_stack(a, v, 1) || b != NULL)
// 		return (free_stacks(&a, &b), 0);
// 	ra(&a);
// 	rb(&b);
// 	rr(&a, &b);
// 	rra(&a);
// 	rrb(&b);
// 	rrr(&a, &b);
// 	if (!check_stack(a, v, 1) || b != NULL)
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }


// static int	test_ss_only_a(void)
// {
// 	int		av[] = {10, 20};
// 	int		bv[] = {30};
// 	int		ea[] = {20, 10};
// 	t_list	*a;
// 	t_list	*b;

// 	a = make_stack(av, 2);
// 	b = make_stack(bv, 1);
// 	if (!a || !b)
// 		return (free_stacks(&a, &b), 0);
// 	ss(&a, &b);
// 	if (!check_stack(a, ea, 2) || !check_stack(b, bv, 1))
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }


// static int	test_ss_only_b(void)
// {
// 	int		av[] = {30};
// 	int		bv[] = {10, 20};
// 	int		eb[] = {20, 10};
// 	t_list	*a;
// 	t_list	*b;

// 	a = make_stack(av, 1);
// 	b = make_stack(bv, 2);
// 	if (!a || !b)
// 		return (free_stacks(&a, &b), 0);
// 	ss(&a, &b);
// 	if (!check_stack(a, av, 1) || !check_stack(b, eb, 2))
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }

// static int	test_ss_neither(void)
// {
// 	int		av[] = {10};
// 	int		bv[] = {20};
// 	t_list	*a;
// 	t_list	*b;

// 	a = make_stack(av, 1);
// 	b = make_stack(bv, 1);
// 	if (!a || !b)
// 		return (free_stacks(&a, &b), 0);
// 	ss(&a, &b);
// 	if (!check_stack(a, av, 1) || !check_stack(b, bv, 1))
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }


// static int	test_rr_only_a(void)
// {
// 	int		av[] = {10, 20, 30};
// 	int		bv[] = {40};
// 	int		ea[] = {20, 30, 10};
// 	t_list	*a;
// 	t_list	*b;

// 	a = make_stack(av, 3);
// 	b = make_stack(bv, 1);
// 	if (!a || !b)
// 		return (free_stacks(&a, &b), 0);
// 	rr(&a, &b);
// 	if (!check_stack(a, ea, 3) || !check_stack(b, bv, 1))
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }

// static int	test_rr_only_b(void)
// {
// 	int		av[] = {40};
// 	int		bv[] = {10, 20, 30};
// 	int		eb[] = {20, 30, 10};
// 	t_list	*a;
// 	t_list	*b;

// 	a = make_stack(av, 1);
// 	b = make_stack(bv, 3);
// 	if (!a || !b)
// 		return (free_stacks(&a, &b), 0);
// 	rr(&a, &b);
// 	if (!check_stack(a, av, 1) || !check_stack(b, eb, 3))
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }


// static int	test_rr_neither(void)
// {
// 	int		av[] = {10};
// 	int		bv[] = {20};
// 	t_list	*a;
// 	t_list	*b;

// 	a = make_stack(av, 1);
// 	b = make_stack(bv, 1);
// 	if (!a || !b)
// 		return (free_stacks(&a, &b), 0);
// 	rr(&a, &b);
// 	if (!check_stack(a, av, 1) || !check_stack(b, bv, 1))
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }

// static int	test_rrr_only_a(void)
// {
// 	int		av[] = {10, 20, 30};
// 	int		bv[] = {40};
// 	int		ea[] = {30, 10, 20};
// 	t_list	*a;
// 	t_list	*b;

// 	a = make_stack(av, 3);
// 	b = make_stack(bv, 1);
// 	if (!a || !b)
// 		return (free_stacks(&a, &b), 0);
// 	rrr(&a, &b);
// 	if (!check_stack(a, ea, 3) || !check_stack(b, bv, 1))
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }

// static int	test_rrr_only_b(void)
// {
// 	int		av[] = {40};
// 	int		bv[] = {10, 20, 30};
// 	int		eb[] = {30, 10, 20};
// 	t_list	*a;
// 	t_list	*b;

// 	a = make_stack(av, 1);
// 	b = make_stack(bv, 3);
// 	if (!a || !b)
// 		return (free_stacks(&a, &b), 0);
// 	rrr(&a, &b);
// 	if (!check_stack(a, av, 1) || !check_stack(b, eb, 3))
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }

// static int	test_rrr_neither(void)
// {
// 	int		av[] = {10};
// 	int		bv[] = {20};
// 	t_list	*a;
// 	t_list	*b;

// 	a = make_stack(av, 1);
// 	b = make_stack(bv, 1);
// 	if (!a || !b)
// 		return (free_stacks(&a, &b), 0);
// 	rrr(&a, &b);
// 	if (!check_stack(a, av, 1) || !check_stack(b, bv, 1))
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }

// static int	test_pa_empty_b(void)
// {
// 	int		av[] = {10, 20};
// 	t_list	*a;
// 	t_list	*b;

// 	a = make_stack(av, 2);
// 	b = NULL;
// 	if (!a)
// 		return (free_stacks(&a, &b), 0);
// 	pa(&a, &b);
// 	if (!check_stack(a, av, 2) || b != NULL)
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }

// static int	test_pb_empty_a(void)
// {
// 	int		bv[] = {10, 20};
// 	t_list	*a;
// 	t_list	*b;

// 	a = NULL;
// 	b = make_stack(bv, 2);
// 	if (!b)
// 		return (free_stacks(&a, &b), 0);
// 	pb(&a, &b);
// 	if (a != NULL || !check_stack(b, bv, 2))
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }

// static int	test_pb_multiple(void)
// {
// 	int		av[] = {10, 20, 30};
// 	int		ea[] = {30};
// 	int		eb[] = {20, 10};
// 	t_list	*a;
// 	t_list	*b;

// 	a = make_stack(av, 3);
// 	b = NULL;
// 	if (!a)
// 		return (free_stacks(&a, &b), 0);
// 	pb(&a, &b);
// 	pb(&a, &b);
// 	if (!check_stack(a, ea, 1) || !check_stack(b, eb, 2))
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }

// static int	test_pa_multiple(void)
// {
// 	int		av[] = {10, 20, 30};
// 	t_list	*a;
// 	t_list	*b;

// 	a = make_stack(av, 3);
// 	b = NULL;
// 	if (!a)
// 		return (free_stacks(&a, &b), 0);
// 	pb(&a, &b);
// 	pb(&a, &b);
// 	pb(&a, &b);
// 	pa(&a, &b);
// 	pa(&a, &b);
// 	pa(&a, &b);
// 	if (!check_stack(a, av, 3) || b != NULL)
// 		return (free_stacks(&a, &b), 0);
// 	free_stacks(&a, &b);
// 	return (1);
// }


// int	main(void)
// {
// 	int	failures;

// 	failures = 0;
// 	failures += print_result("sa", test_sa());
// 	failures += print_result("sb", test_sb());
// 	failures += print_result("ss", test_ss());
// 	failures += print_result("pa / pb", test_pa_pb());
// 	failures += print_result("ra", test_ra());
// 	failures += print_result("rb", test_rb());
// 	failures += print_result("rr", test_rr());
// 	failures += print_result("rra", test_rra());
// 	failures += print_result("rrb", test_rrb());
// 	failures += print_result("rrr", test_rrr());
// 	failures += print_result("edge cases", test_edge_cases());
// 	failures += print_result("ss only A", test_ss_only_a());
// 	failures += print_result("ss only B", test_ss_only_b());
// 	failures += print_result("ss neither", test_ss_neither());
// 	failures += print_result("rr only A", test_rr_only_a());
// 	failures += print_result("rr only B", test_rr_only_b());
// 	failures += print_result("rr neither", test_rr_neither());
// 	failures += print_result("rrr only A", test_rrr_only_a());
// 	failures += print_result("rrr only B", test_rrr_only_b());
// 	failures += print_result("rrr neither", test_rrr_neither());
// 	failures += print_result("pa empty B", test_pa_empty_b());
// 	failures += print_result("pb empty A", test_pb_empty_a());
// 	failures += print_result("pb multiple", test_pb_multiple());
// 	failures += print_result("pa multiple", test_pa_multiple());

// 	return (failures != 0);
// }



















// int	main(void)
// {
// 	int	failures;

// 	failures = 0;
// 	print_result("sa", test_sa());
// 	print_result("sb", test_sb());
// 	print_result("ss", test_ss());
// 	print_result("pa / pb", test_pa_pb());
// 	print_result("ra", test_ra());
// 	print_result("rb", test_rb());
// 	print_result("rr", test_rr());
// 	print_result("rra", test_rra());
// 	print_result("rrb", test_rrb());
// 	print_result("rrr", test_rrr());
// 	print_result("edge cases", test_edge_cases());
// 	print_result("ss only A", test_ss_only_a());
// 	print_result("ss only B", test_ss_only_b());
// 	print_result("ss neither", test_ss_neither());
// 	print_result("rr only A", test_rr_only_a());
// 	print_result("rr only B", test_rr_only_b());
// 	print_result("rr neither", test_rr_neither());
// 	print_result("rrr only A", test_rrr_only_a());
// 	print_result("rrr only B", test_rrr_only_b());
// 	print_result("rrr neither", test_rrr_neither());
// 	print_result("pa empty B", test_pa_empty_b());
// 	print_result("pb empty A", test_pb_empty_a());
// 	print_result("pb multiple", test_pb_multiple());
// 	print_result("pa multiple", test_pa_multiple());
// 	return (failures);
// }











// #include "push_swap.h"

// int	main(int argc, char **argv)
// {
// 	int		strategy;
// 	int		bench;
// 	int		start;
// 	int		count;
// 	int		*numbers;
// 	t_list	*a;
// 	t_list	*current;
// 	t_list *b;

// 	if (argc == 1)
// 		return (0);
// 	if (!parse_args(argc, argv, &strategy, &bench, &start))
// 	{
// 		write(2, "Error\n", 6);
// 		return (1);
// 	}
// 	if (!validate_args(argc, argv, start, &numbers, &count))
// 	{
// 		write(2, "Error\n", 6);
// 		return (1);
// 	}
// 	a = init_stack_a(numbers, count);
// 	free(numbers);
// 	if (!a)
// 	{
// 		write(2, "Error\n", 6);
// 		return (1);
// 	}
// 	// sa(&a);
// 	// current = a;

// 	b = NULL;
// 	// pb(&a, &b);
// 	// pb(&a, &b);

// 	// // sb(&b);
// 	// sb(&b);
// 	// // ss(&a, &b);

// 	// ss(&a, &b);
// 	// pa(&a, &b);

// 	// pb(&a, &b);
// 	// pb(&a, &b);
// 	// ra(&a);

// 	// pb(&a, &b);
// 	// pb(&a, &b);
// 	// rb(&b);

// 	// pb(&a, &b);
// 	// pb(&a, &b);
// 	// rr(&a, &b);

// 	// rra(&a);

// 	// pb(&a, &b);
// 	// pb(&a, &b);
// 	// rrb(&b);

// 	pb(&a, &b);
// 	pb(&a, &b);
// 	rrr(&a, &b);

// 	current = a;

// 	// ft_putendl_fd("Stack A (top -> bottom):", 1);
// 	// while (current)
// 	// {
// 	// 	ft_putnbr_fd(*(int *)current->content, 1);
// 	// 	ft_putchar_fd('\n', 1);
// 	// 	current = current->next;
// 	// }
// 	// ft_putendl_fd("Stack B: empty", 1);

// 	ft_putendl_fd("Stack A (top -> bottom):", 1);
// 	while (current)
// 	{
// 		ft_putnbr_fd(*(int *)current->content, 1);
// 		ft_putchar_fd('\n', 1);
// 		current = current->next;
// 	}
// 	ft_putendl_fd("Stack B (top -> bottom):", 1);
// 	current = b;
// 	while (current)
// 	{
// 		ft_putnbr_fd(*(int *)current->content, 1);
// 		ft_putchar_fd('\n', 1);
// 		current = current->next;
// 	}


// 	ft_lstclear(&a, free);
// 	ft_lstclear(&b, free);
// 	return (0);
// }

