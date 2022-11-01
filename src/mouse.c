/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngardzie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:56:53 by ngardzie          #+#    #+#             */
/*   Updated: 2022/06/17 09:56:55 by ngardzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_for_julia(int x, int y, t_fractol *map)
{
	if (map->type == 2)
	{
		map->ca = x / map->scalefactor + map->left;
		map->cb = y / map->scalefactor + map->top;
		draw(map);
	}
	if (map->random_color == 1)
		random_colors(map);
	return (0);
}

void	zoom_in(t_fractol *map, int x, int y)
{
	float	scale;

	scale = 0;
	scale = map->scalefactor * 1.3;
	map->left = ((double)x / map->scalefactor + map->left) - (scale / 2);
	map->left += (scale / 2) - ((double)x / scale);
	map->top = ((double)y / map->scalefactor + map->top) - (scale / 2);
	map->top += (scale / 2) - ((double)y / scale);
	map->scalefactor *= 1.3;
	map->iterations += 2;
}

void	zoom_out(t_fractol *map, int x, int y)
{
	float	scale;

	scale = 0;
	if (map->iterations <= 0)
		return ;
	scale = map->scalefactor * 0.8;
	map->left = ((double)x / map->scalefactor + map->left) - (scale / 2);
	map->left += (scale / 2) - ((double)x / scale);
	map->top = ((double)y / map->scalefactor + map->top) - (scale / 2);
	map->top += (scale / 2) - ((double)y / scale);
	map->scalefactor *= 0.8;
	map->iterations -= 2;
}

int	mouse_scale_hook(int k, int x, int y, t_fractol *map)
{
	if (k == 1 || k == 4)
		zoom_in (map, x, y);
	else if (k == 2 || k == 5)
		zoom_out (map, x, y);
	mlx_clear_window (map->mlx_ptr, map->win_ptr);
	draw (map);
	return (1);
}
