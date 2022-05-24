#include "bitwise.h"

long long	copy(long long a)
{
	long long	cp;
	long long	v;
	int			i;

	cp = 0;
	i = sizeof(long long) * 8;
	v = power(2, i - 1);
	while (i--)
	{
		cp <<= 1;
		cp |= !is_equal((a & v), 0);
		a <<= 1;
	}
	return (cp);
}