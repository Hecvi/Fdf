/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:31:25 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    check_min_elem(t_ps **stack, int end)
{
    t_ps *tmp;

    tmp = (*stack);
    while (tmp && tmp->block == (*stack)->block)
    {
        if (tmp->index > end)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int    check_mid_elem(t_ps **stack, int start, int end)
{
    t_ps *tmp;

    tmp = (*stack);
    while (tmp && tmp->block == (*stack)->block)
    {
        if (tmp->index <= start || tmp->index > end)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int    check_max_elem(t_ps **stack, int end)
{
    t_ps *tmp;

    tmp = (*stack);
    while (tmp && tmp->block == (*stack)->block)
    {
        if (tmp->index <= end)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int    cardinality(t_ps **stack)
{
    int count;
    t_ps *tmp;
    int block;

    count = 0;
    if (!(*stack))
        return (0);
    tmp = (*stack);
    block = (*stack)->block;
    while (tmp && tmp->block == block && !tmp->sort)
    {
        count++;
        tmp = tmp->next;
    }
    return (count);
}

int     check_order_in_stack(t_ps **a)
{
    t_ps *tmp;

    tmp = (*a);
    while (tmp)
    {
        if (tmp->next)
            if (tmp->index > tmp->next->index)
                return (0);
        tmp = tmp->next;
    }
    return (1);
}

int     func_atoi(char *str, int sign, int *indicator)
{
    int						i;
    unsigned long long int	number;

    i = 0;
    number = 0;
    while (check_char(str[i], 2))
        i++;
    sign = str[i] == '-' ? -1 : 1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        number = number * 10 + (str[i] - '0');
        if ((number > MAX && 1 == sign) || (number > MIN && -1 == sign))
        {
            *indicator = -1;
            return (0);
        }
        i++;
    }
    return ((int)number * sign);
}

void    combine(t_operations **operations, char *str1, char *str2, char *str3)
{
    t_operations *tmp;
    t_operations *tmp_next;

    tmp = (*operations);
    if (tmp && tmp->next)
        tmp_next = tmp->next;
    else
        return ;
    while (tmp)
    {
        if (tmp_next)
            if ((!ft_strcmp(tmp->str, str1) && !ft_strcmp(tmp_next->str, str2))
            || (!ft_strcmp(tmp->str, str2) && !ft_strcmp(tmp_next->str, str1)))
            {
                tmp->str = str3;
                tmp->next = tmp_next->next;
                free(tmp_next);
                tmp_next = NULL;
            }
        tmp = tmp->next;
        if (tmp && tmp->next)
            tmp_next = tmp->next;
    }
}
