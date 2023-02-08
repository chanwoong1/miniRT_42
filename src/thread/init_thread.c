/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:13:44 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/27 16:15:57 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"
#include "raytracer.h"
#include "window.h"

static void	*thread_routine(void *data)
{
	int			x;
	int			y;
	t_drawer	*drawer;
	int			color;

	drawer = (t_drawer *)data;
	x = 0;
	while (x < drawer->width)
	{
		y = 0;
		while (y < drawer->height)
		{
			color = calculate_pixel_color(\
				drawer->info, drawer->width * drawer->i + x, y);
			put_pixel(&drawer->data, x, y, color);
			y++;
		}
		x++;
	}
	return (NULL);
}

void	start_drawing(t_info *info)
{
	const int	width = info->win.width;
	const int	height = info->win.height;
	t_drawer	drawer;
	t_data		*d;

	drawer.i = 0;
	drawer.size = 1;
	drawer.width = width;
	drawer.height = height;
	drawer.info = info;
	d = &drawer.data;
	d->img = mlx_new_image(info->win.mlx, width, height);
	d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length, \
	&d->endian);
	thread_routine(&drawer);
	mlx_put_image_to_window(info->win.mlx, info->win.mlx_win, \
	drawer.data.img, 0, 0);
	mlx_destroy_image(info->win.mlx, drawer.data.img);
}
