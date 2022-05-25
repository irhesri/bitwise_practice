/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:51:31 by irhesri           #+#    #+#             */
/*   Updated: 2022/05/24 17:51:33 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "bitwise.h"

long long	_abs(long long n)
{
	if (is_negative(n))
	{
		// Two's complement
		n = ~n;
		n = add(n, 1);
	}
	return (n);
}

long long	add(long long a, long long b)
{
	long long sum;
	long long carry;
	long long tmp;

	sum = a ^ b;
	carry = a & b;
	while (carry)
	{
		carry <<= 1;
		tmp = sum;
		sum ^= carry;
		carry &= tmp;
	}
	return (sum);
}

long long	substruct(long long a, long long b)
{
	// Two's complement to reverse sign of b
	b = ~b;
	b = add(b, 1);
	return (add(a, b));
}

long long	multiply(long long a, long long b)
{
	long long	result;
	int			i;

	result = 0;
	i = sizeof(long long) * 8;
	while (i-- && b)
	{
		if (b & 1)
			result = add(result, a);
		a <<= 1;
		b >>= 1;
	}
	return (result);
}

long long	power(long long a, long long b)
{
	long long result;

	if (!a)
		return (0);
	if (!b)
		return (1);
	result = 1;
	while (b--)
		result = multiply(result, a);
	return (result);
}

long long	division(long long a, long long b)
{
	long long	result;
	short		sign;
	int			shifts;

	if (is_equal(b, 0))
	{
		write(2, "error: division by zero\n", 24);
		exit (1);
	}
	sign = 1;
	if ((is_negative(a) && !is_negative(b)) || (!is_negative(a) && is_negative(b)))
		sign = -1;
	a = _abs(a);
	b = _abs(b);
	shifts = 1;
	result = 0;
	while (is_bigger_than(a, b))
	{
		b <<= 1;
		shifts++;
	}
	while (shifts--)
	{
		result <<= 1;
		if (is_bigger_than_or_equal(a, b))
		{
			a = substruct(a, b);
			result |= 1;
		}
		b >>= 1;
	}
	if (is_negative(sign))
	{
		result = ~result;
		result = add(result, 1);
	}
	return (result);
}

long long	modulo(long long a, long long b)
{
	int 	shifts;
	int		i;
	short	sign;

	if (is_equal(b, 0))
	{
		write(2, "error: division by zero\n", 24);
		exit (1);
	}
	sign = 1;
	if ((is_negative(a) && !is_negative(b)) || (!is_negative(a) && is_negative(b)))
		sign = -1;
	a = _abs(a);
	b = _abs(b);
	shifts = 1;
	while (is_bigger_than(a, b))
	{
		b <<= 1;
		shifts++;		
	}
	while (shifts--)
	{
		if (is_smaller_than_or_equal(b, a))
			a = substruct(a, b);
		b >>= 1;
	}
	return (a);
}

short	is_equal(long long a, long long b)
{
	if (a ^ b)
		return (0);
	return (1);
}

short	is_bigger_than(long long a, long long b)
{
	long long	v;
	int			i;

	if (!(a ^ b))
		return (0);
	v = power(2, sizeof(long long) * 8 - 1);
	if ((is_negative(a) && !is_negative(b)) || (!is_negative(a) && is_negative(b)))
	{
		a = _abs(a);
		b = _abs(b);
		swap(&a, &b);
	}
	i = sizeof(long long) * 8;
	while (i-- && is_equal((a & v), (b & v)))
	{
		a <<= 1;
		b <<= 1;
	}
	return (!is_equal((a & v), 0));
}

short	is_bigger_than_or_equal(long long a, long long b)
{
	return (is_bigger_than(a, b) || is_equal(a, b));
}

short	is_smaller_than(long long a, long long b)
{
	return (!is_bigger_than(a, b));
}

short	is_smaller_than_or_equal(long long a, long long b)
{
	return (!is_bigger_than(a, b) || is_equal(a, b));
}

short	is_negative(long long a)
{
	long long	v;

	v = power(2, sizeof(long long) * 8 - 1);
	if (a & v)
		return (1);
	return (0);
}

short	is_positive(long long a)
{
	return (!is_negative(a));
}
