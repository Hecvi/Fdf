/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 18:38:31 by klaurine          #+#    #+#             */
/*   Updated: 2019/08/31 18:10:20 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	ft_reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	a;

	i = 0;
	while (i <= 7)
	{
		a = a | ((octet >> i) & 1) << (7 - i);
		i++;
	}
	return (a);
}
