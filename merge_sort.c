/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neric <neric@student.42belgium.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:37:48 by neric             #+#    #+#             */
/*   Updated: 2026/11/06 14:37:58 by neric            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
    sa (swap a):
    sa (swap b):

    ss:



    pa (push a):
    pb (push b):



    ra (rotate a):
    rb (rotate b):

    rr: 


    rra (reverse rotate a):
    rrb (reverse rotate b):
    rrr:



    //////////////////////////////////

    disorder = 0;

    if (disorder)
    {
        // right order (less error)
    }

    if (disorder = 1)
    {
        // worst possible disorder (more errors)
    }


    // function compute_disorder(stack a):
    //     mistakes = 0
    //     total_pairs = 0
    //     for i from 0 to size(a)-1:
    //         for j from i+1 to size(a)-1:
    //             total_pairs += 1
    //             if a[i] > a[j]:
    //                 mistakes += 1
    //     return mistakes / total_pairs
*/


// Merge sort adaptation using two stacks


int *merge_sort(int *list1, int *list2)
{
    int *new_list;
    // ft_a
    
    // if ()

    return new_list;
}

#include <stdlib.h>
#include <stdio.h>
int main()
{
    int arr1[] = { 73, 3,  69, 88, 36, 56, 44, 63, 
        14, 60, 80, 84, 6,  80, 55, 62 };
    int arr2[] = {34, 3, 31, 1, 12, 23, 54, 21, -3, 2,  13};

    // int size_a = sizeof(arr1) / ;

    int res = merge_sort(arr1, arr2);
    int i = 0;

    printf("%d", res);
}