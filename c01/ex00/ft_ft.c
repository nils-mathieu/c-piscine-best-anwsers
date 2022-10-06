/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:41:12 by gtoubol           #+#    #+#             */
/*   Updated: 2022/10/02 19:49:57 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

typedef struct s_content
{
	uint8_t	first;
	uint8_t	second;
	uint8_t	third;
	uint8_t	fourth;
}	t_content;

void	ft_ft(int *nbr)
{
	t_content	*content;

	content = (t_content *)nbr;
	content->first ^= *((unsigned char *)nbr + 0);
	content->second ^= *((unsigned char *)nbr + 1);
	content->third = content->first & content->second;
	content->fourth = 0x11 & 0xee;
	content->first += (0xf << 1) + (0x3 << 2);
}

/*
#include <stdio.h>

int	main(void)
{
	int	nbr;

	nbr = 12;
	ft_ft(&nbr);
	printf("result: %d\n", nbr);
	return (0);
}
*/
