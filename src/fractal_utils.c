/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:08:23 by lbarcelo          #+#    #+#             */
/*   Updated: 2024/03/19 21:54:14 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	paint_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buf;

	buf = fractal->pointer_to_image;
	buf[(y * fractal->size_line / 4) + x] = color;
}

int	close_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	free(fractal);
	exit(1);
	return (0);
}

double	convert_integer(const char *str)
{
	double	result;

	result = 0.0;
	while (ft_isdigit((unsigned char)*str))
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	return (result);
}

double	convert_decimal(const char *str)
{
	double	result;
	double	scale;

	result = 0.0;
	scale = 1.0;
	if (*str == '.')
	{
		str++;
		while (ft_isdigit((unsigned char)*str))
		{
			result = result * 10.0 + (*str - '0');
			scale *= 10.0;
			str++;
		}
	}
	return (result / scale);
}

double	atof(const char *str)
{
	double	sign;
	double	integer_part;
	double	decimal_part;

	sign = 1.0;
	while (ft_isspace((unsigned char)*str))
		str++;
	if (*str == '-')
	{
		sign = -1.0;
		str++;
	}
	else if (*str == '+')
		str++;
	integer_part = convert_integer(str);
	decimal_part = convert_decimal(str);
	return (sign * (integer_part + decimal_part));
}
