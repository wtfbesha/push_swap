#include "../../push_swap.h"

void    rrr(t_list **a, t_list **b)
{
    t_list  *last;
    t_list  *prev;

    if (a && *a && (*a)->next)
    {
        prev = NULL;
        last = *a;
        while (last->next)
        {
            prev = last;
            last = last->next;
        }
        prev->next = NULL;
        last->next = *a;
        *a = last;
    }
    if (b && *b && (*b)->next)
    {
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
    }
    write(1, "rrr\n", 4);
     // ft_putstr("rrr\n");
}