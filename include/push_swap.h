/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:09:04 by mimatsub          #+#    #+#             */
/*   Updated: 2023/02/09 10:51:59 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>//test for printf

typedef struct stack
{
    int num;
    int order;
    struct stack *next;
    struct stack *prev;
}t_stack;

// error_ps
bool digit_check(int argc, char **argv);
bool dup_check(int argc, char **argv);
bool int_check(int argc, char **argv);
bool error_check(int argc, char **argv);

// make_list_ps
t_stack *make_node(int num);
//bool put_into_stack(int argc, char **argv);
bool put_into_stack(int argc, char **argv, t_stack **a);
bool make_list(int argc, char **argv);
#endif
