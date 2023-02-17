/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:13:35 by mimatsub          #+#    #+#             */
/*   Updated: 2023/02/17 23:18:54 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void ra(t_stack *a)
{
    t_stack *tmp1;
    t_stack *tmp2;

    tmp1 = a->next;
    tmp2 = a->next->next;
    a->next = tmp2;
    tmp2->prev = a;
    a->prev->next = tmp1;
    tmp1->next = a;
    tmp1->prev = a->prev;
    a->prev = tmp1;
    ft_putstr_fd("ra\n", 1);


}

void rb(t_stack *b)
{
    t_stack *tmp1;
    t_stack *tmp2;

    tmp1 = b->next;
    tmp2 = b->next->next;
    b->next = tmp2;
    tmp2->prev = b;
    b->prev->next = tmp1;
    tmp1->next = b;
    tmp1->prev = b->prev;
    b->prev = tmp1;
    ft_putstr_fd("rb\n", 1);
}