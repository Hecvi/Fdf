/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:31:25 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    check_list_a(t_ps **a)
{
    t_ps *tmp;
    int  flag;

    flag = 0;
    tmp = (*a);
    while (tmp && 0 == flag)
    {
        if (tmp->num)
            flag = 1;
        tmp = tmp->next;
    }
    if (1 == flag)
        return ;
    write(1, "Incorrect data\n", 15);
    exit (1);
}

void    sort_by_index(t_ps **a, int count)
{
    t_ps *tmp;
    t_ps *min;
    int  minimum;

    tmp = (*a);
    min = (*a);
    minimum = MAX;
    while (tmp)
    {
        if (tmp->num <= minimum && !(tmp->index))
        {
            minimum = tmp->num;
            min = tmp;
        }
        tmp = tmp->next;
    }
    min->index = count;
    tmp = (*a);
    while (tmp)
    {
        if (!(tmp->index))
            sort_by_index(a, ++count);
        tmp = tmp->next;
    }
}

void    filling_in_lists(t_ps **a, int i, char **s, int words)
{
    t_ps *b;
    t_ps *tmp;

    tmp = (*a);
    while (tmp->next)
        tmp = tmp->next;
    if (!(b = (t_ps *)malloc(sizeof(t_ps))))
        free_all(s, words, a, 1);
    b->num = i;
    b->sort = 0;
    b->index = 0;
    b->block = 0;
    b->next = NULL;
    tmp->next = b;
}

void    create_list_a(t_ps **a, int i, char **s, int words)
{
    if (NULL == (*a))
    {
        if (!((*a) = (t_ps *)malloc(sizeof(t_ps))))
        {
            write(1, "Memory allocation error\n", 24);
            free_split(s, words, 0);
            exit(1);
        }
        (*a)->num = i;
        (*a)->sort = 0;
        (*a)->index = 0;
        (*a)->block = 0;
        (*a)->next = NULL;
        return ;
    }
    filling_in_lists(a, i, s, words);
}

void    create_list_oper(t_operations **operations, t_ps **a, t_ps **b, char *s)
{
    t_operations *step;
    t_operations *tmp;

    if (NULL == (*operations))
    {
        if (!((*operations) = (t_operations *)malloc(sizeof(t_operations))))
        {
            free_list(a, 1);
            exit(1);
        }
        (*operations)->str = s;
        (*operations)->next = NULL;
        return ;
    }
    tmp = (*operations);
    while (tmp->next)
        tmp = tmp->next;
    if (!(step = (t_operations *)malloc(sizeof(t_operations))))
    {
        free_list(a, 0);
        free_list(b, 1);
        free_list_operations(operations);
    }
    step->str = s;
    step->next = NULL;
    tmp->next = step;
}