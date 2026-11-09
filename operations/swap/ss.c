#include "../../push_swap.h"

void    ss(t_list **a, t_list **b)
{
    t_list  *tmp;

    if (a && *a && (*a)->next)
    {
        tmp = (*a)->next;
        (*a)->next = tmp->next;
        tmp->next = *a;
        *a = tmp;
    }
    if (b && *b && (*b)->next)
    {
        tmp = (*b)->next;
        (*b)->next = tmp->next;
        tmp->next = *b;
        *b = tmp;
    }
    write(1, "ss\n", 3);
    // ft_putstr("ss\n");
}