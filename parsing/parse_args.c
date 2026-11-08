/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:37:48 by neric             #+#    #+#             */
/*   Updated: 2026/11/06 14:37:58 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int main(int argc, char *argv[])
{
    int *list_input_argv;

    if (argc)
        return (NULL);
    list_input_argv = ft_atoi(argv[2]);
    if (!list_input_argv)
        return ("Error");
    if (argv[1] == "--simple") {

    }
    if (argv[1] == "--medium") {

    }
    if (argv[1] == "--complex") {

    }
    if (argv[1] == "--adaptive") {

    }
    if (argv[2] == "--bench") {

    }

   return (0);
}


// sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr

/*
    sa
    sb
    ss
    pa
    pb
    ra
    rb
    rr
    rra
    rrb
    rrr
*/


/*
stacks are six arguments
split by space

1
2
3
4
5
6

*/