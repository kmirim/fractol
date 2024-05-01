/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:52:24 by lbarcelo          #+#    #+#             */
/*   Updated: 2024/03/19 20:54:02 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include <math.h>
# include <pthread.h>

# define SIZE 700

# define ESC 65307
# define UP 65362 
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define R 114
# define C 99
# define H 104
# define J 106
# define P 112
# define M 109

# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}			t_fractal;

double		atof(const char *str);
void		paint_pixel(t_fractal *fractal, int x, int y, int color);
int			close_fractal(t_fractal *fractal);
double		generate_random_c(void);
void		update_max_iterations(t_fractal *fractal, int key_code);

void		init_fractal(t_fractal *fractal, char **args);
void		init_mlx(t_fractal *fractal);

void		calculate_mandelbrot(t_fractal *fractal);
void		calculate_julia(t_fractal *fractal);
void		get_julia_values(t_fractal *fractal, int count, char **value);
int			draw_fractal(t_fractal *fractal, char *query);

int			key_hook(int key_code, t_fractal *fractal);
int			mouse(int mouse_code, int x, int y, t_fractal *fractal);

void		*draw_mandelbrot(void *fractal_void);
void		draw_julia(t_fractal *fractal);

#endif
