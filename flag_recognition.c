#include "push_swap.h"
#include <string.h>

int flag_recognition(char *arg, t_strategy *strategy)
{
    if (!strcmp(arg, "--simple"))
        *strategy = SIMPLE;
    return (0);
}