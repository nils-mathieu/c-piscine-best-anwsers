/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 05:25:48 by nmathieu          #+#    #+#             */
/*   Updated: 2022/08/22 05:40:54 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define MAGIC_A 13584647
#define MAGIC_B 15317989
#define MAGIC_C 113

void	ft_putchar(char c)
{
	unsigned int	dst;
	unsigned int	src;
	unsigned int	tmp;

	dst = (unsigned int)c * MAGIC_A;
	src = (unsigned int)c * MAGIC_B;
	tmp = dst ^ src;
	if ((dst + src - tmp + src + dst) % MAGIC_A)
		tmp = (dst - src + tmp + src - dst) ^ tmp;
	else
		tmp = tmp ^ (dst - src + tmp + src - dst);
	tmp &= 0xff00ffff;
	tmp |= (unsigned int)c << 16;
	c += MAGIC_A;
	c -= MAGIC_B ^ (unsigned int)c;
	tmp ^= src;
	if (!(dst & 0x1))
		dst--;
	while ((int)dst % (MAGIC_C + 1) != 0 && (dst--, MAGIC_A))
		tmp ^= src;
	if (src & 1)
		src++;
	if (write(src & 0x0001, (char *)&tmp + 2, 1) == 0)
		c = c + 1;
}

/*
int	main(void)
{
	ft_putchar('H');
	ft_putchar('e');
	ft_putchar('l');
	ft_putchar('l');
	ft_putchar('o');
	ft_putchar(',');
	ft_putchar(' ');
	ft_putchar('w');
	ft_putchar('o');
	ft_putchar('r');
	ft_putchar('l');
	ft_putchar('d');
	ft_putchar('!');
	ft_putchar('\n');
	return (0);
}
*/
