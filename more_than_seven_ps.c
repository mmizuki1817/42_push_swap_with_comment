/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_seven_ps.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizuki <mizuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:18:24 by mizuki            #+#    #+#             */
/*   Updated: 2023/02/28 19:24:31 by mizuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/push_swap.h"

void sort_three_random_num_with_other_node(t_stack *a)
{
    // 213
    if (a->next->next->num < a->next->num && a->next->num < a->prev->num)
        sa(a);
    /*// 132
    else if (a->next->num < a->prev->num && a->prev->num < a->next->next->num)
    {
        ra(a);
        sa(a);
        rra(a);
    }
    // 312
    else if (a->next->next->num < a->prev->num && a->prev->num < a->next->num)
    {
        sa(a);
        ra(a);
        sa(a);
        rra(a);
    }->まとめる*/
    else if ((a->next->num < a->prev->num && a->prev->num < a->next->next->num) || \
    (a->next->next->num < a->prev->num && a->prev->num < a->next->num)) //123 //312
    {
        if (a->next->next->num < a->prev->num && a->prev->num < a->next->num)
            sa(a);
        ra(a);
        sa(a);
        rra(a);
    }
    /*// 231
    else if (a->prev->num < a->next->num && a->next->num < a->next->next->num)
    {
        ra(a);
        sa(a);
        rra(a);
        sa(a);
    }    
    // 321
    else if (a->prev->num < a->next->next->num && a->next->next->num < a->next->num)
    {
        sa(a);
        ra(a);
        sa(a);
        rra(a);
        sa(a);
    }->まとめる*/
    else if ((a->prev->num < a->next->next->num && a->next->next->num < a->next->num) || \
    (a->prev->num < a->next->num && a->next->num < a->next->next->num)) // 321 //231
    {
        if (a->prev->num < a->next->next->num && a->next->next->num < a->next->num)
            sa(a);
        ra(a);
        sa(a);
        rra(a);
        sa(a);
    }    
    // 123
    //if (a->next->num < a->next->next->num && a->next->next->num < a->prev->num)
    return ;
}

void sort_less_than_three_with_other_node(t_stack *a)
{
    int g;
    int count;

    a = a->next;
    g = a->group;
    count = 0;

    while (a->order != -1)
    {
        count++;
        a = a->next;
    }
    //ソートが1個の場合
    if (count == 1)
        return ;
    else if (count == 2) // 2この場合
    {
        if (a->next->order > a->next->next->order)
            sa(a);
        return ;
    }     
    else // (count == 3)// ３個の場合
    {
        sort_three_random_num(a);   
    }
    return ;
}

void devide_into_group(int argc, t_stack *a, t_stack *b)
{
    // aの要素が３つ以下になるまでbにpush
    // pushするときは小さいものを半分ずつpushしていき、group化
    int i;
    int delimiter;
    int group;
    int num;
    int push_counter;

    num = argc - 1;
    group = 0;
    while (num > 3)
    {
        num = num - (num / 2); // num/2:bに移す分 num-(num/2):aに残っている分
        group++;
    }

    // aの小さい要素半分をbへpushを繰り返す
    // gを更新して、グループ分けを行う
    i = 0;
    push_counter = (argc - 1) / 2; //この回数分だけpushしたい
    delimiter = (argc - 1) - ((argc - 1) / 2); // 区切りの値
    //printf("group%i delimiter%i counter%i\n", group, delimiter, push_counter);
    //printf("firstgroup%i del%i\n", group, delimiter);
    while (group > 0)
    {
        if (push_counter == 0) // 半分がbにプッシュされた時
        {
            group--;
            push_counter = delimiter / 2;
            delimiter = (delimiter + (argc - 1) + 1) / 2; // aに残っているうちの半分をdelimiterの数に設定
            //printf("group%i delimiter%i counter%i\n", group, delimiter, push_counter);
            //printf("group%i del%i ps_counter%i\n", group, delimiter, push_counter);
        }
        else if (a->next->order < delimiter) // 半分より小さい時
        {
            a->next->group = group;
            pb(a, b);
            push_counter--;
            
        }
        else // 半分より大きい時
        {
            a->group = 0;
            ra(a);
        }
        //printf("%i", a->next->order);
    }
}

void more_than_seven(int argc, t_stack *a, t_stack *b)
{
    devide_into_group(argc, a, b);

    sort_less_than_three_with_other_node(a);
    /*
    // groupの数をカウント
    int g;
    int count;
    t_stack *p;
    
    // int n = 9;
    // while (n--)
    // {
    //     printf("b->group%i\n", b->group);
    //     b = b->next;
    // }
    //return;
    p = b;
    p = b->next;
    count = 0;
    g = p->group;
    printf("group%i\n", g); 
    while (g == p->group)
    {
        count++;
        p = p->next;
    }
    printf("count%i\n", count);
    //if (count == 0)
    //    return;
    if (count == 1)
        pa(a, b);
    else if (count == 2)
    {
        if (b->next->order < b->next->next->order)  
            sb(b);
        pa(a, b);
        pa(a, b);
    }
    else if (count <= 3)
    {
        sort_three_random_num_b(b);
        while (count--)
            pa(a, b);
        return;
    }    
    else if (count > 3)
        exit(1);
*/
    return ;

}