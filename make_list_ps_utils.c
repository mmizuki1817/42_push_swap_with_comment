/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list_ps_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:53:44 by mimatsub          #+#    #+#             */
/*   Updated: 2023/02/14 19:58:34 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/push_swap.h"

void binary_search(int argc, int *num_cpy, t_stack *a)
{
    // 二分探索->orderに順番に入れてる
    // 原理はよくわかんないし、エラーチェックもしてないけど、できてはいる。
    // https://dev.grapecity.co.jp/support/powernews/column/clang/054/page03.htm
    
    int target;
    int middle;
    int low;
    int high;
    int i;

    a = a->next;// １個目はダミーのため
    i = 0;
    while (i < argc - 1)
    {
        target = a->num;
        low = 0;
        high = argc - 1;
        while (low <= high)
        {
            middle = (low + high) / 2; 
            if (num_cpy[middle - 1] == target)
            {
                a->order = middle;
                a = a->next;
                break;
            }
            else if (num_cpy[middle - 1] < target)
                low = middle + 1;
            else
                high = middle - 1;
        }
        i++;
    }
    //test
    i = 0;
    while (i < argc)
    {
        printf("%i", a->order);
        a = a->next;
        i++;
    }
}

void sorting_cpy(int argc, int *num_cpy)
{
    //num_cpyを昇順にソート
    int i;
    int j;
    int tmp;

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
        printf("num_cpy[%i]%i\n", i, num_cpy[i]);
        i++;
    }
    return ;
}

// リストaにおけるnumを配列num_cpyにコピー
int *cpy_a_num(int argc, t_stack *a)
{
    int *num_cpy;
    int i;
    t_stack *p;
    
    num_cpy = malloc(sizeof(int) * (argc - 1)); //argc > 1    
    if (num_cpy == NULL)
    {
        //free (list);
        //free (num_cpy);
        return (NULL);
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
    return (num_cpy);
}

//座標圧縮
bool coordinate_compression(int argc, t_stack *a)
{
    int *num_cpy;

    num_cpy = cpy_a_num(argc, a);
    if (num_cpy == NULL)
        return (false); 
    sorting_cpy(argc, num_cpy);    
    binary_search(argc, num_cpy, a);
    free(num_cpy);
    return (true);
}