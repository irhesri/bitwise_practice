#ifndef BITWISE_H
# define BITWISE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "math.h"


void			print_bits(long long u);
// void			print_bits(unsigned char u);
void			swap(int *a, int *b);
unsigned char	reverse_bits(unsigned char c);

//	MATHS
long long		_abs(long long a);
long long		add(long long a, long long b);
long long		substruct(long long a, long long b);

#endif