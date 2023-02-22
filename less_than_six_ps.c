/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_six_ps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:03:38 by mimatsub          #+#    #+#             */
/*   Updated: 2023/02/20 14:38:29 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void sort_three_random_num(t_stack *a)
{
    // 123
    if (a->next->num < a->next->next->num && a->next->next->num < a->prev->num)
        return ;
    // 132
    else if (a->next->num < a->prev->num && a->prev->num < a->next->next->num)
    {
        sa(a);
        ra(a);
    }
    // 213
    else if (a->next->next->num < a->next->num && a->next->num < a->prev->num)
        sa(a);
    // 231
    else if (a->prev->num < a->next->num && a->next->num < a->next->next->num)
        rra(a);
    // 312
    else if (a->next->next->num < a->prev->num && a->prev->num < a->next->num)
        ra(a);
    // 321
    else // a->prev->num < a->next->next->num && a->next->next->num < a->next->num
    {
        sa(a);
        rra(a);
    }    
    return ;
}

void sort_three_random_num_b(t_stack *b)
{
    // 123
    if (b->next->num < b->next->next->num && b->next->next->num < b->prev->num)
    {
        sb(b);
        rrb(b);
    }  
    // 132
    else if (b->next->num < b->prev->num && b->prev->num < b->next->next->num)
        rb(b);
    
    // 213
    else if (b->next->next->num < b->next->num && b->next->num < b->prev->num)
        rrb(b);
    // 231
    else if (b->prev->num < b->next->num && b->next->num < b->next->next->num)
        sb(b);
    
    // 312
    else if (b->next->next->num < b->prev->num && b->prev->num < b->next->num)
    {
        sb(b);
        rb(b);
    }
    // 321
    else // b->prev->num < b->next->next->num && b->next->next->num < b->next->num
        return ;
}

void less_than_six(int argc, t_stack *a, t_stack *b)
{
    int i;
    int delimiter;

    //check
    a = a->next;
    printf("num\na:");
    while (a->order != -1)
    {
        printf("%i", a->num);
        a = a->next;
    }
    printf("\n");

    // aが3個になるまで、小さい数からbにpush
    i = 0;
    delimiter = (argc - 1) / 2;
    while (i < argc - 4) 
    {
        if (a->next->order <= delimiter) 
        {
            pb(a, b);
            i++;
        }
        else 
            ra(a);
    }
    // 残ったaを３つのルールで昇順ソート
    sort_three_random_num(a);
    
    // bを”降順”ソート
    //if (argc == 5) //何もしない

    if (argc == 6 && b->next->order < b->next->next->order)  
        sb(b);
    else if (argc == 7)
        sort_three_random_num_b(b);
 
    // bをaにpushして戻す
    i = 0;
    while (i < argc - 4)
    {
        pa(a, b);
        i++;       
    }       
}
