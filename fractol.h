/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:08:44 by mariverg          #+#    #+#             */
/*   Updated: 2024/08/21 19:23:34 by mariverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H


# include <stdio.h> 
# include <stdlib.h> 
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

#define ERROR_MESSAGE " madelbrot\n julia ()\n burningship\n"
#define WIDTH	800
#define	HEIGHT	800
#define	BLACK	0x000000
#define	LIME_SHOCK	0xCCFF00
#define PSYCHEDELIC_PURPLE 0x660066



typedef struct s_complex
{
	//		real
	double	x;
	//		i
	double	y;
}				t_complex;

typedef struct s_img
{
	void	*img_ptr; //pointer to image struct
	char	*pixels_ptr; //points to the actual pixels
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	//Hooks
	double	escape_value;
	int		iterations_defintion;
	double	shift_x;
	double	shift_y;
	int		color_shift;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_fractal;

int		ft_strncmp(char *s1, char *s2, int n);
void	ft_putstr_fd(char *s, int fd);
double	atodbl(char *s);
void	fractal_init(t_fractal *fractal);
void	fractal_render(t_fractal *fractal);
double	calculate_scale(double new_min,
			double new_max,
			double old_min,
			double old_max);
double	map_scaled(double unscaled_num,
			double new_min,
			double scale,
			double old_min);
int		key_handler(int keysym, t_fractal *fractal);
int		close_handler(t_fractal *fractal);
int		mouse_handler(int button, int x, int y, t_fractal *fractal);
int		julia_track(int x, int y, t_fractal *fractal);
int		loop_handler(t_fractal *fractal);
int		calculate_color(int i, t_fractal *fractal);
double	map_x(int x, t_fractal *fractal);
double	map_y(int y, t_fractal *fractal);
void	burningship(t_complex *z);

t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

#endif