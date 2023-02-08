/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/02/02 20:25:13 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "info.h"
#include "window.h"

void	set_pl(t_info *info, t_obj *obj, char **opt)
{
	if (sec_arr_len(opt) != 4 && sec_arr_len(opt) != 5)
		error_exit("Wrong plane argument num");
	check_coordinates(obj, opt[1]);
	obj->normal = get_arg_normal(opt[2]);
	obj->colors = get_arg_color(opt[3]);
	if (sec_arr_len(opt) == 5)
		init_image(&info->win, &obj->texture, opt[4], DIFFUSE);
	if (sec_arr_len(opt) == 5 && ft_strncmp(opt[4], "checker\n", 8) == 0)
		obj->texture.type = CHECK;
}
