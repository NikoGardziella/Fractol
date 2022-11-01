/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngardzie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 09:17:47 by ngardzie          #+#    #+#             */
/*   Updated: 2022/06/13 09:17:50 by ngardzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_burning_ship(t_fractol *map, int Px, int Py, int depth)
{
	double		temp_x;
	long double	x0;
	long double	y0;
	long double	x;
	long double	y;

	x0 = Px / map->scalefactor + map->left;
	y0 = Py / map->scalefactor + map->top;
	x = 0;
	y = 0;
	while ((x * x + y * y < 4) && (depth < map->iterations))
	{
		temp_x = x * x - y * y + x0;
		y = fabsl(2 * x * y + y0);
		x = fabsl(temp_x);
		depth = depth + 1;
	}
	ft_put_pixel (map, depth, Px, Py);
}

void	draw_barnsley_fern(t_fractol *map, float x, float y)
{
	int		randomnum;
	int		i;
	int		seed;

	i = 0;
	seed = 1;
	while (i < map->iterations * map->iterations * 10)
	{
		seed = linear_congruential_generator(seed);
		randomnum = seed % 100;
		x = check_fern_x(randomnum, x, y);
		y = check_fern_y(randomnum, x, y);
		mlx_pixel_put (map->mlx_ptr, map->win_ptr, (y * map->scalefactor
				+ map->left), (map->top + x * map->scalefactor), 0x00FF00);
		i++;
	}
}

void	draw_julia(t_fractol *map, int Px, int Py, int depth)
{
	double		temp_x;
	long double	x0;
	long double	y0;

	x0 = Px / map->scalefactor + map->left;
	y0 = Py / map->scalefactor + map->top;
	while ((x0 * x0 + y0 * y0 < 4) && (depth < map->iterations))
	{
		temp_x = x0 * x0 - y0 * y0 + map->ca;
		y0 = 2 * x0 * y0 + map->cb;
		x0 = temp_x;
		depth = depth + 1;
	}
	ft_put_pixel(map, depth, Px, Py);
}

void	draw_mandelbrot(t_fractol *map, int Px, int Py, int depth)
{
	double		temp_x;
	long double	x0;
	long double	y0;
	long double	x;
	long double	y;

	x0 = Px / map->scalefactor + map->left;
	y0 = Py / map->scalefactor + map->top;
	x = 0;
	y = 0;
	while ((x * x + y * y < 4) && (depth < map->iterations))
	{
		temp_x = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = temp_x;
		depth = depth + 1;
	}	
	ft_put_pixel(map, depth, Px, Py);
}
