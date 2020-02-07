/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:31:25 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    general_sort_one(t_ps **a, t_ps **b, char **av)
{
    t_ps *tmp; //
    t_operations *operations;

    operations = NULL;
    for_five_num(a, b, &operations, av);
    if (check_order_in_stack(a))
        the_end_of_sorting(a, &operations, av);
    sort_two(a, b, &operations);
    sort_three(a, b, &operations);
    tmp = (*a);             ////////////////////////////
    printf("stack A\n");
    while (tmp)
    {
        printf("%d\n", (tmp)->index);
        tmp = tmp->next;
    }
    tmp = (*b);
    printf("stack B\n");
    while (tmp)
    {
        printf("%d\n", (tmp)->index);
        tmp = tmp->next;
    }
//    the_end_of_sorting(a, &operations, av);
}

void    make_sort_all(t_ps **stack)
{
    t_ps *tmp;

    tmp = (*stack);
    while (tmp)
    {
        if (!tmp->sort && tmp->block == (*stack)->block)
            tmp->sort = 1;
        tmp = tmp->next;
    }
}

void    sort_three_el_up(t_ps **a, t_ps **b, t_operations **operations)
{
    t_ps *n1;
    t_ps *n2;
    t_ps *n3;

    n1 = (*a);
    n2 = n1->next;
    n3 = n2->next;
    if (!n1->sort && n1->next && n2->sort)
        n1->sort = 1;
    else if (2 == cardinality(a) && (n1->index > n2->index))
    {
        n1->sort = 1;
        n2->sort = 1;
        sa(a, b, operations);
    }
    if ((n1->num < n2->num) && (n1->num < n3->num) && (n2->num > n3->num))
        min_max_mid_top_a(a, b, operations);
    else if ((n1->num < n2->num) && (n1->num > n3->num) && (n2->num > n3->num))
        mid_max_min_top_a(a, b, operations);
    else if ((n1->num > n2->num) && (n1->num < n3->num) && (n2->num < n3->num))
        mid_min_max_top_a(a, b, operations);
    else if ((n1->num > n2->num) && (n1->num > n3->num) && (n2->num > n3->num))
        max_mid_min_top_a(a, b, operations);
    else if ((n1->num > n2->num) && (n1->num > n3->num) && (n2->num < n3->num))
        max_min_mid_top_a(a, b, operations);
}

void    sort_three(t_ps **a, t_ps **b, t_operations **operations)
{
    int n;

    while (!check_order_in_stack(a) || (*b))
    {
        if (check_order_in_stack(a))
            make_sort_all(a);
        else if (!check_order_in_stack(a))
        {
            if (cardinality(a) <= 3)
                sort_three_el_up(a, b, operations);
            else if (снизу неотсортированно)
                функции сортировки снизу
            else
                while (cardinality(a) > 3)
            {
                n =

                division(a, b, operations, n);
            }
                рассмотреть что эл могут лежать и снизу неотсортированные
        }

    }

}

void    sort_two(t_ps **a, t_ps **b, t_operations **operations)
{
    int end;
    t_ps *tmp;
    int start;
    t_ps *tmp_next;

    tmp = (*a);
    start = cardinality(a) / 3;
    end = 2 * start;
    while (!(check_max_elem(a, end)))
    {
        tmp_next = tmp->next;
        if (tmp->index <= start)
            sort_min_elem(a, b, operations, 1);
        else if (tmp->index > start && tmp->index <= end)
            sort_mid_elem(a, b, operations, 2);
        else
        {
            tmp->block = 3;
            ra(a, b, operations);
        }
        tmp = tmp_next;
    }
}

void    sort_min_elem(t_ps **a, t_ps **b, t_operations **operations, int n)
{
    t_ps *tmp_a;

    tmp_a = (*a);
    if (tmp_a)
    {
        if (NULL == (*b))
        {
            (*b) = (*a);
            (*b)->block = n;
            (*a) = (*a)->next;
            (*b)->next = NULL;
        }
        else
        {
            tmp_a->block = n;
            pb(a, b, operations);
            rb(b, a, operations);
        }
    }
}

void    sort_mid_elem(t_ps **a, t_ps **b, t_operations **operations, int n)
{
    t_ps *tmp_a;

    tmp_a = (*a);
    if (tmp_a)
    {
        if (NULL == (*b))
        {
            (*b) = (*a);
            (*b)->block = n;
            (*a) = (*a)->next;
            (*b)->next = NULL;
        }
        else
        {
            tmp_a->block = n;
            pb(a, b, operations);
        }
    }
}
/*

void    general_sort_two(t_ps **a, t_ps **b, t_operations **operations, char **av)
{
    int n;

    n = 1;
    while (!check_order_in_stack(a) || (*b))
    {
        while (*b)
        {
            while (cardinality(b) > 2)
                sort_another_parts(a, b, operations, ++n);
            check_sort_stack_b_and_a(a, b, operations);
            if ((*a)->block != 1 && !check_order_in_stack(a))
                transfer_from_a_to_b(a, b, operations);
        }
        general_sort_three(a, b, operations);
    }
    the_end_of_sorting(a, operations, av);
}

void    general_sort_three(t_ps **a, t_ps **b, t_operations **operations)
{
    int count;
    int center;
    int numbers;

    if (!check_order_in_stack(a) && (*a)->block)
    {
        count = 0;
        numbers = cardinality(a);
        center = find_mid(a);
        zeroing_the_blocks(a);
        while (++count <= (numbers / 2 + 1))
            sort_first_part(a, b, operations, center);
        count = 0;
        if (!check_large_elem(a, center))
            while (++count <= (numbers / 2) && !check_large_elem(a, center))
                sort_first_part(a, b, operations, center);
        flipping_to_the_top(a, b, operations);
    }
}

void    sort_first_part(t_ps **a, t_ps **b, t_operations **operations, int mid)
{
    t_ps *tmp_a;

    tmp_a = (*a);
    if (tmp_a && tmp_a->sort != 1)
    {
        if (tmp_a->index <= mid)
        {
            if (NULL == (*b))
            {
                (*b) = (*a);
                (*a) = (*a)->next;
                (*b)->next = NULL;
            }
            else
                pb(a, b, operations);
        }
        else if (0 == (*a)->block)
        {
            (*a)->block = 1;
            ra(a, b, operations);
        }
    }
}

void    sort_another_parts(t_ps **a, t_ps **b, t_operations **operations, int n)
{
    int mid;
    int min;
    t_ps *tmp_b;
    t_ps *tmp_next;

    min = find_min(b);
    mid = find_mid(b);
    tmp_b = (*b);
    while (tmp_b && tmp_b->block != n + 10)
    {
        tmp_next = tmp_b->next;
        if (tmp_b->index == min)
        {
            tmp_b->sort = 1;
            pa(b, a, operations);
            ra(a, b, operations);
            min++;
        }
        else if (tmp_b->index > mid)
        {
            tmp_b->block = n;
            pa(b, a, operations);
        }
        else if (tmp_b->block != n)
        {
            (*b)->block = n + 10;
            rb(b, a, operations);
        }
        tmp_b = tmp_next;
    }
}
*/