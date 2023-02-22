/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:09:04 by mimatsub          #+#    #+#             */
/*   Updated: 2023/02/20 14:05:45 by mimatsub         ###   ########.fr       */
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

// less_than_six_ps
void less_than_six(int argc, t_stack *a, t_stack *b);
void sort_three_random_num(t_stack *a);
void sort_three_random_num_b(t_stack *b);


// push_swap_ps

void push_and_swap(int argc, t_stack *a, t_stack *b);

// push && swap && rotate && reverse_rotate
void pa(t_stack *a, t_stack *b); //ok
void pb(t_stack *a, t_stack *b);
void sa(t_stack *a); //ok
void sb(t_stack *b);
void ra(t_stack *a); //ok
void rb(t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);


#endif

// ./push_swap | grep -e "sa" -e "sb" -e "pa" -e "pb" -e "ra" -e "rb" -e "rra" -e "rrb"| wc -l