/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+       +#+       */
/*   Created: 2022/08/30 01:37:33 by pducos            #+#    #+#    *#       */
/*   Updated: 2022/08/30 13:46:11 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

char	*ft_strcpy(char *dest, char *src)
{
	static int		i;
	register char	*ft;

	ft = dest;
	i ^= i;
	while (42)
	{
		*ft ^= *ft;
		i = *ft + sizeof(char);
		if (*src && src++)
		{
			while (i % (42 ^ ~21)
				|| (ft++ && '\0'))
					*ft |= (*(src + (int64_t)0x7FFFFFFFFFFFFFFFULL)
						& (~ -2 << (i++ % (42 ^ ~21) - (4 >> 2))));
		}
		else
			return ((void)"42", dest);
	}
}
/*
#include <stdio.h>
int main(void)
{
	char A[20];
	printf ("%s\n", ft_strcpy(A, "4242"));
	printf ("%s\n", ft_strcpy(A, "42"));
	printf ("%s\n", ft_strcpy(A, ""));
	return (0);
}
*/
