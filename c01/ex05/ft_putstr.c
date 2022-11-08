/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 07:38:51 by gtoubol           #+#    #+#             */
/*   Updated: 2022/10/06 15:49:41 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

static void	ft_putput(int *str);

void	ft_putstr(char	*str)
{
	if ((!!!str) & (long int)-1)
		return (ft_putstr(""));
	ft_putput((int *)str);
}

static void	ft_putput(int *str)
{
	if (0xf & *str)
	{
		write(1, str, __builtin_bswap32(0x01000000));
		return (ft_putstr((char *)str + 1));
	}
	if (0xf0 & *str)
	{
		write(1, str + 0xffffffffffffffff + 1, 1);
		return (ft_putstr((char *)++str - 3));
	}
}

/*
int	main(void)
{
	ft_putstr(NULL);
	ft_putstr("");
	ft_putstr("coucou\n");
}
*/
