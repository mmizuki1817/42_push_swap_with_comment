/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:26:18 by mimatsub          #+#    #+#             */
/*   Updated: 2023/02/20 13:49:39 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/push_swap.h"

static void	error_print(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);//
}

void sort_three_random_num(t_stack *a)
{
    // 123
    if (a->next->num < a->next->next->num && a->next->next->num < a->prev->num)
        return ;
    // 132
    else if (a->next->num < a->prev->num && a->prev->num < a->next->next->num)
    {
        sa(a);
        ra(a);
    }
    // 213
    else if (a->next->next->num < a->next->num && a->next->num < a->prev->num)
        sa(a);
    // 231
    else if (a->prev->num < a->next->num && a->next->num < a->next->next->num)
        rra(a);
    // 312
    else if (a->next->next->num < a->prev->num && a->prev->num < a->next->num)
        ra(a);
    // 321
    else // a->prev->num < a->next->next->num && a->next->next->num < a->next->num
    {
        sa(a);
        rra(a);
    }    
    return ;
}

void sort_three_random_num_b(t_stack *b)
{
    // 123
    if (b->next->num < b->next->next->num && b->next->next->num < b->prev->num)
    {
        sb(b);
        rrb(b);
    }  
    // 132
    else if (b->next->num < b->prev->num && b->prev->num < b->next->next->num)
        rb(b);
    
    // 213
    else if (b->next->next->num < b->next->num && b->next->num < b->prev->num)
        rrb(b);
    // 231
    else if (b->prev->num < b->next->num && b->next->num < b->next->next->num)
        sb(b);
    
    // 312
    else if (b->next->next->num < b->prev->num && b->prev->num < b->next->num)
    {
        sb(b);
        rb(b);
    }
    // 321
    else // b->prev->num < b->next->next->num && b->next->next->num < b->next->num
        return ;
}

void less_than_six(int argc, t_stack *a, t_stack *b)
{
    int i;
    int middle; //middleではない

    //check
    a = a->next;
    printf("num\na:");
    while (a->order != -1)
    {
        printf("%i", a->num);
        a = a->next;
    }
    printf("\n");

    // aが3個になるまで、小さい数からbにpush
    i = 0;
    middle = (argc - 1) / 2;
    while (i < argc - 4) 
    {
        if (a->next->order <= middle) 
        {
            pb(a, b);
            i++;
        }
        else 
            ra(a);
    }
    // 残ったaを３つのルールで昇順ソート
    sort_three_random_num(a);
    
    // bを”降順”ソート
    //if (argc == 5) //何もしない

    if (argc == 6 && b->next->order < b->next->next->order)  
        sb(b);
    else if (argc == 7)
        sort_three_random_num_b(b);
 
    // bをaにpushして戻す
    i = 0;
    while (i < argc - 4)
    {
        pa(a, b);
        i++;       
    }       
}

void push_and_swap(int argc, t_stack *a, t_stack *b)
{
    if (argc == 2)
        return ;
    else if (argc == 3)
    {
        // ２つを比較
        if (a->next->order < a->next->next->order)
            return ;
        else
            return (sa(a));
    }
    else if (argc == 4)
    {
        sort_three_random_num(a);
    }

    //else if (argc == 5)
    else if (argc <= 7)
    {
        return (less_than_six(argc, a, b));
    }
    // else
    //     return (more_than_seven());
    return ;
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    
    if (error_check(argc, argv) == false)
        error_print();
    a = make_list(argc, argv);
    if (a == NULL)
        exit(1); //?
    b = make_node(-1);
    // if (b == NULL)
    // {
    //     //free();
    //     // exit;
    // }
    b->next = b;
    b->prev = b;
    b->order = -1;
    push_and_swap(argc, a, b);

    //free(a);
    a = a->next;
    b = b->next;
    printf("\na:");
    while (a->order != -1)
    {
        printf("%i", a->num);
        a = a->next;
    }
    printf("\nb:");
    
    while (b->order != -1)
    {
        printf("%i", b->num);
        b = b->next;
    }
    printf("\n");

    ft_putstr_fd("true", 1);

}

// 覚書
// bug ./push_swap 1 2 3 -1
// ./push_swap ならうまくいく。orderの順番がおかしくなる。座標圧縮のどっかがおかしい
// -1, -2, 0のときおかしい
// 多分binary serachが変
// low = 0がおかしいのでは？->low=-1にしたら全部いけた。。。なぜ？
// binary serach をちゃんと理解してから考えてほしい

// 双方向循環リストのfreeの仕方がわからない。番兵ノードで判断できるはず。
// a を参照するときは毎回NULLじゃないか確認する必要がありそう