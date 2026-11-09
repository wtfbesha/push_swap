#include "../../push_swap.h"

void    rb(t_list **b)
{
    t_list  *first;
    t_list  *last;

    if (!b || !*b || !(*b)->next)
        return ;
    first = *b;
    *b = first->next;
    first->next = NULL;
    last = *b;
    while (last->next)
        last = last->next;
    last->next = first;
    write(1, "rb\n", 3);
     // ft_putstr("rb\n");
}