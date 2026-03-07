/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanuel- <cmanuel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:33:02 by cmanuel-          #+#    #+#             */
/*   Updated: 2025/08/09 11:33:18 by cmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	paint_fractal(t_complex z, t_complex c, t_fractal *fractal)
{
	int		i;
	int		color;
	double	smooth_n;
	double	norm_sq;

	i = 0;
	while (i++ < fractal->iter)
	{
		z = sum_complex(square_complex(z), c);
		norm_sq = (z.x * z.x) + (z.y * z.y);
		if (norm_sq > fractal->escape_value)
		{
			smooth_n = i + 1 - log(log(sqrt(norm_sq))) / log(2.0);
			color = map_color_hsv(smooth_n);
			ft_pixel_put(fractal->px, fractal->py, &fractal->img, color);
			return ;
		}
	}
	ft_pixel_put(fractal->px, fractal->py, &fractal->img, fractal->max_color);
}

void	handle_mandelbrot(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;

	z.x = 0;
	z.y = 0;
	c.x = (map(x, -2, 0.47, WIDTH) * fractal->zoom) + fractal->shift_x;
	c.y = (map(y, 1.15, -1.15, HEIGHT) * fractal->zoom) + fractal->shift_y;
	fractal->px = x;
	fractal->py = y;
	paint_fractal(z, c, fractal);
}

void	handle_julia(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;

	z.x = (map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	c.x = fractal->julia_x;
	c.y = fractal->julia_y;
	fractal->px = x;
	fractal->py = y;
	paint_fractal(z, c, fractal);
}

void	handle_mods(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	static int	i = 1;

	z.x = (map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	c.x = fractal->mods_x;
	c.y = fractal->mods_y;
	fractal->px = x;
	fractal->py = y;
	while (i-- > 0)
		putstr_fd(JULIA_MODS, 1);
	paint_fractal(z, c, fractal);
}
