/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:13:23 by lbarcelo          #+#    #+#             */
/*   Updated: 2024/03/19 22:13:28 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	calculate_mandelbrot(t_fractal *fractal)
{
	int		i;
	double	x_temp;

	fractal->name = "mandel";
	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
	while (++i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_temp;
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy
			>= __DBL_MAX__)
			break ;
	}
	if (i == fractal->max_iterations)
		paint_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		paint_pixel(fractal, fractal->x, fractal->y, (fractal->color * i));
}
