/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:08:29 by mariverg          #+#    #+#             */
/*   Updated: 2024/08/21 19:11:45 by mariverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;


	if (2 == ac && (!ft_strncmp(av[1], "mandelbrot", 10) 
			|| !ft_strncmp(av[1], "burningship", 11)))
	{
		fractal.name = av[1];
		printf("Fractal name: %s\n", fractal.name);
	}
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 5))
	{
		fractal.name = av[1];
		fractal.julia_x = atodbl(av[2]);
		fractal.julia_y = atodbl(av[3]);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop_hook(fractal.mlx_connection, loop_handler, &fractal);
	mlx_loop(fractal.mlx_connection);
}
