#include "../push_swap.h"

void    sb(t_list **b)
{
    t_list  *first;
    t_list  *second;

    if (!b || !*b || !(*b)->next)
        return ;
    first = *b;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *b = second;
    write(1, "sb\n", 3);
    // ft_putstr("sb\n");
}