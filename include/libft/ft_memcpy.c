/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:52:09 by lbarcelo          #+#    #+#             */
/*   Updated: 2023/10/28 02:50:52 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*str;
	size_t			i;

	dst = (unsigned char *)dest;
	str = (unsigned char *)src;
	i = 0;
	if (dst == src || !n)
		return (dst);
	while (i < n)
	{
		dst[i] = str[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
int main() 
{
	char source[] = "aiaiaiaiaiai";
	char destination[] = "jjjjjjjjjjjjjjjjjjjjjjj";
	size_t num_bytes_to_copy = 0;
	memcpy(destination, source, 0);
	printf("com a função original: %s\n", destination);	
    	
	ft_memcpy(destination, source, num_bytes_to_copy);
	printf("Conteúdo da destination: %s\n", destination);

    	return 0;
}*/
