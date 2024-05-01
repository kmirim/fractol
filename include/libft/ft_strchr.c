/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:07:14 by lbarcelo          #+#    #+#             */
/*   Updated: 2023/11/08 21:21:25 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	character;

	character = (unsigned char)c;
	while (*s && *s != character)
		s++;
	if (*s == character)
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>
int main ()
{
	const char str[]  = "trimpouille";
	printf("retorno: %s\n", ft_strchr(str, '\0'));
	return (0);
}*/
