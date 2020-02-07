/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:40:20 by klaurine          #+#    #+#             */
/*   Updated: 2020/01/17 18:40:22 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define MAX 2147483647
# define MIN 2147483648
# include "libft/libft.h"

typedef struct      s_ps
{
    int             num;
    int             block;
    int             index;
    int             sort;
    struct s_ps   *next;
}                   t_ps;

typedef struct      s_operations
{
    char                    *str;
    struct s_operations     *next;
}                   t_operations;

int     c_w(char *s);
int     c_l(char *s, int i);
int     find_mid(t_ps **stack);
void    check_list_a(t_ps **a);
int     find_min(t_ps **stack);
int     find_max(t_ps **stack);
int	write_to_file(t_operations **operations);
int     stupid_function(t_ps **a);
int     cardinality(t_ps **stack);
int     check_char(char c, int flag);
void    zeroing_the_blocks(t_ps **a);
int     check_order_in_stack(t_ps **a);
void    first_check(char **av, int ac);
char    **ft_split(char *str, t_ps **a);
void    free_list(t_ps **stack, int flag);
int     check_number(t_ps **a, int number);
void    sort_by_index(t_ps **a, int count);
void    general_sort_one(t_ps **a, t_ps **b, char **av);
int    check_large_elem(t_ps **stack, int start, int end);
void    free_split(char **s, int words, int flag);
void    print_operations(t_operations **operations, char **av);
int     func_atoi(char *str, int sign, int *indicator);
int     check_string_of_array(char *s, int *indicator);
void    second_check(char **av, t_ps **a, int i, int j);
void    free_list_operations(t_operations **operations);
void    pa(t_ps **b, t_ps **a, t_operations **operations);
void    pb(t_ps **a, t_ps **b, t_operations **operations);
void    rr(t_ps **a, t_ps **b, t_operations **operations);
void    ss(t_ps **a, t_ps **b, t_operations **operations);
void    free_all(char **s, int words, t_ps **a, int flag);
void    sa(t_ps **a, t_ps **b, t_operations **operations);
void    sb(t_ps **b, t_ps **a, t_operations **operations);
void    ra(t_ps **a, t_ps **b, t_operations **operations);
void    rb(t_ps **b, t_ps **a, t_operations **operations);
void    rra(t_ps **a, t_ps **b, t_operations **operations);
void    rrb(t_ps **b, t_ps **a, t_operations **operations);
void    rrr(t_ps **a, t_ps **b, t_operations **operations);
char    **mas_of_char(char *str, char **s, t_ps **a, int i);
void    create_list_a(t_ps **a, int i, char **s, int words);
void    filling_in_lists(t_ps **a, int i, char **s, int words);
void    the_end_of_sorting(t_ps **a, t_operations **operations, char **av);
void    start_read_gnl(t_ps **a, t_ps **b, t_operations **operations);
void    sort_of_two_num(t_ps **a, t_ps **b, t_operations **operations);
void    sort_of_five_num(t_ps **a, t_ps **b, t_operations **operations);
void    sort_of_four_num(t_ps **a, t_ps **b, t_operations **operations);
void    general_sort_two(t_ps **a, t_ps **b, t_operations **operations, char **av);
void    general_sort_three(t_ps **a, t_ps **b, t_operations **operations);
void    flipping_to_the_top(t_ps **a, t_ps **b, t_operations **operations);
void    transfer_from_a_to_b(t_ps **a, t_ps **b, t_operations **operations);
int     fuc_norm(t_ps **a, t_ps **b, t_operations **operations, t_ps **tmp);
void    sort_of_three_num_in_a(t_ps **a, t_ps **b, t_operations **operations);
void    sort_of_three_num_in_b(t_ps **a, t_ps **b, t_operations **operations);
void    combine(t_operations **operations, char *str1, char *str2, char *str3);
void    end_read_gnl(t_ps **a, t_ps **b, t_operations **operations, char *str);
void    check_sort_stack_b_and_a(t_ps **a, t_ps **b, t_operations **operations);
void    sort_first_part(t_ps **a, t_ps **b, t_operations **operations, int mid);
void    help_with_operations_in_a(t_ps **a, t_ps **b, t_operations **operations);
void    create_list_oper(t_operations **operations, t_ps **a, t_ps **b, char *s);
void    sort_another_parts(t_ps **a, t_ps **b, t_operations **operations, int n);
void    for_five_num(t_ps **a, t_ps **b, t_operations **operations, char **av);
int    check_min_elem(t_ps **stack, int end);
int    check_mid_elem(t_ps **stack, int start, int end);
int    check_max_elem(t_ps **stack, int end);
void    sort_min_elem(t_ps **a, t_ps **b, t_operations **operations, int n);
void    sort_mid_elem(t_ps **a, t_ps **b, t_operations **operations, int n);
void    sort_two(t_ps **a, t_ps **b, t_operations **operations);
void    sort_three(t_ps **a, t_ps **b, t_operations **operations);
void    make_sort_all(t_ps **stack);
void    min_max_mid_top_a(t_ps **a, t_ps **b, t_operations **operations);
void    mid_max_min_top_a(t_ps **a, t_ps **b, t_operations **operations);
void    mid_min_max_top_a(t_ps **a, t_ps **b, t_operations **operations);
void    max_mid_min_top_a(t_ps **a, t_ps **b, t_operations **operations);
void    max_min_mid_top_a(t_ps **a, t_ps **b, t_operations **operations);



#endif
