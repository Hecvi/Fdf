/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_usual.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:31:25 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    for_five_num(t_ps **a, t_ps **b, t_operations **operations, char **av)
{
    int max;

    max = find_max(a);
    if (max <= 5)
    {
        if (!check_order_in_stack(a))
        {
            if (1 == max)
            {
                free_list(a, 0);
                exit(0);
            }
            if (2 == max)
                sa(a, b, operations);
            else if (3 == max)
                sort_of_three_num_in_a(a, b, operations);
            else if (4 == max)
                sort_of_four_num(a, b, operations);
            else if (5 == max)
                sort_of_five_num(a, b, operations);
        }
        the_end_of_sorting(a, operations, av);
    }
}

void    sort_of_two_num(t_ps **a, t_ps **b, t_operations **operations)
{
    t_ps *tmp;
    t_ps *tmp_next;

    tmp = (*b);
    tmp_next = (*b)->next;
    if (tmp->num > tmp_next->num)
        sb(b, a, operations);
    pa(b, a, operations);
    ra(a, b, operations);
    pa(b, a, operations);
    ra(a, b, operations);
}
void    sort_of_three_num_in_b(t_ps **a, t_ps **b, t_operations **operations)
{
    t_ps *n1;
    t_ps *n2;
    t_ps *n3;

    n1 = (*b);
    n2 = n1->next;
    n3 = n2->next;
    if ((n1->num < n2->num) && (n1->num < n3->num) && (n2->num > n3->num))
    {
        sb(b, a, operations);
        rb(b, a, operations);
    }
    else if ((n1->num < n2->num) && (n1->num > n3->num) && (n2->num > n3->num))
        rrb(b, a, operations);
    else if ((n1->num > n2->num) && (n1->num < n3->num) && (n2->num < n3->num))
        sb(b, a, operations);
    else if ((n1->num > n2->num) && (n1->num > n3->num) && (n2->num > n3->num))
    {
        sb(b, a, operations);
        rrb(b, a, operations);
    }
    else if ((n1->num > n2->num) && (n1->num > n3->num) && (n2->num < n3->num))
        rb(b, a, operations);
}

void    sort_of_three_num_in_a(t_ps **a, t_ps **b, t_operations **operations)
{
    t_ps *n1;
    t_ps *n2;
    t_ps *n3;

    n1 = (*a);
    n2 = n1->next;
    n3 = n2->next;
    if ((n1->num < n2->num) && (n1->num < n3->num) && (n2->num > n3->num))
    {
        sa(a, b, operations);
        ra(a, b, operations);
    }
    else if ((n1->num < n2->num) && (n1->num > n3->num) && (n2->num > n3->num))
        rra(a, b, operations);
    else if ((n1->num > n2->num) && (n1->num < n3->num) && (n2->num < n3->num))
        sa(a, b, operations);
    else if ((n1->num > n2->num) && (n1->num > n3->num) && (n2->num > n3->num))
    {
        sa(a, b, operations);
        rra(a, b, operations);
    }
    else if ((n1->num > n2->num) && (n1->num > n3->num) && (n2->num < n3->num))
        ra(a, b, operations);
}

void sort_of_four_num(t_ps **a, t_ps **b, t_operations **operations)
{
    t_ps    *tmp;
    t_ps    *tmp_next;
    int     i;

    i = 0;
    tmp = (*a);
    while (i++ < 4)
    {
        tmp_next = tmp->next;
        if (tmp->index > 2)
            pb(a, b, operations);
        else
            ra(a, b, operations);
        tmp = tmp_next;
    }
    tmp = (*a);
    tmp_next = tmp->next;
    if (tmp->index > tmp_next->index)
        ra(a, b, operations);
    sort_of_two_num(a, b, operations);
}

void sort_of_five_num(t_ps **a, t_ps **b, t_operations **operations)
{
    t_ps    *tmp;
    t_ps    *tmp_next;
    int     i;

    i = 0;
    tmp = (*a);
    while (i++ < 5)
    {
        tmp_next = tmp->next;
        if (tmp->index > 3)
            pb(a, b, operations);
        else
            ra(a, b, operations);
        tmp = tmp_next;
    }
    sort_of_three_num_in_a(a, b, operations);
    sort_of_two_num(a, b, operations);
}
