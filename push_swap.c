/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:26:18 by mimatsub          #+#    #+#             */
/*   Updated: 2023/02/15 08:59:07 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/push_swap.h"

static void	error_print(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);//
}


void push_and_swap(int argc, t_stack *a)
{
    if (argc == 2)
        return ;
    if (argc == 3)
    {
        // ２つを比較
        if (a->next->order < a->next->next)
            return ;
        else
            swap_a();
    }
        


}

int main(int argc, char **argv)
{
    t_stack *a;
    
    if (error_check(argc, argv) == false)
        error_print();
    a = make_list(argc, argv);
    if (a == NULL)
        exit(1); //?
    push_and_swap(argc, a);

    //free(a);
    ft_putstr_fd("true", 1);

}

// 覚書
// listのaが関数で消えてしまう。ダブルポインタで渡さないといけないみたい->static関数使ってもよい？
// 双方向循環リストのfreeの仕方がわからない。番兵ノードで判断できるはず。