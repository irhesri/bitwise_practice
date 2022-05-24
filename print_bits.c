/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:31:51 by irhesri           #+#    #+#             */
/*   Updated: 2022/05/22 18:31:54 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "bitwise.h"

// void	print_bits(unsigned char u)
// {
// 	int	i;
// 	int	b;

// 	i = 8;
// 	while (i--)
// 	{
// 		b = ((u & 128) != 0) + 48;
// 		write(1, &b, 1);
// 		u <<= 1;
// 	}
// }

// check max and min long long
void	print_bits(long long u)
{
	int			i;
	int			b;
	long long	v;
	
	i = sizeof(long long) * 8;
	v = pow(2, i - 1);
	while (i--)
	{
		b = ((u & v) != 0) + 48;
		write(1, &b, 1);
		u <<= 1;
	}
}