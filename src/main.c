/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngardzie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:04:36 by ngardzie          #+#    #+#             */
/*   Updated: 2022/05/12 16:29:24 by ngardzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	initialize(t_fractol *map)
{
	map->color_r = 0x20;
	map->color_g = 0x20;
	map->color_b = 0x00;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, 1000, 800, "FRACTOL");
	map->mlx_img = mlx_new_image(map->mlx_ptr, 1000, 600);
	map->mlx_addr = mlx_get_data_addr(map->mlx_img,
			&map->mlx_bits_per_pixel, &map->mlx_size_line, &map->mlx_endian);
}

int	main(int ac, char **av)
{
	t_fractol	*map;

	if (ac != 2)
		ft_fail ("write: ./fractol mandelbrot, julia, ship or fern");
	if (ft_strcmp(av[1], "mandelbrot") && ft_strcmp (av[1], "julia")
		&& ft_strcmp (av[1], "fern") && ft_strcmp (av[1], "ship"))
		ft_fail ("write: ./fractol mandelbrot, julia, ship or fern");
	map = (t_fractol *)malloc(sizeof(t_fractol));
	initialize(map);
	if (!ft_strcmp(av[1], "mandelbrot"))
		init_mandelbrot(map);
	else if (!ft_strcmp(av[1], "julia"))
		init_julia(map);
	else if (!ft_strcmp(av[1], "fern"))
		init_barnsley_fern(map);
	else if (!ft_strcmp(av[1], "ship"))
		init_burning_ship(map);
	draw(map);
	mlx_key_hook(map->win_ptr, keydown, map);
	mlx_mouse_hook(map->win_ptr, mouse_scale_hook, map);
	mlx_hook(map->win_ptr, 6, 1L << 6, mouse_for_julia, map);
	mlx_loop(map->mlx_ptr);
	free(map);
	return (0);
}
