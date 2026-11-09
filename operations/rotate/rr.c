#include "../push_swap.h"

void    rr(t_list **a, t_list **b)
{
    t_list  *first;
    t_list  *last;

    if (a && *a && (*a)->next)
    {
        first = *a;
        *a = first->next;
        first->next = NULL;
        last = *a;
        while (last->next)
            last = last->next;
        last->next = first;
    }
    if (b && *b && (*b)->next)
    {
        first = *b;
        *b = first->next;
        first->next = NULL;
        last = *b;
        while (last->next)
            last = last->next;
        last->next = first;
    }
    write(1, "rr\n", 3);
     // ft_putstr("rr\n");
}