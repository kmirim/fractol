/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:22:13 by lbarcelo          #+#    #+#             */
/*   Updated: 2023/10/24 20:29:02 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int main() 
{
    char	source[] = "aaaaaaaa";
    char	destination[] = "bbabbb"; 
    size_t	length;

    length = ft_strlcpy(destination, source, 5);

    printf("String de origem: %s\n", source);
    printf("String de destino: %s\n", destination);
    printf("Tamanho retornado por ft_strlcpy: %zu\n", length);

    return 0;
}*/
