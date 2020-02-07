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
/*
int    check_large_elem(t_ps **stack, int mid)
{
    t_ps *tmp;

    tmp = (*stack);
    while (tmp && tmp->block == (*stack)->block)
    {
        if (tmp->index <= mid)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int    stupid_function(t_ps **a)
{
    t_ps *tmp;

    tmp = (*a);
    while (tmp->next)
        tmp = tmp->next;
    return (tmp->index);
}

void    transfer_from_a_to_b(t_ps **a, t_ps **b, t_operations **operations)
{
    int block;
    t_ps *tmp;
    t_ps *tmp_next;

    tmp = (*a);
    block = (*a)->block;
    while (tmp && tmp->block == block)
    {
        tmp_next = tmp->next;
        pb(a, b, operations);
        tmp = tmp_next;
    }
}

void    check_sort_stack_b_and_a(t_ps **a, t_ps **b, t_operations **operations)
{
    if (cardinality(b) >= 1 && cardinality(b) <= 3)
    {
        if (3 == cardinality(b))
            sort_of_three_num_in_b(a, b, operations);
        else if ((*b)->next && ((*b)->next->index < (*b)->index))
            sb(b, a, operations);
        while (*b)
        {
            (*b)->sort = 1;
            pa(b, a, operations);
            ra(a, b, operations);
        }
    }
    help_with_operations_in_a(a, b, operations);
    if (cardinality(a) <= 2 && cardinality(a) >= 1)
    {
        if (2 == cardinality(a))
        {
            if ((*a)->next && ((*a)->next->index < (*a)->index))
                sa(a, b, operations);
            (*a)->sort = 1;
            ra(a, b, operations);
        }
        (*a)->sort = 1;
        ra(a, b, operations);
    }
}

void    help_with_operations_in_a(t_ps **a, t_ps **b, t_operations **operations)
{
    int min;
    t_ps *tmp;
    t_ps *tmp_next;

    tmp = (*a);
    min = stupid_function(a);
    while (tmp && tmp->block == (*a)->block)
    {
        tmp_next = tmp->next;
        if (tmp_next && (min + 1) == tmp_next->index && (min + 2) == tmp->index)
        {
            sa(a, b, operations);
            tmp = (*a);
        }
        if ((min + 1) == tmp->index)
        {
            min++;
            tmp->sort = 1;
            ra(a, b, operations);
            tmp = tmp_next;
        }
        else
            break ;
    }
}

int    fuc_norm(t_ps **a, t_ps **b, t_operations **operations, t_ps **tmp)
{
    int min;

    min = find_min(b);
    if ((*tmp)->index == min)
    {
        (*tmp)->sort = 1;
        pa(b, a, operations);
        ra(a, b, operations);
        return (1);
    }
    return (0);
}
*/
