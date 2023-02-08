/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/02/02 20:25:21 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "info.h"
#include "rt_math.h"
#include "window.h"

void	set_cn(t_info *info, t_obj *obj, char **opt)
{
	if (sec_arr_len(opt) != 6 && sec_arr_len(opt) != 7)
		error_exit("Wrong cone argument");
	check_coordinates(obj, opt[1]);
	obj->normal = get_arg_normal(opt[2]);
	check_diameter(obj, ft_atod(opt[3]));
	obj->cy_hei = ft_atod(opt[4]);
	if (obj->cy_hei <= 0)
		error_exit("Wrong cone argument");
	obj->colors.x = get_arg_color(opt[5]).x;
	obj->colors.y = get_arg_color(opt[5]).y;
	obj->colors.z = get_arg_color(opt[5]).z;
	if (sec_arr_len(opt) == 7)
		init_image(&info->win, &obj->texture, opt[4], DIFFUSE);
}
