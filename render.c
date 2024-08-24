/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:38:35 by mariverg          #+#    #+#             */
/*   Updated: 2024/08/21 19:22:45 by mariverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
	if (!ft_strncmp(fractal->name, "burningship", 11))
	{
		z->x = fabs(z->x);
		z->y = fabs(z->y);
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = map_x(x, fractal);
	z.y = map_y(y, fractal);
	mandel_vs_julia(&z, &c, fractal);
	i = 0;
	while (i < fractal->iterations_defintion)
	{
		if (!ft_strncmp(fractal->name, "burningship", 11))
			burningship(&z);
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = calculate_color(i, fractal);
			my_pixel_put(x, y, &fractal->img, color);
			return;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
}


void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
}

int	loop_handler(t_fractal *fractal)
{
	static int	refresh_rate = 0;

	if (refresh_rate++ % 10 == 0)
	{
		fractal_render(fractal);
		mlx_put_image_to_window(fractal->mlx_connection,
			fractal->mlx_window, fractal->img.img_ptr, 0, 0);
	}
	return (0);
}
