/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:36:11 by mariverg          #+#    #+#             */
/*   Updated: 2024/08/21 19:18:11 by mariverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map_x(int x, t_fractal *fractal)
{
	double	scale_x;

	scale_x = calculate_scale(-2, +2, 0, WIDTH);
	return ((map_scaled(x, -2, scale_x, 0)
			* fractal->zoom) + fractal->shift_x);
}

double	map_y(int y, t_fractal *fractal)
{
	double	scale_y;

	scale_y = calculate_scale(+2, -2, 0, HEIGHT);
	return ((map_scaled(y, +2, scale_y, 0)
			* fractal->zoom) + fractal->shift_y);
}

int	calculate_color(int i, t_fractal *fractal)
{
	double	scale_color;
	int		color;

	scale_color = calculate_scale(BLACK, LIME_SHOCK, 0, 
			fractal->iterations_defintion);
	color = map_scaled(i + fractal->color_shift,
						BLACK, scale_color, 0);
	color = color + PSYCHEDELIC_PURPLE;
	return (color);
}