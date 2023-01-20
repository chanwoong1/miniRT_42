/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:13:44 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/20 15:13:19 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"
#include "raytracer.h"
#include "info.h"

static int	is_last_img(t_drawer *drawer)
{
	return (drawer->i == drawer->size - 1);
}

static void	*thread_routine(void *data)
{
	int			x;
	int			y;
	t_drawer	*drawer;
	int			color;

	drawer = (t_drawer *)data;
	t_info *info = drawer->info; 
	x = 0;
	while (x < drawer->width)
	{
		y = 0;
		while (y < drawer->height)
		{
			// TODO render(info, x, y); 계산함수 호출
			// color = create_trgb(0, 0, 200, 200);
			color = calculate_pixel_color(info, x, y);
			// printf("%d ", color);
			put_pixel(&drawer->data, x, y, color);
			y++;
		}
		printf("\n");
		x++;
	}
	return (NULL);
}

static void	create_thread(int i, int size, t_drawer *drawer, t_info *info)
{
	t_data	*d;

	drawer->i = i;
	drawer->size = size;
	drawer->width = info->win.width / size;
	drawer->height = info->win.height;
	drawer->info = info;
	d = &drawer->data;
	if (is_last_img(drawer))
		drawer->width += info->win.width - (info->win.width / size) * size;
	d->img = mlx_new_image(info->win.mlx, drawer->width, drawer->height);
	d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length, \
	&d->endian);
	pthread_create(&drawer->thread, NULL, thread_routine, drawer);
}

static void	attach_thread(int width, t_drawer *drawer, t_window *win)
{
	pthread_join(drawer->thread, NULL);
	printf("i: %d width: %d\n", drawer->i, width);
	mlx_put_image_to_window(win->mlx, win->mlx_win, drawer->data.img, width, 0);
	mlx_destroy_image(win->mlx, drawer->data.img);
	free(drawer);
}

void	start_drawing(t_info *info)
{
	// const int	procs = sysconf(_SC_NPROCESSORS_ONLN);
	const int	procs = 1;

	int			i;
	t_drawer	**drawers;

	drawers = ft_malloc(sizeof(t_drawer *) * (procs + 1));
	i = 0;
	while (i < procs)
	{
		drawers[i] = ft_malloc(sizeof(t_drawer));
		create_thread(i, procs, drawers[i], info);
		i++;
	}
	i = 0;
	while (i < procs)
	{
		attach_thread(info->win.width / procs * i, drawers[i], &info->win);
		i++;
	}
	free(drawers);
}
