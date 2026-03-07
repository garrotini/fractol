/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanuel- <cmanuel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:31:10 by cmanuel-          #+#    #+#             */
/*   Updated: 2025/08/13 16:26:20 by cmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_press_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Left || keysym == XK_a || keysym == XK_Right
		|| keysym == XK_d || keysym == XK_Up || keysym == XK_w
		|| keysym == XK_Down || keysym == XK_s || keysym == XK_i
		|| keysym == XK_o || keysym == XK_0)
		key_zoom_handler(keysym, fractal);
	if (keysym == XK_equal || keysym == XK_e || keysym == XK_minus
		|| keysym == XK_q || keysym == XK_1 || keysym == XK_2 || keysym == XK_3
		|| keysym == XK_4 || keysym == XK_5)
		key_iter_handler(keysym, fractal);
	if (keysym == XK_z || keysym == XK_x || keysym == XK_c || keysym == XK_v)
		key_color_handler(keysym, fractal);
	if (keysym == XK_g || keysym == XK_h || keysym == XK_j || keysym == XK_k
		|| keysym == XK_l)
		key_mods_handler(keysym, fractal);
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == Button4)
		fractal->zoom *= 0.95;
	else if (button == Button5)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}
