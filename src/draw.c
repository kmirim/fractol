/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:01:18 by lbarcelo          #+#    #+#             */
/*   Updated: 2024/03/19 21:01:34 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	*draw_mandelbrot(void *fractal_void)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)fractal_void;
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			calculate_mandelbrot(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	return (NULL);
}

void	draw_julia(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			calculate_julia(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
}
