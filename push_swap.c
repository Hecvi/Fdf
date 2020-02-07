/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:31:25 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rrr(t_ps **a, t_ps **b, t_operations **operations)
{
    if ((*a) && (*a)->next && (*b) && (*b)->next)
    {
        rra(a, b, operations);
        rrb(b, a, operations);
        create_list_oper(operations, a, b, "rrr");
    }
}

void    the_end_of_sorting(t_ps **a, t_operations **operations, char **av)
{
    t_ps *tmp; //

    tmp = (*a); //
    combine(operations, "sa", "sb", "ss");
    combine(operations, "ra", "rb", "rr");
    combine(operations, "rra", "rrb", "rrr");
    print_operations(operations, av);
    while (tmp)   //
    {
        printf("%d\n", tmp->index);
        tmp = tmp->next;
    }  //
    free_list_operations(operations);
    free_list(a, 0);
    exit (0);
}

void    print_operations(t_operations **operations, char **av)
{
    int count; //
    t_operations *tmp;

    count = 0;  //
    tmp = (*operations);
    if ('-' == av[1][0] && 'w' == av[1][1] && !av[1][2])
        write_to_file(operations);
    else
        while (tmp)
    {
        count++; //
        write(1, tmp->str, ft_strlen(tmp->str));
        write(1, "\n", 1);
        tmp = tmp->next;
    }
    printf("%d\n", count); //
}


int	write_to_file(t_operations **operations)
{
    FILE		*s;
    t_operations *tmp;

    tmp = (*operations);
    s = fopen("Operations.txt", "w");
    if (NULL == s)
        return (write(1, "Cannot create file\n", 19));
    while (tmp)
    {
        if (NULL == tmp->str) //
            tmp = tmp->next; //
        fprintf(s, "%s", tmp->str);
        tmp = tmp->next;
    }
    return (0);
}

int     main(int ac, char **av)
{
    int     i;
    int     j;
    t_ps    *a;
    t_ps    *b;
    int     count;

    i = 0;
    j = 0;
    a = NULL;
    b = NULL;
    count = 1;
    first_check(av, ac);
    second_check(av, &a, i, j);
    sort_by_index(&a, count);
    general_sort_one(&a, &b, av);
    return (0);
}

