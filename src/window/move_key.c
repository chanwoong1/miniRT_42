/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:08:05 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/02/07 18:14:36 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "structs.h"
#include "info.h"
#include "thread.h"
#include "rt_math.h"

void	key_hook_light_off(t_window *win, t_info *info, t_l *light)
{
	if (info->win.terminal.reverse_color)
	{
		convert_color_light(light, win->terminal.curr_light);
		info->win.terminal.reverse_color = false;
	}
	info->win.terminal.light_on = false;
	info->win.terminal.light_select = false;
	info->win.terminal.curr_light = 0;
	print_turn_off("LIGHTS");
	start_drawing(info);
	terminal_prompt();
}

void	key_hook_object_off(t_window *win, t_info *info, t_list *obj)
{
	if (info->win.terminal.reverse_color)
	{
		convert_color_object(obj, win->terminal.curr_obj);
		info->win.terminal.reverse_color = false;
	}
	win->terminal.obj_on = false;
	win->terminal.obj_select = false;
	win->terminal.curr_obj = 0;
	print_turn_off("OBJECT");
	start_drawing(info);
	terminal_prompt();
}
