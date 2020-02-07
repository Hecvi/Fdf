/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:31:23 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:31:25 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     c_w(char *s)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (s[i])
    {
        if (check_char(s[i], 3) && (' ' == s[i + 1] ||
            '\t' == s[i + 1] || '\n' == s[i + 1] || '\v' == s[i + 1] ||
            '\f' == s[i + 1] || '\r' == s[i + 1] || '\0' == s[i + 1]))
            count++;
        i++;
    }
    return (count);
}

int     c_l(char *s, int i)
{
    int count;

    count = 0;
    while (check_char(s[i], 3))
    {
        count++;
        i++;
    }
    return (count);
}

char    **mas_of_char(char *str, char **s, t_ps **a, int i)
{
    int k;
    int j;

    j = 0;
    while (str[i])
    {
        if (check_char(str[i], 3))
        {
            k = 0;
            if (!(s[j] = (char *)malloc(sizeof(char) * (c_l(str, i) + 1))))
                free_all(s, j, a, 1);
            while (check_char(str[i], 3))
                s[j][k++] = str[i++];
            s[j][k] = '\0';
            j++;
            if (str[i] == '\0')
            {
                s[j] = NULL;
                return (s);
            }
        }
        i++;
    }
    s[j] = NULL;
    return (s);
}

char    **ft_split(char *str, t_ps **a)
{
    int i;
    char **s;

    i = 0;
    if (!str)
        return (NULL);
    if (!(s = (char **)malloc(sizeof(char *) * (c_w(str) + 1))))
    {
        free_list(a, 1);
        exit(1);
    }
    while (check_char(str[i], 2))
        i++;
    return (mas_of_char(str, s, a, i));
}