/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngardzie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:21:01 by ngardzie          #+#    #+#             */
/*   Updated: 2022/05/13 11:21:03 by ngardzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	random_colors(t_fractol *map)
{
	map->color_r += 15;
	map->color_g += 41;
	map->color_b += 10;
}

void	ft_put_pixel(t_fractol *map, int depth, int Px, int Py)
{
	int	pos;

	pos = (Px + (Py * 1000)) * 4;
	if (Px < 1000 && Py < 800 && depth == map->iterations)
	{
		map->mlx_addr[pos] = 0x00;
		map->mlx_addr[pos + 1] = 0x00;
		map->mlx_addr[pos + 2] = 0x00;
	}
	else if (Px < 1000 && Py < 800)
	{
		map->mlx_addr[pos] = map->color_r + (depth * 2);
		map->mlx_addr[pos + 1] = map->color_g + (depth * 3);
		map->mlx_addr[pos + 2] = map->color_b + (depth * 4);
	}
}

void	select_fractal(t_fractol *map, int Px, int Py, int depth)
{
	if (map->type == 1)
		draw_mandelbrot(map, Px, Py, depth);
	else if (map->type == 2)
		draw_julia(map, Px, Py, depth);
	if (map->type == 4)
		draw_burning_ship(map, Px, Py, depth);
}

void	draw(t_fractol *map)
{
	int	py;
	int	px;
	int	depth;

	depth = 0;
	py = 0;
	if (map->type == 3)
		draw_barnsley_fern(map, py, py);
	else
	{
		while (py < 600)
		{
			px = 0;
			while (px < 1000)
			{
				select_fractal(map, px, py, depth);
				px++;
			}
		py++;
		}
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->mlx_img, 0, 0);
	}
	hud_setup(map);
}
