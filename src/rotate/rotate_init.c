/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:47:05 by sunhwang          #+#    #+#             */
/*   Updated: 2023/02/07 13:28:59 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "rt_math.h"
#include "parse.h"
#include "thread.h"

void	init_rotate_from_info_other(t_info *rotate, t_info *info)
{
	copy_vector_value(&(rotate->amb.colors), info->amb.colors);
	rotate->amb.amb_light_ratio = info->amb.amb_light_ratio;
	rotate->cam.coor.x = 0.0;
	rotate->cam.coor.y = 0.0;
	rotate->cam.coor.z = 0.0;
	rotate->cam.normal.x = 0.0;
	rotate->cam.normal.y = 0.0;
	rotate->cam.normal.z = 1.0;
	rotate->cam.fov = info->cam.fov;
	rotate->cam.length = info->cam.length;
	rotate->num_ele.a_count = info->num_ele.a_count;
	rotate->num_ele.c_count = info->num_ele.c_count;
	rotate->num_ele.l_count = info->num_ele.l_count;
	rotate->num_ele.objs_count = info->num_ele.objs_count;
}

void	init_rotate_from_info_win(t_info *rotate, t_info *info)
{
	rotate->win.height = info->win.height;
	rotate->win.width = info->win.width;
	rotate->win.mlx = info->win.mlx;
	rotate->win.mlx_win = info->win.mlx_win;
	rotate->win.terminal.cam_on = info->win.terminal.cam_on;
	rotate->win.terminal.light_on = info->win.terminal.light_on;
	rotate->win.terminal.light_select = info->win.terminal.light_select;
	rotate->win.terminal.curr_light = info->win.terminal.curr_light;
	rotate->win.terminal.prompt = info->win.terminal.prompt;
	rotate->win.terminal.obj_on = info->win.terminal.obj_on;
	rotate->win.terminal.obj_select = info->win.terminal.obj_select;
	rotate->win.terminal.curr_obj = info->win.terminal.curr_obj;
	init_rotate_from_info_other(rotate, info);
}

void	init_rotate_light(t_info *rotate, t_info *info)
{
	t_l	*info_light;
	t_l	*tmp_light;

	rotate->lights = 0;
	info_light = info->lights;
	while (info_light)
	{
		tmp_light = ft_malloc(sizeof(t_l));
		copy_vector_value(&(tmp_light->coor), \
		v_minus(info_light->coor, info->cam.coor));
		copy_vector_value(&(tmp_light->colors), info_light->colors);
		tmp_light->light_brightness_ratio = info_light->light_brightness_ratio;
		ft_light_add(rotate, tmp_light);
		info_light = info_light->next;
	}
}

void	init_rotate_from_tmp(t_obj *tmp_obj, t_obj *obj)
{
		tmp_obj->diameter = obj->diameter;
		tmp_obj->cy_hei = obj->cy_hei;
		tmp_obj->texture.type = obj->texture.type;
		tmp_obj->texture.width = obj->texture.width;
		tmp_obj->texture.height = obj->texture.height;
		tmp_obj->texture.data.addr = obj->texture.data.addr;
		tmp_obj->texture.data.bits_per_pixel = obj->texture.data.bits_per_pixel;
		tmp_obj->texture.data.endian = obj->texture.data.endian;
		tmp_obj->texture.data.img = obj->texture.data.img;
		tmp_obj->texture.data.line_length = obj->texture.data.line_length;
}

void	init_rotate_texture_normal(t_obj *tmp_obj, t_obj *obj)
{
	tmp_obj->texture_normal.type = obj->texture_normal.type;
	tmp_obj->texture_normal.width = obj->texture_normal.width;
	tmp_obj->texture_normal.height = obj->texture_normal.height;
	tmp_obj->texture_normal.data.addr = obj->texture_normal.data.addr;
	tmp_obj->texture_normal.data.bits_per_pixel = \
	obj->texture_normal.data.bits_per_pixel;
	tmp_obj->texture_normal.data.endian = obj->texture_normal.data.endian;
	tmp_obj->texture_normal.data.img = obj->texture_normal.data.img;
	tmp_obj->texture_normal.data.line_length = \
	obj->texture_normal.data.line_length;
}
