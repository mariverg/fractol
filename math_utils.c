/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:38:09 by mariverg          #+#    #+#             */
/*   Updated: 2024/08/21 19:18:18 by mariverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	calculate_scale(double new_min,
		double new_max,
		double old_min,
		double old_max)
{
	double	scale;

	scale = (new_max - new_min) / (old_max - old_min);
	return (scale);
}

double	map_scaled(double unscaled_num,
		double new_min,
		double scale,
		double old_min)
{
	double	result;

	result = scale * (unscaled_num - old_min) + new_min;
	return (result);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

void	burningship(t_complex *z)
{
	z->x = fabs(z->x);
	z->y = fabs(z->y);
}
