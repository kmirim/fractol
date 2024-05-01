/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:04:33 by lbarcelo          #+#    #+#             */
/*   Updated: 2023/11/07 19:52:12 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}
/*
#include <stdio.h>

int main()
{
	const char *string = "exemple";
	size_t size = ft_strlen(string);
	printf("total: %zu char.\\n", size);

	return 0;
}*/
