/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanuel- <cmanuel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:32:16 by cmanuel-          #+#    #+#             */
/*   Updated: 2025/08/09 18:20:35 by cmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_color_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_z)
		fractal->max_color = UBUNTU;
	else if (keysym == XK_x)
		fractal->max_color = BLACK;
	else if (keysym == XK_c)
		fractal->max_color = WHITE;
	else if (keysym == XK_v)
		fractal->max_color = PINK;
}

void	key_iter_handler(int keysym, t_fractal *fractal)
{
	if (keysym == 61 || keysym == XK_e)
		fractal->iter += 10;
	else if (keysym == XK_minus || keysym == XK_q)
		fractal->iter -= 10;
	else if (keysym == XK_1)
		fractal->iter = 42;
	else if (keysym == XK_2)
		fractal->iter = 242;
	else if (keysym == XK_3)
		fractal->iter = 442;
	else if (keysym == XK_4)
		fractal->iter = 642;
	else if (keysym == XK_5)
		fractal->iter = 842;
}

void	key_zoom_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Left || keysym == XK_a)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Right || keysym == XK_d)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Up || keysym == XK_w)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Down || keysym == XK_s)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_i)
		fractal->zoom *= 0.90;
	else if (keysym == XK_o)
		fractal->zoom *= 1.1;
	else if (keysym == XK_0)
	{
		fractal->shift_x = 0;
		fractal->shift_y = 0;
		fractal->zoom = 1.0;
	}
}

void	key_mods_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_g)
	{
		fractal->mods_x = 0.285;
		fractal->mods_y = 0;
	}
	else if (keysym == XK_h)
	{
		fractal->mods_x = -0.8;
		fractal->mods_y = 0.156;
	}
	else if (keysym == XK_j)
	{
		fractal->mods_x = 0;
		fractal->mods_y = -0.8;
	}
	else if (keysym == XK_k)
	{
		fractal->mods_x = 0.285;
		fractal->mods_y = 0.01;
	}
	else if (keysym == XK_l)
	{
		fractal->mods_x = 0.35;
		fractal->mods_y = 0.35;
	}
}
