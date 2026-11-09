#include "../push_swap.h"

void    pb(t_list **a, t_list **b)
{
    t_list  *tmp;

    if (!a || !*a)
        return ;
    tmp = *a;
    *a = (*a)->next;
    tmp->next = *b;
    *b = tmp;
    write(1, "pb\n", 3);
     // ft_putstr("pb\n");
}