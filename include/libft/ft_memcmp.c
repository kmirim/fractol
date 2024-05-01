/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:22:25 by lbarcelo          #+#    #+#             */
/*   Updated: 2023/11/07 19:33:05 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*arr1;
	unsigned char	*arr2;

	i = -1;
	arr1 = (unsigned char *) s1;
	arr2 = (unsigned char *) s2;
	while (++i < n)
	{
		if (arr1[i] != arr2[i])
			return (arr1[i] - arr2[i]);
	}
	return (0);
}
/*
int main ()
{
//	char arrS1[] = "";
//	char arrS2[] = "";

	printf("result: %i\n", ft_memcmp("t\200", "t\0", 3));
	
}*/
