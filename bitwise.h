/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:51:07 by irhesri           #+#    #+#             */
/*   Updated: 2022/05/24 17:51:10 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITWISE_H
# define BITWISE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


void			print_binary(long long u);
void			print_hexa(long long u);
void			print_octa(long long u);

void			print_bits(unsigned char u);
void			swap(long long *a, long long *b);
long long		copy(long long a);
unsigned char	reverse_bits(unsigned char c);

//	MATHS
long long		_abs(long long a);
long long		add(long long a, long long b);
long long		substruct(long long a, long long b);
long long		multiply(long long a, long long b);
long long		power(long long a, long long b);
long long		division(long long a, long long b);
short			is_equal(long long a, long long b);
short			is_bigger_than(long long a, long long b);
short			is_bigger_than_or_equal(long long a, long long b);
short			is_smaller_than(long long a, long long b);
short			is_smaller_than_or_equal(long long a, long long b);
short			is_negative(long long a);
short			is_positive(long long a);

#endif
