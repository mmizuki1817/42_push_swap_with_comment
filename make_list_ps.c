/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:34:37 by mimatsub          #+#    #+#             */
/*   Updated: 2023/02/20 13:49:54 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/push_swap.h"

// リストaにおけるnodeを作る
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
    // 番兵ノードのnumにargcの値を入れたら毎回argc渡さないでよくなるの便利そう？
    if (a == NULL)
    {
        //free();
        return(NULL);
    }
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

t_stack *make_list(int argc, char **argv)
{
    t_stack *a;

    a = put_into_stack(argc, argv);
    if (a == NULL)
        return (NULL);
    //printf("%i %i %i", a->num, a->next->num, a->next->next->num);
    if (coordinate_compression(argc, a) == false) // 座標圧縮
        return (NULL);
    //printf("num:%i %i %i %i %i\n", a->num, a->next->num, a->next->next->num, a->next->next->next->num, a->next->next->next->next->num);
    //printf("order:%i %i %i %i %i", a->order, a->next->order, a->next->next->order, a->next->next->next->order, a->next->next->next->next->order);
    //exit(1);
    return (a);
}