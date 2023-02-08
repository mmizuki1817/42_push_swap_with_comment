/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:26:18 by mimatsub          #+#    #+#             */
/*   Updated: 2023/02/08 23:55:37 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/push_swap.h"

// 要素数を数える
// stack Aにいれながら（？）座標圧縮
// 要素数に応じてぱたー？


// 座標圧縮も入れていく



/*
// 座標圧縮
{
    // 昇順にソートする？
    //二分探索
}*/

static void	error_print(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);//
}

/*
bool push_swap(int argc, char **argv)
{
    if (argc == 2)
        return (true);
    if (argc == 3)
    {
        num_count_two()
    }
        


}*/

int main(int argc, char **argv)
{
    if (error_check(argc, argv) == false)
        error_print();
    if (make_list(argc, argv) == false)
        exit(1); //?
    
    // if (push_swap(argc, argv) == false)
    //     exit(1);
    ft_putstr_fd("true", 1);

}

// 覚書
// listのaが関数で消えてしまう。ダブルポインタで渡さないといけないみたい
// 双方向循環リストのfreeの仕方がわからない。番兵ノードで判断できるはず。