/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/02/06 15:09:00 by sunhwang         ###   ########.fr       */
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
		obj->texture_nomal.type = NONE;
	}
	if (sec_arr_len(opt) == 6)
	{
		printf("5 = %s\n", opt[5]);
		init_image(&info->win, &(obj->texture_nomal), opt[5], NORMAL);
	}
}
