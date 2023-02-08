/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 02:03:23 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/30 13:42:03 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "info.h"
#include "rt_math.h"

void	get_camera(t_info *info, char **s)
{
	if (sec_arr_len(s) != 4)
		error_exit("Wrong camera argument num");
	info->cam.coor = get_arg_coor(s[1]);
	info->cam.normal = get_arg_normal(s[2]);
	check_only_num1(s[3], "");
	info->cam.fov = atoi(s[3]);
	if (check_range(180, info->cam.fov) == ERR)
		error_exit("Wrong camera fov argument");
}

void	camera_setting(t_info *info)
{
	const int		width = info->win.width;
	const int		fov = info->cam.fov;
	const double	radian = degrees_to_radians_double(fov / 2);

	info->cam.length = (double)width / (2.0 * tan(radian));
}
