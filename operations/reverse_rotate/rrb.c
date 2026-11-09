#include "../../push_swap.h"

void    rrb(t_list **b)
{
    t_list  *last;
    t_list  *prev;

    if (!b || !*b || !(*b)->next)
        return ;
    prev = NULL;
    last = *b;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *b;
    *b = last;
    write(1, "rrb\n", 4);
     // ft_putstr("rrb\n");
}