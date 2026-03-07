/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanuel- <cmanuel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:33:53 by cmanuel-          #+#    #+#             */
/*   Updated: 2025/08/09 11:33:59 by cmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parse_args(int ac, char **av, t_fractal *fractal)
{
	if (ac == 2 && (!ft_strncmp(av[1], "mandelbrot", 10) || !ft_strncmp(av[1],
				"julia_mods", 10)))
		return (1);
	if (ac == 4 && !(ft_strncmp(av[1], "julia", 5)))
	{
		if (ft_atodbl(av[2]) >= -2.0 && ft_atodbl(av[2]) <= 2.0
			&& ft_atodbl(av[3]) >= -2 && ft_atodbl(av[3]) <= 2)
		{
			fractal->julia_x = ft_atodbl(av[2]);
			fractal->julia_y = ft_atodbl(av[3]);
			return (1);
		}
		putstr_fd(JULIA_ERROR, 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (parse_args(ac, av, &fractal))
	{
		putstr_fd(HOTKEYS, 1);
		fractal.name = av[1];
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
