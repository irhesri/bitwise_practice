# include "bitwise.h"

long long		_abs(long long n)
{
	long long	v;

	v = pow(2, sizeof(long long) * 8 - 1);
	if (n & v)
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
