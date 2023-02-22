/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:26:18 by mimatsub          #+#    #+#             */
/*   Updated: 2023/02/20 14:37:27 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/push_swap.h"

static void	error_print(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);//
}

void more_than_seven(int argc, t_stack *a, t_stack *b)
{
    int i;
    int delimiter;
    int count;

    // aの小さいほう半分をbへ
    i = 0;
    delimiter = (argc - 1) / 2;
    while (i < argc - 4)
    {
        if (a->next->order <= delimiter)
        {
            pb(a, b);
            i++;
        }
        else
            ra(a);
    }
    //bのノード数をカウント
    b = b->next;
    while (b->order != -1)
    {
        count++;
        b = b->next;
    }
    if (count < 4)
        sort_three_random_num_b(b);


    //delimiter = delimiter / 2;


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
    else
        return (more_than_seven(argc, a, b));
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
// 双方向循環リストのfreeの仕方がわからない。番兵ノードで判断できるはず。
// a を参照するときは毎回NULLじゃないか確認する必要がありそう