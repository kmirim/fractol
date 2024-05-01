/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maldel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:08:17 by lbarcelo          #+#    #+#             */
/*   Updated: 2024/03/19 22:10:05 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/fractol.h"

void	get_julia_values(t_fractal *fractal, int count, char **value)
{
	if (count == 4)
	{
		fractal->cx = atof(value[2]);
		fractal->cy = atof(value[3]);
		if (fractal->cx > 2.0 || fractal->cx < -2.0 || fractal->cy > 2.0
			|| fractal->cy < -2.0)
		{
			ft_putendl_fd("Error. Possible range: -2.0 and 2.0.", 1);
			exit(EXIT_FAILURE);
		}
	}
}

int	draw_fractal(t_fractal *fractal, char *query)
{
	if (ft_strncmp(query, "mandel", 6) == 0)
		draw_mandelbrot(fractal);
	else if (ft_strncmp(query, "julia", 5) == 0)
		draw_julia(fractal);
	else
	{
		ft_putendl_fd("Render a fractal: mandel or julia:", 1);
		close_fractal(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}

int	main(int count, char **value)
{
	t_fractal	*fractal;

	if (count < 2)
	{
		ft_putendl_fd("Prototype: ./fractol <fractal>", 1);
		ft_putendl_fd("Available fractals: mandel and julia.", 1);
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	if (ft_strncmp(value[1], "julia", 5) == 0)
		get_julia_values(fractal, count, value);
	init_fractal(fractal, value);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse, fractal);
	mlx_hook(fractal->window, 17, 0L, close_fractal, fractal);
	draw_fractal(fractal, value[1]);
	mlx_loop(fractal->mlx);
	free(fractal);
	return (0);
}
