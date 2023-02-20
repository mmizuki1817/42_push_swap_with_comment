/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:11:57 by mimatsub          #+#    #+#             */
/*   Updated: 2023/02/20 13:03:24 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

//リストの要素数が1以下？（2以下？）のときエラー処理

void sa(t_stack *a)
{
    t_stack *tmp1;
    t_stack *tmp2;

    tmp1 = a->next;
    tmp2 = a->next->next->next;
    a->next = a->next->next;
    a->next->prev = a;
    a->next->next = tmp1;
    tmp1->next = tmp2;
    tmp2->prev = tmp1;
    tmp1->prev = a->next;

    ft_putstr_fd("sa\n", 1);
    //printf("sa:%i %i\n", a->next->num, a->next->next->num);
}

void sb(t_stack *b)
{
    t_stack *tmp1;
    t_stack *tmp2;

    tmp1 = b->next;
    tmp2 = b->next->next->next;
    b->next = b->next->next;
    b->next->prev = b;
    b->next->next = tmp1;
    tmp1->next = tmp2;
    tmp2->prev = tmp1;
    tmp1->prev = b->next;

    ft_putstr_fd("sb\n", 1);
    //printf("b:%i %i\n", b->next->num, b->next->next->num);
}