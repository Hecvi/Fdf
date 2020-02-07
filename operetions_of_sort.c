/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_of_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:31:25 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    min_max_mid_top_a(t_ps **a, t_ps **b, t_operations **operations)
{
    ra(a, b, operations);
    sa(a, b, operations);
    rra(a, b, operations);
    make_sort_all(a);
}

void    mid_max_min_top_a(t_ps **a, t_ps **b, t_operations **operations)
{
    ra(a, b, operations);
    sa(a, b, operations);
    rra(a, b, operations);
    sa(a, b, operations);
    make_sort_all(a);
}

void    mid_min_max_top_a(t_ps **a, t_ps **b, t_operations **operations)
{
    sa(a, b, operations);
    make_sort_all(a);
}

void    max_mid_min_top_a(t_ps **a, t_ps **b, t_operations **operations)
{
    sa(a, b, operations);
    ra(a, b, operations);
    sa(a, b, operations);
    rra(a, b, operations);
    sa(a, b, operations);
    make_sort_all(a);
}

void    max_min_mid_top_a(t_ps **a, t_ps **b, t_operations **operations)
{
    sa(a, b, operations);
    ra(a, b, operations);
    sa(a, b, operations);
    rra(a, b, operations);
    make_sort_all(a);
}