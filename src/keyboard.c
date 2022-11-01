/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngardzie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:07:59 by ngardzie          #+#    #+#             */
/*   Updated: 2022/06/17 09:08:00 by ngardzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	int	more_keys(int key, t_fractol *map)
{
	if (key == 53)
		exit (1);
	if (key == 13)
		map->scalefactor += 10;
	if (key == 1)
		map->scalefactor -= 10;
	if (key == 123)
		map->left -= 10 / map->scalefactor;
	if (key == 124)
		map->left += 10 / map->scalefactor;
	if (key == 125)
		map->top += 10 / map->scalefactor;
	if (key == 126)
		map->top -= 10 / map->scalefactor;
	if (key == 69)
		map->iterations += 4;
	if (key == 78)
	{
		map->iterations -= 4;
		if (map->iterations <= 0)
			map->iterations = 0;
	}
	return (1);
}

int	keydown(int key, t_fractol *map)
{
	more_keys(key, map);
	if (key == 18)
		init_mandelbrot (map);
	else if (key == 19)
		init_julia (map);
	else if (key == 21)
		init_barnsley_fern (map);
	else if (key == 20)
		init_burning_ship (map);
	else if (key == 23)
	{
		if (map->random_color == 0)
			map->random_color = 1;
		else
			map->random_color = 0;
	}
	mlx_clear_window (map->mlx_ptr, map->win_ptr);
	draw (map);
	return (0);
}
