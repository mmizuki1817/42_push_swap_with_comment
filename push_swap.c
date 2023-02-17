/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:26:18 by mimatsub          #+#    #+#             */
/*   Updated: 2023/02/17 23:32:32 by mimatsub         ###   ########.fr       */
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
    // 3つの数字の大小を条件文で表す方法？
    // 123
    if (a->next->num )

    // 132

    // 213

    // 231

    // 312

    // 321
    
}

void less_than_six(int argc, t_stack *a, t_stack *b)
{
    int i;
    int target;

    // aが3個になるまで、小さい数からbにpush
    i = 0;
    target = 1;
    while (i < argc - 4) 
    {
        if (a->next->order == target) 
        {
            pb(a, b);
            i++;
            target++;
        }
        else 
            ra(a);
    }
    // // 残ったaを３つのルールでソート
    // patarn_three
    // // bをaにpushして戻す
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
    printf("last\n");
    while (a->order != -1)
    {
        printf("%i", a->num);
        a = a->next;
    }
    printf("\n");
    
    while (b->order != -1)
    {
        printf("%i", b->num);
        b = b->next;
    }
    printf("\n");

    ft_putstr_fd("true", 1);

}

// 覚書
// 双方向循環リストのfreeの仕方がわからない。番兵ノードで判断できるはず。
// a を参照するときは毎回NULLじゃないか確認する必要がありそう