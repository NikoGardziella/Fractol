/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngardzie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:52:58 by ngardzie          #+#    #+#             */
/*   Updated: 2022/06/17 10:52:59 by ngardzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_name(t_fractol *map)
{
	if (map->type == 1)
		mlx_string_put(map->mlx_ptr, map->win_ptr, 400, 610,
			0xFFFFFF, "Mandelbrot");
	if (map->type == 2)
		mlx_string_put(map->mlx_ptr, map->win_ptr, 400, 610,
			0xFFFFFF, "Julia");
	if (map->type == 3)
		mlx_string_put(map->mlx_ptr, map->win_ptr, 400, 610,
			0xFFFFFF, "Barnsley Fern");
	if (map->type == 4)
		mlx_string_put(map->mlx_ptr, map->win_ptr, 400, 610,
			0xFFFFFF, "Burning Ship");
}

void	hud_setup(t_fractol *map)
{
	set_name(map);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 50, 680,
		0xFFFFFF, "Move:              ^ v < >");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 50, 700,
		0xFFFFFF, "Change iterations: num + / num -");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 50, 720,
		0xFFFFFF, "zoom:              mouse wheel");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 430, 680,
		0xFFFFFF, "Mandelbrot:    1");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 430, 700,
		0xFFFFFF, "Julia:         2");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 430, 720,
		0xFFFFFF, "Burning ship:  3");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 700, 680,
		0xFFFFFF, "Barnsley Fern:     4");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 700, 700,
		0xFFFFFF, "Psyechedelic mode: 5");
}
