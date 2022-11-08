/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:52:51 by gtoubol           #+#    #+#             */
/*   Updated: 2022/10/02 20:04:12 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;
	int	diff;

	tmp = 0xff00ff00 | 0xffff << 4 | 15 | 0xf << 20 ;
	diff = *a ^ *b;
	tmp ^= diff;
	*a = ~tmp ^ *a;
	*b = ~tmp ^ *b;
}

/*
#include <stdio.h>

int main(void)
{
	int	a;
	int	b;

	a = 12;
	b = 17;
	ft_swap(&a, &b);
	printf("a:%7d\nb:%7d\n", a, b);
}
*/
