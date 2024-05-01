/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:55:04 by lbarcelo          #+#    #+#             */
/*   Updated: 2024/03/19 21:55:42 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_fractal(t_fractal *fractal, char **args)
{
	ft_memset(fractal, 0, sizeof(t_fractal));
	if (args[2])
		fractal->cx = atof(args[2]);
	else
		fractal->cx = -0.745429;
	if (args[3])
		fractal->cy = atof(args[3]);
	else
		fractal->cy = 0.05;
	fractal->color = 0xFCBE11;
	fractal->zoom = 300;
	fractal->offset_x = -1.21;
	fractal->offset_y = -1.21;
	fractal->max_iterations = 42;
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fract'ol");
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	fractal->pointer_to_image = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel,
			&fractal->size_line,
			&fractal->endian);
}
