/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/02/06 18:48:02 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "info.h"
#include "window.h"

void	set_sp(t_info *info, t_obj *obj, char **opt)
{
	if (sec_arr_len(opt) < 4 && sec_arr_len(opt) > 6)
		error_exit("Wrong argument");
	check_coordinates(obj, opt[1]);
	check_diameter(obj, ft_atod(opt[2]));
	obj->colors = get_arg_color(opt[3]);
	if (sec_arr_len(opt) >= 5)
	{
		init_image(&info->win, &(obj->texture), opt[4], DIFFUSE);
		obj->texture_normal.type = NONE;
	}
	if (sec_arr_len(opt) == 6)
	{
		init_image(&info->win, &(obj->texture_normal), opt[5], NORMAL);
	}
	obj->normal.x = 0;
	obj->normal.y = 0;
	obj->normal.z = 1;
}
