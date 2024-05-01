/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:57:01 by lbarcelo          #+#    #+#             */
/*   Updated: 2023/10/24 17:03:26 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n-- > 0)
	{
		if (*((unsigned char *) s) == (unsigned char)c)
			return ((void *) s);
		s++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main() {
    const char *str = "123456";
    int character = 'a';
    size_t num = 8;

    void *result = ft_memchr(str, character, num);
	printf("result: %s", (char *)result);
    return 0;
}*/
