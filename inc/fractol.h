/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanuel- <cmanuel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:40:45 by cmanuel-          #+#    #+#             */
/*   Updated: 2025/08/09 18:20:11 by cmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 600
# define HEIGHT 600

// COLORS
# define BLACK 0x000000 // RGB(0, 0, 0)
# define WHITE 0xFFFFFF // RGB(255, 255, 255)
# define UBUNTU 0x5E2750
# define PINK 0xFF69B4

// ERROR MESSAGES
# define ERROR_MESSAGE \
	"\n\tUsage:\n\n\
        './fractol mandelbrot'\n\
        './fractol julia X Y'\n\
        './fractol julia_mods'\n\n"
# define JULIA_ERROR "\n\t!! Julia values should be between -2 and 2 !!\n\n"

// HOTKEYS MESSAGES
# define HOTKEYS \
	"\n\tHOTKEYS:\n\n\
        arrows || 'asdw' -> move accordingly\n\
        mouse_scroll up || i -> zoom in\n\
        mouse_scooll down || o -> zoom out\n\
        0 -> reset zoom and overall position\n\
        1 -> set iterations to 42\n\
        2 -> set iterations to 242\n\
        3 -> set iterations to 442\n\
        4 -> set iterations to 642\n\
        5 -> set iterations to 842\n\
        e || + -> 10 more iterations\n\
        q || - -> 10 less iterations\n\
        z -> set max_color to UBUNTU\n\
        x -> set max_color to BLACK\n\
        c -> set max_color to WHITE\n\
        v -> set max_color to PINK\n\n"

// JULIA_MODS
# define JULIA_MODS \
	"\n-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n\
        Hey!\n\n\
        I know the eclipse looks cool,\n\
        But don't you want to have a try on the next julia_mod sets...?:\n\n\
        g -> 'charcoal' (0.285 + 0i)\n\
        h -> 'dragon' (-0.8 + 0.156i) \n\
        j -> 'root' (0 - 0.8i)\n\
        k -> 'flowers' (0.285 + 0.01i)\n\
        l -> 'pokemon' (0.35 + 0.35)\n\n"

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
	double	c;
	double	x;
	double	m;
	double	h;
	double	s;
	double	v;
}			t_color;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iter;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	double	mods_x;
	double	mods_y;
	int		px;
	int		py;
	int		max_color;
}			t_fractal;

// init fn
void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);

// string_utils
int			ft_strncmp(char *s1, char *s2, int n);
void		putstr_fd(char *s, int fd);
double		ft_atodbl(char *s);

// math_utils;
double		map(double unscaled_num, double new_min, double new_max,
				double olx_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

// hook_events
int			key_press_handler(int keysym, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			close_handler(t_fractal *fractal);

// events utils
void		key_zoom_handler(int keysym, t_fractal *fractal);
void		key_iter_handler(int keysym, t_fractal *fractal);
void		key_color_handler(int keysym, t_fractal *fractal);
void		key_mods_handler(int keysym, t_fractal *fractal);
void		key_random_handler(int keysym, t_fractal *fractal);

// handle fractals
void		handle_julia(int x, int y, t_fractal *fractal);
void		handle_mandelbrot(int x, int y, t_fractal *fractal);
void		handle_mods(int x, int y, t_fractal *fractal);

// drawing, painting, plotting, coloring
void		ft_pixel_put(int x, int y, t_img *img, int color);
int			map_color_hsv(double smooth_n);
int			hsv_to_rgb(double h, double s, double v);

#endif
