/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:31:25 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     check_char(char c, int flag)
{
    if (1 == flag && ((c >= '0' && c <= '9') || '-' == c || '+' == c ||
    '\n' == c || '\t' == c || '\v' == c || '\f' == c || '\r' == c || ' ' == c))
        return (1);
    else if (2 == flag && c != '\0' && ('\n' == c || '\t' == c || '\v' == c ||
    '\f' == c || '\r' == c || ' ' == c))
        return (2);
    else if (3 == flag && c != '\0' && c != '\n' && c != '\t' && c != '\v' &&
    c != '\f' && c != '\r' && c != ' ')
        return (3);
    return (0);
}

void     first_check(char **av, int ac)
{
    int i;
    int j;

    i = 0;
    if (1 == ac)
    {
        write(1, "Add the arguments\n", 18);
        exit(1);
    }
    if ('-' == av[1][0] && 'w' == av[1][1] && !av[1][2])
        i++;
    while (av[++i])
    {
        j = 0;
        while (av[i][j])
        {
            if (check_char(av[i][j], 1))
                j++;
            else
            {
                write(1, "Incorrect data\n", 15);
                exit(1);
            }
        }
    }
}

int     check_string_of_array(char *s, int *indicator)
{
    int     i;
    size_t  j;
    int     sign;
    int     number;

    i = -1;
    sign = 1;
    if ('-' == s[0] || '+' == s[0])
    {
        sign = -1;
        i++;
    }
    j = ft_strlen(s);
    if ((j > 10 && 1 == sign) || (j > 11 && -1 == sign))
    {
        *indicator = -1;
        return (0);
    }
    while (s[++i])
        if (!(s[i] >= '0' && s[i] <= '9'))
            return (0);
    number = func_atoi(s, sign, indicator);
    return (number);
}

int    check_number(t_ps **a, int number)
{
    t_ps *tmp;

    tmp = (*a);
    while (tmp)
    {
        if ((tmp)->num == number)
            return (0);
        (tmp) = (tmp)->next;
    }
    return (1);
}

void    second_check(char **av, t_ps **a, int i, int j)
{
    char **s;
    int number;
    int *indicator;
    int num_of_words;

    indicator = &i;
    if ('-' == av[1][0] && 'w' == av[1][1] && !av[1][2])
        i++;
    while (av[++i])
    {
        j = 0;
        if (!(s = ft_split(av[i], a)))
            continue ;
        num_of_words = c_w(av[i]);
        while (s[j])
        {
            number = check_string_of_array(s[j], indicator);
            if (-1 == *indicator || !(check_number(a, number)))
                free_all(s, num_of_words, a, 0);
            create_list_a(a, number, s, num_of_words);
            j++;
        }
        free_split(s, c_w(av[i]), 0);
    }
    check_list_a(a);
}