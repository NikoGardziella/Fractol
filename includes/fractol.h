/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngardzie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:11:53 by ngardzie          #+#    #+#             */
/*   Updated: 2022/06/17 13:11:56 by ngardzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

typedef struct s_fractol
{
	void		*win_ptr;
	void		*mlx_ptr;
	char		*mlx_addr;
	void		*mlx_img;
	int			mlx_bits_per_pixel;
	int			mlx_size_line;
	int			mlx_endian;
	int			random_color;
	int			color_r;
	int			color_g;
	int			color_b;
	int			iterations;
	long double	scalefactor;
	long double	left;
	long double	top;
	int			type;
	double		ca;
	double		cb;
}			t_fractol;

void	hud_setup(t_fractol *map);
void	draw(t_fractol *map);
int		linear_congruential_generator(int seed);
void	ft_put_pixel(t_fractol *map, int depth, int Px, int Py);
void	random_colors(t_fractol *map);

void	draw_burning_ship(t_fractol *map, int Px, int Py, int depth);
void	draw_mandelbrot(t_fractol *map, int x, int y, int depth);
void	draw_barnsley_fern(t_fractol *map, float x, float y);
void	draw_julia(t_fractol *map, int Px, int Py, int depth);

void	init_mandelbrot(t_fractol *map);
void	init_julia(t_fractol *map);
void	init_barnsley_fern(t_fractol *map);
void	init_burning_ship(t_fractol *map);

int		keydown(int key, t_fractol *map);
int		mouse_for_julia(int x, int y, t_fractol *map);
int		mouse_scale_hook(int k, int x, int y, t_fractol *map);

void	hud_setup(t_fractol *map);
float	check_fern_y(int randomnum, float x, float y);
float	check_fern_x(int randomnum, float x, float y);
int		linear_congruential_generator(int seed);

#endif
