/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:13:14 by mimatsub          #+#    #+#             */
/*   Updated: 2023/02/06 20:54:54 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// error function
bool digit_check(int argc, char **argv)
{
    // digit 以外をはじく
    // （+-のフラッグを立てる）
    int i;
    int j;

    i = 1; //argc=０は./push_swapなので
    while (i != argc)
    {
        if (ft_strlen(argv[i]) > 11) //from int_check
            return (false);
        j = 0;
        while (argv[i][j] != '\0')
        {
            if ('0' > argv[i][j] || argv[i][j] > '9')
            {
                if (ft_strlen(argv[i]) == 1) // -だけを渡されたときの処理
                    return (false);
                if (!(j == 0 && (argv[i][j] == '+' || argv[i][j] == '-'))) 
                {
                    return (false);        
                }
            }
            j++;
        }
        i++;
    }
    return (true);
}

bool dup_check(int argc, char **argv)
{
    // 引数にダブりがあったらはじく

    int i;
    int j;

    i = 1;
    while(i < argc) //?
    {
        j = i + 1;
        while (j != argc)
        {
            if (ft_strncmp(argv[i], argv[j], 11) == 0)
                return (false);
            j++;
        }
        i++;
    }
    return (true);
}

bool int_check(int argc, char **argv)
{
    // intの範囲を超えていたらはじく
    long num;
    int i;

    i = 1;
    while (i != argc)
    {
        // if (ft_strlen(argv[i]) > 11)// atolを簡略化してるため、long longの値の範囲内で引数を渡したい //桁数を判定 //これdigit_checkでやったほうが時間短縮されるのでは？
        //     return (false); //digit_checkに移しました
        num = ft_atol(argv[i]);
        if (num < INT_MIN || num > INT_MAX)
            return (false);
        i++;
    }
    return (true);
}

bool error_check(int argc, char **argv)
{   
    //arg_check()
    // if (argc < 3) // これはエラーにはならないみたい??
    //     error_swap();
    
    if (digit_check(argc, argv) == false)
        return (false);
    if (dup_check(argc, argv) == false)
        return (false);
    if (int_check(argc, argv) == false)
        return (false);    

    return (true);
}
