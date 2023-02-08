/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:33:26 by sunhwang          #+#    #+#             */
/*   Updated: 2023/02/07 13:08:11 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "structs.h"

void	init_window(t_window *win)
{
	win->mlx = mlx_init();
	win->width = 800;
	win->height = 800;
	win->width /= 2;
	win->height /= 2;
	win->mlx_win = mlx_new_window(win->mlx, win->width, win->height, TITLE);
	ft_memset(&win->terminal, 0, sizeof(win->terminal));
}
