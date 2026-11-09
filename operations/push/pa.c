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