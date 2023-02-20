/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:13:58 by mimatsub          #+#    #+#             */
/*   Updated: 2023/02/20 01:52:32 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"


void rra(t_stack *a)
{
    t_stack *tmp1;
    t_stack *tmp2;

    tmp1 = a->prev;
    tmp2 = a->prev->prev;
    a->prev = tmp2;
    tmp2->next = a;
    a->next->prev = tmp1;
    tmp1->next = a->next;
    a->next = tmp1;
    tmp1->prev = a;
}

void rrb(t_stack *b)
{
    t_stack *tmp1;
    t_stack *tmp2;

    tmp1 = b->prev;
    tmp2 = b->prev->prev;
    b->prev = tmp2;
    tmp2->next = b;
    b->next->prev = tmp1;
    tmp1->next = b->next;
    b->next = tmp1;
    tmp1->prev = b;
}