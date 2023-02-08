/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_minus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:52:33 by seokchoi          #+#    #+#             */
/*   Updated: 2023/02/02 14:39:46 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "rt_math.h"
#include "parse.h"
#include "thread.h"

void	rotation_minus_light(t_info *rotate)
{
	t_l	*rota_light;

	rota_light = rotate->lights;
	while (rota_light)
	{
		copy_vector_value(&(rota_light->coor), \
		vec3(rota_light->coor.x, rota_light->coor.y, -(rota_light->coor.z)));
		rota_light = rota_light->next;
	}
}

void	rotation_minus_objs(t_info *rotate)
{
	t_list	*rotate_list;
	t_obj	*rotate_obj;

	rotate_list = rotate->objs;
	while (rotate_list)
	{
		rotate_obj = (t_obj *)(rotate_list->content);
		copy_vector_value(&(rotate_obj->coor), \
		vec3(rotate_obj->coor.x, rotate_obj->coor.y, -(rotate_obj->coor.z)));
		copy_vector_value(&(rotate_obj->normal), vec3(rotate_obj->normal.x, \
		rotate_obj->normal.y, -(rotate_obj->normal.z)));
		rotate_list = rotate_list->next;
	}
}

void	rotation_minus(t_info *rotate)
{
	rotation_minus_light(rotate);
	rotation_minus_objs(rotate);
}
