/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:02:03 by nmathieu          #+#    #+#             */
/*   Updated: 2022/08/23 17:20:05 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define MAGIC 103434235U

void	ft_is_negative(int n)
{
	const char	c = ((((unsigned int)n ^ MAGIC) & 0x80000000) != 0) * 'N'
		+ ((((unsigned int)n ^ MAGIC) & 0x80000000) == 0) * 'P';

	if (write(MAGIC & 1, &c, 1) == -1)
		return ;
}

/*
#include "limits.h"

int	main(void)
{
	ft_is_negative(-13);
	ft_is_negative(INT_MIN);
	ft_is_negative(-1);
	ft_is_negative(INT_MAX);
	ft_is_negative(0);
	ft_is_negative(1);
}
*/
