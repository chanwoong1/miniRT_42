/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:44:25 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/17 14:16:41 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

#define ZOOM 1.1
#define LEFT_CLICK 1
#define RIGHT_CLICK 2
#define MIDDLE_CLICK 3
#define SCROLL_UP 4
#define SCROLL_DOWN 5

static int	is_inside_of_window(int x, int y, t_window *win)
{
	if ((x < 0 || y < 0) || (win->width < x || win->height < y))
		return (1);
	return (0);
}

static void	mouse_hook_scroll(int button, int x, int y, t_window *win)
{
	if (!is_inside_of_window(x, y, win))
		return ;
	if (button == SCROLL_UP)
	{
		(void)win;
	}
	else if (button == SCROLL_DOWN)
	{
		(void)win;
	}
}

int	binding_mouse_events(int button, int x, int y, t_window *win)
{
	if (button == LEFT_CLICK)
	{
		if (!is_inside_of_window(x, y, win))
			return (0);
	}
	else if (button == SCROLL_UP || button == SCROLL_DOWN)
		mouse_hook_scroll(button, x, y, win);
	return (0);
}
