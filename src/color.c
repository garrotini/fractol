/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanuel- <cmanuel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:49:59 by cmanuel-          #+#    #+#             */
/*   Updated: 2025/08/09 18:20:24 by cmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_rgb1(t_color *color)
{
	if (color->h >= 0 && color->h < 60)
	{
		color->r = color->c;
		color->g = color->x;
		color->b = 0;
	}
	else if (color->h >= 60 && color->h < 120)
	{
		color->r = color->x;
		color->g = color->c;
		color->b = 0;
	}
	else
	{
		color->r = 0;
		color->g = color->c;
		color->b = color->x;
	}
}

static void	set_rgb2(t_color *color)
{
	if (color->h >= 180 && color->h < 240)
	{
		color->r = 0;
		color->g = color->x;
		color->b = color->c;
	}
	else if (color->h >= 240 && color->h < 300)
	{
		color->r = color->x;
		color->g = 0;
		color->b = color->c;
	}
	else
	{
		color->r = color->c;
		color->g = 0;
		color->b = color->x;
	}
}

int	map_color_hsv(double smooth_n)
{
	int		hue_value;
	t_color	color;

	hue_value = 360;
	color.h = fmod(smooth_n * 10, hue_value);
	color.s = 0.8;
	color.v = 1;
	color.c = color.v * color.s;
	color.x = color.c * (1 - fabs(fmod(color.h / 60.0, 2) - 1));
	color.m = color.v - color.c;
	if (color.h < 180)
		set_rgb1(&color);
	else
		set_rgb2(&color);
	return (((int)((color.r + color.m) * 255) << 16) | ((int)((color.g
					+ color.m) * 255) << 8) | (int)((color.b + color.m) * 255));
}

// 360 is the hue_value
// c for CHROMA: intensity of the color
// x : intermediate value used in the conversion logic to find color values
// m : the lightness offset that is added to the RGB components at the end
// Map the continuous iteration count to a hue_value (0-360)
// You can adjust the multiplier to change the speed of the color cycle
// s for Saturation
// v for Value, range from 0.0 (BLACK) to 1.0
