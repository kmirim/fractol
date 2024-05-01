/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:54:18 by lbarcelo          #+#    #+#             */
/*   Updated: 2023/10/28 02:02:19 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((str1[i] == str2[i]) && (i < n - 1) && (str1[i]))
		i++;
	return (str1[i] - str2[i]);
}
/*
#include <stdio.h>
int main ()
{
	char arrS1[] = "a zaab";
	char arrS2[] = "aabb";
	printf("%i", ft_strncmp(arrS1, arrS2, 3));
}*/
