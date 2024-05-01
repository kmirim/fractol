/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:01:51 by lbarcelo          #+#    #+#             */
/*   Updated: 2024/03/19 22:06:22 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	zoom(t_fractal *fractal, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.40;
	if (zoom == 1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (
				x / (fractal->zoom * zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (
				y / (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (
				x / (fractal->zoom / zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (
				y / (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
	else
		return ;
}

int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		close_fractal(fractal);
	else if (key_code == LEFT)
		fractal->offset_x -= 42 / fractal->zoom;
	else if (key_code == RIGHT)
		fractal->offset_x += 42 / fractal->zoom;
	else if (key_code == UP)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (key_code == DOWN)
		fractal->offset_y += 42 / fractal->zoom;
	else if (key_code == C)
		fractal->color += (255 * 255 * 255) / 100;
	else if (key_code == M || key_code == P)
		update_max_iterations(fractal, key_code);
	draw_fractal(fractal, fractal->name);
	return (0);
}

void	update_max_iterations(t_fractal *fractal, int key_code)
{
	if (key_code == M || key_code == SCROLL_UP)
	{
		if (fractal->max_iterations > 42)
			fractal->max_iterations -= 42;
	}
	else if (key_code == P || key_code == SCROLL_DOWN)
	{
		if (fractal->max_iterations < 4200)
			fractal->max_iterations += 42;
	}
}

int	mouse(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == SCROLL_UP)
	{
		zoom(fractal, x, y, 1);
		update_max_iterations(fractal, mouse_code);
	}
	else if (mouse_code == SCROLL_DOWN)
	{
		zoom(fractal, x, y, -1);
		update_max_iterations(fractal, mouse_code);
	}
	draw_fractal(fractal, fractal->name);
	return (0);
}
