#include "../../push_swap.h"

void    ra(t_list **a)
{
    t_list  *first;
    t_list  *last;

    if (!a || !*a || !(*a)->next)
        return ;
    first = *a;
    *a = first->next;
    first->next = NULL;
    last = *a;
    while (last->next)
        last = last->next;
    last->next = first;
    write(1, "ra\n", 3);
     // ft_putstr("ra\n");
}