/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_object_rotation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:16:43 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/02/02 14:38:50 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "structs.h"
#include "info.h"
#include "thread.h"
#include "rt_math.h"

static void	move_object_rotation_dir(\
	t_info *info, t_vec3 dx, t_vec3 dy, t_vec3 dz)
{
	t_list	*objs;
	int		idx;

	idx = -1;
	objs = info->objs;
	while (++idx < info->win.terminal.curr_obj)
		objs = objs->next;
	copy_vector_value(&(((t_obj *)(objs->content))->normal), vec3(\
		v_element_sum(v_mul(dx, ((t_obj *)(objs->content))->normal)), \
		v_element_sum(v_mul(dy, ((t_obj *)(objs->content))->normal)), \
		v_element_sum(v_mul(dz, ((t_obj *)(objs->content))->normal))));
}

static void	move_object_rotation_xy(double radian, char flag, t_info *info)
{
	t_vec3	dir_x;
	t_vec3	dir_y;
	t_vec3	dir_z;

	if (flag == 'x')
	{
		dir_x = vec3(cos(radian), 0, sin(radian));
		dir_y = vec3(0, 1, 0);
		dir_z = vec3(-sin(radian), 0, cos(radian));
	}
	else
	{
		dir_x = vec3(1, 0, 0);
		dir_y = vec3(0, cos(radian), -sin(radian));
		dir_z = vec3(0, sin(radian), cos(radian));
	}
	move_object_rotation_dir(info, dir_x, dir_y, dir_z);
}

void	move_object_rotation(int key, t_info *info)
{
	if (key == KEY_ARROW_RIGHT)
		move_object_rotation_xy(-degrees_to_radians_double(15), 'x', info);
	else if (key == KEY_ARROW_LEFT)
		move_object_rotation_xy(degrees_to_radians_double(15), 'x', info);
	else if (key == KEY_ARROW_UP)
		move_object_rotation_xy(degrees_to_radians_double(15), 'y', info);
	else if (key == KEY_ARROW_DOWN)
		move_object_rotation_xy(-degrees_to_radians_double(15), 'y', info);
	start_drawing(info);
}
