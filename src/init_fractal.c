/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngardzie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:39:21 by ngardzie          #+#    #+#             */
/*   Updated: 2022/06/14 14:39:23 by ngardzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_mandelbrot(t_fractol *map)
{
		map->iterations = 20;
		map->scalefactor = 250;
		map->left = -2.5;
		map->top = -1.20;
		map->type = 1;
}

void	init_julia(t_fractol *map)
{
		map->type = 2;
		map->top = -2;
		map->left = -3.4;
		map->iterations = 20;
		map->scalefactor = 150;
}

void	init_barnsley_fern(t_fractol *map)
{
		map->type = 3;
		map->scalefactor = 80;
		map->iterations = 50;
		map->left = 100;
		map->top = 250;
}

void	init_burning_ship(t_fractol *map)
{
		map->iterations = 20;
		map->scalefactor = 250;
		map->left = -2.5;
		map->top = -1.70;
		map->type = 4;
}
