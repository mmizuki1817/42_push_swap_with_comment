/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:34:37 by mimatsub          #+#    #+#             */
/*   Updated: 2023/02/09 10:52:04 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/push_swap.h"

/*
bool coordinate_compression(int argc)
{
    int *num_cpy;
    int i;
    t_stack *p;

    num_cpy = malloc(sizeof(int) * (argc - 1)); //argc > 1    
    if (num_cpy == NULL)
    {
        //free (list);
        //free (num_cpy);
        return (false);
    }
    i = 0;
    p = a;
    p = a->next;
    while (i < argc - 1)// p->order=-1
    {
        num_cpy[i] = p->num;
        p = p->next;
        printf("num_cpy[%i]%i \n", i, num_cpy[i]);
        i++;

    }
    return (true);
}*/

t_stack *make_node(int num)
{
    t_stack *tmp = malloc(sizeof(t_stack));
    if (tmp == NULL) // mallocの失敗などはErrorを表示して抜ける？そのまま抜ける？ 
    {
        // while (a != NULL)
        // {
        //     free_tmp = a->next;
        //     free(a);
        //     a = free_tmp;
        // }
        return (NULL);
    }
    tmp->num = num;
    tmp->next = NULL;
    tmp->prev = NULL;
    tmp->order = 0;
    return (tmp);
}

// 引数を数字にする
// 双方向循環リストの実装（stack aのnumにひとつづつ数字を入れていく）
bool put_into_stack(int argc, char **argv, t_stack **a)
{
    int i = 1;
  
    t_stack *a;
    
    a = make_node(-1);// 番兵ノード数値は？？先にorderに負の値を入れてしまえばよいのでは？？
    a->next = a;
    a->prev = a;
    a->order = -1;
    t_stack *p = a;

    t_stack *tmp = NULL;
    while (i < argc)
    {
        tmp = make_node(ft_atoi(argv[i]));
        if (tmp == NULL)
            return (false);
        p->next = tmp;
        tmp->prev = p;
        tmp->next = a;
        a->prev = tmp;
        p = tmp;
        i++;
    }
    //printf("%i %i %i %i %i", a->num, a->next->num, a->next->next->num, a->next->next->next->num, a->next->next->next->next->num);
    return (true);
    
    // t_stack *free_tmp;
    // while (a != NULL) //while の条件考えないと
    // {
    //     free_tmp = a->next;
    //     free(a);
    //     a = free_tmp;
    // }
    // return (true);
}

bool make_list(int argc, char **argv)
{
    t_stack **a;

    if (put_into_stack(argc, argv, a) == false)
        return (false);
    //if (coordinate_compression(argc) == false) // 座標圧縮
    //    return (false);
    return (true);
}