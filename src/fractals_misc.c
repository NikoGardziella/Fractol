/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_misc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngardzie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:24:27 by ngardzie          #+#    #+#             */
/*   Updated: 2022/06/17 12:24:29 by ngardzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	linear_congruential_generator(int seed)
{
	seed = (seed * 1103515245 + 12345) & ((1U << 31) - 1);
	return (seed);
}

float	check_fern_x(int randomnum, float x, float y)
{
	if (randomnum == 0)
		x = 0;
	else if (randomnum <= 86)
		x = 0.85 * x + 0.04 * y;
	else if (randomnum <= 93)
		x = 0.2 * x - 0.26 * y;
	else
		x = -0.15 * x + 0.28 * y;
	return (x);
}

float	check_fern_y(int randomnum, float x, float y)
{
	if (randomnum == 0)
		y = 0.16 * y;
	else if (randomnum <= 86)
		y = -0.04 * x + 0.85 * y + 1.60;
	else if (randomnum <= 93)
		y = 0.23 * x + 0.22 * y + 1.6;
	else
		y = 0.26 * x + 0.24 * y + 0.44;
	return (y);
}
