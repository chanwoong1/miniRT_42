/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera_rotation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:57:37 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/02/02 14:38:50 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "structs.h"
#include "info.h"
#include "thread.h"
#include "rt_math.h"

static void	move_cam_rotation_light(\
	t_info *info, t_vec3 dx, t_vec3 dy, t_vec3 dz)
{
	t_l		*light;
	int		idx;

	light = info->lights;
	idx = -1;
	while (++idx < info->num_ele.l_count)
	{
		copy_vector_value(&(light->coor), vec3(\
			v_element_sum(v_mul(dx, light->coor)), \
			v_element_sum(v_mul(dy, light->coor)), \
			v_element_sum(v_mul(dz, light->coor))));
		light = light->next;
	}
}

static void	move_cam_rotation_object(\
	t_info *info, t_vec3 dx, t_vec3 dy, t_vec3 dz)
{
	t_list	*objs;
	int		idx;

	objs = info->objs;
	idx = -1;
	while (++idx < info->num_ele.objs_count)
	{
		copy_vector_value(&(((t_obj *)(objs->content))->coor), vec3(\
			v_element_sum(v_mul(dx, ((t_obj *)(objs->content))->coor)), \
			v_element_sum(v_mul(dy, ((t_obj *)(objs->content))->coor)), \
			v_element_sum(v_mul(dz, ((t_obj *)(objs->content))->coor))));
		copy_vector_value(&(((t_obj *)(objs->content))->normal), vec3(\
			v_element_sum(v_mul(dx, ((t_obj *)(objs->content))->normal)), \
			v_element_sum(v_mul(dy, ((t_obj *)(objs->content))->normal)), \
			v_element_sum(v_mul(dz, ((t_obj *)(objs->content))->normal))));
		objs = objs->next;
	}
}

static void	move_cam_rotation_xy(double radian, char flag, t_info *info)
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
	move_cam_rotation_object(info, dir_x, dir_y, dir_z);
	move_cam_rotation_light(info, dir_x, dir_y, dir_z);
}

void	move_camera_rotation(int key, t_info *info)
{
	if (key == KEY_ARROW_RIGHT)
		move_cam_rotation_xy(-degrees_to_radians_double(15), 'x', info);
	else if (key == KEY_ARROW_LEFT)
		move_cam_rotation_xy(degrees_to_radians_double(15), 'x', info);
	else if (key == KEY_ARROW_UP)
		move_cam_rotation_xy(degrees_to_radians_double(15), 'y', info);
	else if (key == KEY_ARROW_DOWN)
		move_cam_rotation_xy(-degrees_to_radians_double(15), 'y', info);
	start_drawing(info);
}
