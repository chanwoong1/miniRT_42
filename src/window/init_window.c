/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:33:26 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/25 15:31:40 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	init_window(t_window *win)
{
	win->mlx = mlx_init();
	// mlx_get_screen_size(win->mlx, &win->width, &win->height);
	// win->width = 100;
	// win->height = 100;
	win->width = 2560;
	win->height = 1400;
	win->width /= 2;
	win->height /= 2;
	win->mlx_win = mlx_new_window(win->mlx, win->width, win->height, TITLE);
}
