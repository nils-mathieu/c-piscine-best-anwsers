/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:46:19 by nmathieu          #+#    #+#             */
/*   Updated: 2022/08/23 17:21:13 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define MAGIC_A 13584647
#define MAGIC_B 15317989
#define MAGIC_C 113

static void	ft_putchar(char c)
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

inline static int	next_letter(char c, char d)
{
	if (!c)
		return (d);
	else
		return (next_letter((c & d) << 1, c ^ d));
}

void	ft_print_alphabet_from(char current)
{
	if (current == 123)
		return ;
	ft_print_alphabet_from(next_letter(current, (unsigned char)257));
	if ((unsigned int)current & 1)
		ft_putchar(current);
	else if (write(1, &current, 1) == -1)
		return ;
}

void	ft_print_alphabet(void)
{
	ft_print_alphabet_from(97);
}

/*
int	main(void)
{
	ft_print_alphabet();
	return (0);
}
*/
