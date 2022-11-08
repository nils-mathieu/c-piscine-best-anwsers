/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 06:31:51 by gtoubol           #+#    #+#             */
/*   Updated: 2022/10/06 07:31:27 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

typedef struct s_ultimate
{
	char			*a;
	uint32_t		*b;
	char			**c;
	int64_t			d;
	size_t			*e;
	int				******f;
	unsigned long	g;

}	t_ultimate;

void	ft_ultimate_ft(int *********nbr)
{
	t_ultimate	u;
	uint64_t	*****v;

	v = (uint64_t *****)&u;
	u.a = *(char **)nbr;
	u.b = *(uint32_t **)(u.a);
	u.c = *(char ***)(u.b);
	u.d = *(int64_t *)(u.c);
	u.e = *(size_t **)(u.d);
	u.f = *(int *******)(u.e);
	u.g = *(unsigned long *)(u.f);
	****v[6] = 42;
}

/*
#include <stdio.h>

int	main(void)
{
	int		q42;
	char	q43[432 * sizeof(void *)];
	size_t	i;

	q42 = 12;
	i ^= i;
	while (i < 400)
	{
		((char **)q43 + i)[(0xc7 & 033) >> 2] = q43 + ((i + 1) << 3);
		++i;
	}
	*(size_t *)(q43 + 42 * sizeof(void *)) = (size_t)&q42;
	ft_ultimate_ft((int *********)(q43 + 33 * sizeof(void *)));

	printf("result : % 12.11d\n", q42);
	return (0);
}
*/
