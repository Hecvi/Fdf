/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:31:25 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    zeroing_the_blocks(t_ps **a)
{
    t_ps *tmp;

    tmp = (*a);
    while (tmp)
    {
        tmp->block = 0;
        tmp = tmp->next;
    }
}

void    flipping_to_the_top(t_ps **a, t_ps **b, t_operations **operations)
{
    t_ps *tmp;
    t_ps *tmp_next;

    tmp = (*a);
    while (tmp && tmp->sort == 1)
        tmp = tmp->next;
    while (tmp && tmp->sort != 1 && tmp != (*a))
    {
        tmp_next = tmp;
        rra(a, b, operations);
        tmp = tmp_next;
    }
}

int    find_min(t_ps **stack)
{
    t_ps *tmp;
    t_ps *min;
    int block;
    int minimum;

    if (NULL == (*stack))
        return (0);
    tmp = (*stack);
    min = (*stack);
    block = (*stack)->block;
    minimum = (*stack)->index;
    while (tmp && tmp->block == block)
    {
        if (tmp->index < minimum)
        {
            minimum = tmp->index;
            min = tmp;
        }
        tmp = tmp->next;
    }
    return (min->index);
}

int     find_mid(t_ps **stack)
{
    int mid;
    int count;
    t_ps *tmp;
    int block;

    mid = 0;
    count = 0;
    if (!(*stack))
        return (0);
    if ((*stack)->sort)
        return (0);
    tmp = (*stack);
    block = (*stack)->block;
    while (tmp && tmp->block == block && tmp->sort != 1)
    {
        count++;
        mid = mid + tmp->index;
        tmp = tmp->next;
    }
    return (mid / count);
}

int    find_max(t_ps **stack)
{
    t_ps *tmp;
    t_ps *max;
    int block;
    int maximum;

    if (NULL == (*stack))
        return (0);
    tmp = (*stack);
    max = (*stack);
    block = (*stack)->block;
    maximum = (*stack)->index;
    while (tmp && tmp->block == block)
    {
        if (tmp->index > maximum)
        {
            maximum = tmp->index;
            max = tmp;
        }
        tmp = tmp->next;
    }
    return (max->index);
}