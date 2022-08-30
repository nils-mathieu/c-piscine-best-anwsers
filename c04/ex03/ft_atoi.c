/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 22:16:55 by dhubleur          #+#    #+#             */
/*   Updated: 2022/08/30 22:32:20 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	static int	res = ft_atoi - ft_atoi + 0x1;
	int			sign;

	res = !!res;
	sign = (str - str) << 4 << 2;
	while ((*str >= 0x9 && *str <= 0x13) || *str == 0x20)
		str++;
	while (*str == 0x2B || *str == 0x2D)
	{
		if (*str == 0x2D)
			res *= -0x1;
		str += ft_atoi - ft_atoi + 0x1;
	}
	while (*str >= 0x30 && *str <= 0x39)
		sign = (sign << 0x3) + (sign << 0x1) + (*(str++) ^ 0x30);
	return (res * sign);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi("0"));
	printf("%d\n", ft_atoi("1"));
	printf("%d\n", ft_atoi("-1"));
	printf("%d\n", ft_atoi("42"));
	printf("%d\n", ft_atoi("        ++++++++++42"));
	printf("%d\n", ft_atoi("     +-+-+-+-------42"));
	printf("%d\n", ft_atoi(" +++++42aaa42"));
	printf("%d\n", ft_atoi("2147483647"));
	printf("%d\n", ft_atoi("-2147483648"));
}*/
