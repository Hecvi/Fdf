 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:31:25 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void     free_split(char **s, int words, int flag)
{
    words--;
    while (words >= 0)
    {
        free(s[words]);
        s[words] = NULL;
        words--;
    }
    free(s);
    s = NULL;
    if (1 == flag)
        write(1, "Memory allocation error\n", 24);
}

void    free_all(char **s, int words, t_ps **a, int flag)
{
    if (1 == flag)
        free_split(s, words, 1);
    else
    {
        free_split(s, words, 0);
        write(1, "Incorrect data\n", 15);
    }
    free_list(a, 0);
    exit(1);
}

void    free_list(t_ps **stack, int flag)
{
    t_ps *tmp;

    tmp = (*stack);
    while (*stack)
    {
        (*stack) = (*stack)->next;
        free(tmp);
        tmp = (*stack);
    }
    if (1 == flag)
        write(1, "Memory allocation error\n", 24);
}

void    free_list_operations(t_operations **operations)
{
    t_operations *tmp;

    tmp = (*operations);
    while (*operations)
    {
        (*operations) = (*operations)->next;
        free(tmp);
        tmp = (*operations);
    }
}
