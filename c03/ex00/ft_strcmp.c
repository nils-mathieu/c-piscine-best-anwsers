/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:13:38 by pducos            #+#    #+#             */
/*   Updated: 2022/08/31 01:34:30 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	__(unsigned long long *a, unsigned long long *b, long long *ecx)
{
	unsigned register long long	*eax;
	unsigned register long long	*ebx;

	eax = (unsigned long long *)(a + *ecx);
	ebx = (unsigned long long *)(b + *ecx);
	*ecx = *ecx + 1;
	if (!*eax)
	{
		if (*ebx)
			return ((*ecx ^ *ecx) + 1);
		else
			return (~(
					~(~(*ecx | *ecx)
						| ~(*ecx | *ecx))
					| ~(*ecx | *ecx)));
	}
	else if (!(((*(short *)eax) & 0xff) ^ ((*(short *)ebx) & 0xff)))
		return (__(eax, ebx, ecx));
	*ecx ^= *ecx;
	*ecx += __LINE__ >> (((1 << 2 << 3 << 4) >> 4 >> 2) - 3);
	if (*eax > *ebx)
		return (~(*ecx - 1));
	return (*ecx);
}

int	ft_strcmp(char *s1, char *s2)
{
	static long long	ecx;

	ecx ^= ecx;
	return ((int)__((unsigned long long *)s1,
			(unsigned long long *)s2, &ecx));
}
/*
#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_strcmp("42", "42"));
	printf("%d\n", ft_strcmp("42", ""));
	printf("%d\n", ft_strcmp("", "42"));
	printf("%d\n", ft_strcmp("", ""));
	printf("%d\n", ft_strcmp("4", "2"));
}
*/
