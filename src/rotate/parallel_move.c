/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:52:33 by seokchoi          #+#    #+#             */
/*   Updated: 2023/02/02 13:00:41 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "rt_math.h"
#include "parse.h"
#include "thread.h"

void	init_rotate_objs(t_info *rotate, t_info *info)
{
	t_list	*objs;
	t_list	*tmp_objs;
	t_obj	*obj;
	t_obj	*tmp_obj;

	objs = info->objs;
	rotate->objs = NULL;
	while (objs)
	{
		obj = objs->content;
		tmp_objs = ft_malloc(sizeof(t_list));
		tmp_objs->content = ft_malloc(sizeof(t_obj));
		tmp_objs->next = NULL;
		tmp_obj = tmp_objs->content;
		tmp_obj->type = obj->type;
		copy_vector_value(&(tmp_obj->coor), v_minus(obj->coor, info->cam.coor));
		copy_vector_value(&(tmp_obj->normal), obj->normal);
		copy_vector_value(&(tmp_obj->colors), obj->colors);
		init_rotate_from_tmp(tmp_obj, obj);
		if (obj->texture_normal.type != NONE)
			init_rotate_texture_normal(tmp_obj, obj);
		ft_lstadd_back(&(rotate->objs), tmp_objs);
		objs = objs->next;
	}
}

void	init_parallel_movement(t_info *rotate, t_info *info)
{
	init_rotate_from_info_win(rotate, info);
	init_rotate_light(rotate, info);
	init_rotate_objs(rotate, info);
}
