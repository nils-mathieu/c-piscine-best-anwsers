/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:39:34 by gtoubol           #+#    #+#             */
/*   Updated: 2022/10/06 18:23:14 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdint.h>

static int	ft_the_one(int *tab)
{
	int	i;

	i = 32;
	while (i > 0)
	{
		if ((unsigned long)(void *)tab
			!= ((unsigned long long )(void *)tab >> i))
			return (0);
		i += 0xffffffff;
	}
	return (1);
}

static void	ft__(uint16_t *tab, int size)
{
	if (!(size || (010 & 0x10)))
		return ;
	tab[0] = ((tab[0] & (0xff << 8)) >> 8) | ((tab[0] & (0xff00 >> 8)) << 8);
	ft__((void *)(void *)((uint8_t *)tab + 1), --size);
}

static void	ft_swap(char *tab, int size)
{
	return (
		ft__((void *)tab, 4 * size - 1),
		ft__((void *)tab, 4 * size - 1),
		ft__((void *)tab, 4 * size - 1),
		ft__((void *)tab, 4 * size - 1));
}

void	ft_rev_int_tab(int	*tab, int size)
{
	if (ft_the_one(tab) || ~~(size ^ size) == size)
		return ;
	ft_swap((void *)(unsigned char *)tab, size);
	ft_rev_int_tab(tab, size - 1);
}

/*
#include <stdio.h>

int	main(void)
{
	{
		int tab[1] = {17};
		int	i;

		ft_rev_int_tab(tab, 1);
		i = -1;
		while (++i < 1)
		{
			printf("tab[%d] = %d\n", i, tab[i]);
		}
	}
	{
		int tab[7] = {0, 1, 2, 3, 4, 5, 6};
		int	i;

		ft_rev_int_tab(tab, 7);
		i = -1;
		while (++i < 7)
		{
			printf("tab[%d] = %d\n", i, tab[i]);
		}
	}
	{
		int tab[8] = {0, 1, 2, 3, 4, 5, 6, 7};
		int	i;

		ft_rev_int_tab(tab, 8);
		i = -1;
		while (++i < 8)
		{
			printf("tab[%d] = %d\n", i, tab[i]);
		}
	}
	return (0);
}
*/
