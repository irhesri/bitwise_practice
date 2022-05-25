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

void	print_bits(unsigned char u)
{
	int	i;
	int	b;

	i = 8;
	while (i--)
	{
		b = !is_equal((u & 128), 0) + 48;
		write(1, &b, 1);
		u <<= 1;
	}
}

// check max and min long long
void	print_binary(long long u)
{
	int			i;
	int			b;
	long long	v;
	
	i = sizeof(long long) * 8;
	v = power(2, i - 1);
	while (i--)
	{
		b = !is_equal((u & v), 0) + 48;
		write(1, &b, 1);
		u <<= 1;
	}
	write(1, "\n", 1);
}

void	print_hexa(long long u)
{
	int			i;
	int			j;
	short		result;
	long long	v;
	
	i = sizeof(long long) * 8;
	v = power(2, i - 1);
	if (is_negative(u))
		write(1, "-", 1);		
	u = _abs(u);
	j = 4;
	while (i && is_equal(u & v, 0))
	{
		j--;
		u <<= 1;
		if (is_equal(j, 0))
			j = 4;
		i--;
	}
	if (!u && i++)
		j++;
	while (i)
	{
		result = 0;
		while (j-- && i)
		{
			if (u & v)
				result = add(result, power(2, j));
			u <<= 1;
			i--;
		}
		j = 4;
		if (is_bigger_than(result, 9))
			result = add(result, 55);
		else
			result = add(result, 48);
		write(1, &result, 1);
	}
	write(1, "\n", 1);
}

void	print_octa(long long u)
{
	int			i;
	int			j;
	short		result;
	long long	v;
	
	i = sizeof(long long) * 8;
	v = power(2, i - 1);
	if (is_negative(u))
		write(1, "-", 1);		
	u = _abs(u);
	j = 1;
	while (i && is_equal(u & v, 0))
	{
		u <<= 1;
		if (is_equal(j, 0))
			j = 3;
		j--;
		i--;
	}
	if (!u && ++i)
		j = 1;
	while (i)
	{
		result = 0;
		while (j-- && i)
		{
			i--;
			if (u & v)
				result = add(result, power(2, j));
			u <<= 1;
		}
		j = 3;
		result = add(result, 48);
		write(1, &result, 1);
	}
	write(1, "\n", 1);
}