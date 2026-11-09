#include "../../push_swap.h"

void    pa(t_list **a, t_list **b)
{
    t_list  *tmp;

    if (!b || !*b)
        return ;
    tmp = *b;
    *b = (*b)->next;
    tmp->next = *a;
    *a = tmp;
    write(1, "pa\n", 3);
     // ft_putstr("pa\n");
}
#include "../../push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void print_stack(char *name, t_list *stack)
{
    printf("%s: ", name);
    while (stack)
    {
        printf("%d ", *(int *)stack->content);
        stack = stack->next;
    }
    printf("\n");
}

t_list *new_node(int value)
{
    t_list  *node;
    int     *content;

    node = malloc(sizeof(t_list));
    content = malloc(sizeof(int));
    if (!node || !content)
        return (NULL);
    *content = value;
    node->content = content;
    node->next = NULL;
    return (node);
}

int main(void)
{
    t_list  *a;
    t_list  *b;

    // Stack A: 1 -> 2 -> 3
    a = new_node(1);
    a->next = new_node(2);
    a->next->next = new_node(3);

    // Stack B: 4 -> 5
    b = new_node(4);
    b->next = new_node(5);

    printf("BEFORE pa:\n");
    print_stack("A", a);
    print_stack("B", b);

    printf("\n");
    pa(&a, &b);

    printf("\nAFTER pa:\n");
    print_stack("A", a);
    print_stack("B", b);

    return (0);
}