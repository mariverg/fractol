/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:53:24 by mariverg          #+#    #+#             */
/*   Updated: 2024/08/21 18:25:58 by mariverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection,
		fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection,
		fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_plus)
		fractal->iterations_defintion += 10;
	else if (keysym == XK_minus)
		fractal->iterations_defintion -= 10;
	else if (keysym == XK_space)
		fractal->color_shift += 1;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = map_x(x, fractal);
	mouse_y = map_y(y, fractal);
	if (button == Button5)
	{
		fractal->zoom *= 0.95;
		fractal->shift_x = mouse_x - (mouse_x - fractal->shift_x) * 0.95;
		fractal->shift_y = mouse_y - (mouse_y - fractal->shift_y) * 0.95;
	}
	else if (button == Button4)
	{
		fractal->zoom *= 1.05;
		fractal->shift_x = mouse_x - (mouse_x - fractal->shift_x) * 1.05;
		fractal->shift_y = mouse_y - (mouse_y - fractal->shift_y) * 1.05;
	}
	fractal_render(fractal);
	return (0);
}
 int	julia_track(int x, int y, t_fractal *fractal)
{
	double	scale_x;
	double	scale_y;

	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		scale_x = calculate_scale(-2, 2, 0, WIDTH);
		scale_y = calculate_scale(2, -2, 0, HEIGHT);
		fractal->julia_x = (map_scaled(x, -2, scale_x, 0) 
				* fractal->zoom) + fractal->shift_x;
		fractal->julia_y = (map_scaled(y, 2, scale_y, 0) 
				* fractal->zoom) + fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
} 
