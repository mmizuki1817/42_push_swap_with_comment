/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:34:37 by mimatsub          #+#    #+#             */
/*   Updated: 2023/02/11 22:33:50 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/push_swap.h"

/*
bool binary_search(int argc, int *num_cpy)
{
    //find_min_and_max();
    int min;
    int max;
    int i;

    // argc = 1はすでに除外されてる
    // if (argc = 2)
    // {
        //whileにいれてもいいし、ここで特別な処理をしてもよいかも
    // }
    min = num_cpy[0];
    max = num_cpy[0];
    i = 1;
    while (i < argc - 2)
    {
        if (max < num_cpy[i])
            max = num_cpy[i];
        if (min > num_cpy[i])
            min = num_cpy[i];
        i++;
    }
    

    return (true);
} */

//座標圧縮
bool coordinate_compression(int argc, t_stack *a)
{
    // 配列をコピー
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

    //sort cpy
    int tmp;
    int j;
    i = 0;
    while (i < argc - 2)
    {
        j = i + 1;
        while (j < argc - 1)
        {
            if (num_cpy[i] > num_cpy[j])
            {
                tmp = num_cpy[i];
                num_cpy[i] = num_cpy[j];
                num_cpy[j] = tmp;
            }
        j++;
        }
        i++;
    }
    //test
    i = 0;
    while (i < argc-1)
    {
        printf("order:num_cpy[%i]%i\n", i, num_cpy[i]);
        i++;
    }

    // if (binary_search(argc, num_cpy) == false)
    //     return(false);
    //Aが「全体の中で何番目に小さいか」とは、Aが「数列 B
 //の何番目の要素に相当するか」を意味する
    
    
    
    return (true);
}

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
t_stack *put_into_stack(int argc, char **argv)
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
            return (NULL);
        p->next = tmp;
        tmp->prev = p;
        tmp->next = a;
        a->prev = tmp;
        p = tmp;
        i++;
    }
    //printf("%i %i %i %i %i", a->num, a->next->num, a->next->next->num, a->next->next->next->num, a->next->next->next->next->num);
    return (a);
    
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
    t_stack *a;

    a = put_into_stack(argc, argv);
    if (a == NULL)
        return (false);
    //printf("%i %i %i", a->num, a->next->num, a->next->next->num);
    if (coordinate_compression(argc, a) == false) // 座標圧縮
        return (false);
    
    return (true);
}