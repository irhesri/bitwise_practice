/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhesri <irhesri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:51:21 by irhesri           #+#    #+#             */
/*   Updated: 2022/07/26 19:44:05 by irhesri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitwise.h"

long long	copy(long long a)
{
	long long	cp;
	long long	v;
	int			i;

	cp = 0;
	i = SIZE_OF_LONG_LONG;
	v = power(2, i - 1);
	while (i--)
	{
		cp <<= 1;
		cp |= !is_equal((a & v), 0);
		a <<= 1;
	}
	return (cp);
}
