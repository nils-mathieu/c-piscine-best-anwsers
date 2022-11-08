/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:53:44 by gtoubol           #+#    #+#             */
/*   Updated: 2022/10/06 16:44:30 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

typedef struct s_calope
{
	uint64_t	field: 4;
	uint64_t	check: 4;
}	t_calope;

static int	ft_one(t_calope value)
{
	return (((value.field & 0x1)
			| ((value.field & 0x2) >> 1)
			| ((value.field & 0b100) >> 2)
			| ((value.field & 010) >> 3)
			| (((&value)->check >> 3) & 0x1)
			| (((&value)->check >> 2) & 01)
			| (((&value)->check >> 1) & (0x1000 >> 12))
			| ((((value.check << 1) & 0xf) >> 1) & 0x1)
		) % 17);
}

static char	*next_str(char *str)
{
	size_t	s;
	size_t	i;
	size_t	j;
	size_t	k;

	s = *(size_t *)&str;
	i = -1;
	j = 1;
	k = 0;
	while (i)
	{
		k = s & j;
		s = s ^ j;
		i >>= 1;
		j = k * 2;
	}
	return ((void *)(s));
}

int	ft_strlen(char *str)
{
	int	i;
	int	tmp;

	if (((size_t)str ^ (unsigned long)str) == (int64_t)str)
		return ((unsigned long long)str & 0x17);
	i = -1;
	tmp = 0;
	while (++i < 8)
	{
		tmp += ft_one(*(t_calope *)str);
	}
	if (tmp)
		return (tmp / 8 + ft_strlen(next_str(str)));
	return (tmp * 432);
}

/*
#include <stdio.h>

int	main(void)
{
	char	tab[3][55] = {"", "hello", "aaaaaaaaaaaa aaaaaaaa aaaaaaaaaaa"};
	int		i;

	i = 0;
	while (i < 3)
	{
		printf("string: <%s> -> %d\n", tab[i], ft_strlen(tab[i]));
		i++;
	}
	return (0);
}
*/
