/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:09:04 by mimatsub          #+#    #+#             */
/*   Updated: 2023/02/17 23:18:16 by mimatsub         ###   ########.fr       */
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
t_stack *put_into_stack(int argc, char **argv);
t_stack *make_list(int argc, char **argv);

// make_list_ps_utils
void binary_search(int argc, int *num_cpy, t_stack *a);
void sorting_cpy(int argc, int *num_cpy);
int *cpy_a_num(int argc, t_stack *a);
bool coordinate_compression(int argc, t_stack *a);

// push_swap_ps

void push_and_swap(int argc, t_stack *a, t_stack *b);

// push && swap && rotate && reverse_rotate
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void sa(t_stack *a);
void sb(t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);


#endif
