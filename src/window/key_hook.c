/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:27:30 by sunhwang          #+#    #+#             */
/*   Updated: 2023/02/07 18:24:14 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "structs.h"
#include "info.h"
#include "thread.h"
#include "parse.h"

void	move_coordinate(t_vec3 *coor, int key)
{
	if (key == KEY_Q)
		coor->x -= 1;
	else if (key == KEY_W)
		coor->x += 1;
	else if (key == KEY_A)
		coor->y -= 1;
	else if (key == KEY_S)
		coor->y += 1;
	else if (key == KEY_Z)
		coor->z -= 1;
	else if (key == KEY_X)
		coor->z += 1;
}

static void	binding_key_event_camera(int key, t_info *info)
{
	t_window	*win;
	t_terminal	*term;

	win = &(info->win);
	term = &(info->win.terminal);
	if (key == KEY_1 && term->light_on == false && term->obj_on == false)
		key_hook_camera(win);
	else if (term->cam_on && (key == KEY_Q || key == KEY_W || \
		key == KEY_A || key == KEY_S || key == KEY_Z || key == KEY_X))
		move_camera(key, info);
	else if (term->cam_on && (key >= KEY_ARROW_LEFT && key <= KEY_ARROW_UP))
		move_camera_rotation(key, info);
}

static void	binding_key_event_light(int key, t_info *info)
{
	t_window	*win;
	t_terminal	*term;

	win = &(info->win);
	term = &(info->win.terminal);
	if (key == KEY_2 && term->cam_on == false && term->obj_on == false)
		key_hook_light(win, info);
	else if (term->light_on && term->light_select == false && \
		(key == KEY_B || key == KEY_N || key == KEY_O || key == KEY_2))
		select_light(key, info);
	else if (term->light_select && (key == KEY_Q || key == KEY_W || key == \
		KEY_A || key == KEY_S || key == KEY_Z || key == KEY_X || key == KEY_2))
		move_light(key, info);
}

static void	binding_key_event_objs(int key, t_info *info)
{
	t_window	*win;
	t_terminal	*term;

	win = &(info->win);
	term = &(info->win.terminal);
	if (key == KEY_3 && term->cam_on == false && term->light_on == false)
		key_hook_obj(win, info);
	else if (term->obj_on && term->obj_select == false && \
		(key == KEY_B || key == KEY_N || key == KEY_O || key == KEY_3))
		select_obj(key, info);
	else if (term->obj_select && (key == KEY_Q || key == KEY_W || key == KEY_A \
		|| key == KEY_S || key == KEY_Z || key == KEY_X || key == KEY_3))
		move_objs(key, info);
	else if (term->obj_select && (key >= KEY_ARROW_LEFT && key <= KEY_ARROW_UP))
		move_object_rotation(key, info);
}

int	binding_key_events(int key, t_info *info)
{
	t_window	*win;
	t_terminal	*term;

	win = &(info->win);
	term = &(info->win.terminal);
	if (key == KEY_ESC)
		exit_event(win);
	binding_key_event_camera(key, info);
	binding_key_event_light(key, info);
	binding_key_event_objs(key, info);
	return (0);
}
