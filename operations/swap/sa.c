#include "../push_swap.h"

void    sa(t_list **a)
{
    t_list  *first;
    t_list  *second;

    if (!a || !*a || !(*a)->next)
        return ;
    first = *a;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *a = second;
    write(1, "sa\n", 3);
    // ft_putstr("sa\n");
}