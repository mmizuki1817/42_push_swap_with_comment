/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:12:57 by mimatsub          #+#    #+#             */
/*   Updated: 2023/02/20 13:02:43 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void pa(t_stack *a, t_stack *b)
{
    t_stack *tmp1;
    t_stack *tmp2;

    tmp1 = b->next;
    tmp2 = b->next->next;
    b->next = tmp2;
    tmp2->prev = b;
    
    a->next->prev = tmp1;
    tmp1->next = a->next;
    tmp1->prev = a;
    a->next = tmp1;
    
    ft_putstr_fd("pa\n", 1);
    //printf("a:%i %i %i \n", a->num, a->next->num, a->next->next->num);
}

void pb(t_stack *a, t_stack *b)
{
    t_stack *tmp1;
    t_stack *tmp2;

    tmp1 = a->next;
    tmp2 = a->next->next;
    a->next = tmp2;
    tmp2->prev = a;
    b->next->prev = tmp1;
    tmp1->next = b->next;
    tmp1->prev = b;
    b->next = tmp1;
    ft_putstr_fd("pb\n", 1);
    //printf("b:%i %i %i \n", b->num, b->next->num, b->next->next->num);
}
