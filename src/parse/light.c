/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/27 14:14:54 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "parse.h"

void	ft_light_add(t_info *info, t_l *light)
{
	t_l	*tmp;

	if (!info->lights)
		info->lights = light;
	else
	{
		tmp = info->lights;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = light;
		light->prev = tmp;
	}
}

void	get_light(t_info *info, char **s)
{
	t_l	*light;

	light = ft_calloc(sizeof(t_l), 1);
	if (!light)
		error_exit("malloc error");
	if (sec_arr_len(s) != 3 && sec_arr_len(s) != 4)
		error_exit("Wrong 1 argument");
	light->coor = get_arg_coor(s[1]);
	light->light_brightness_ratio = ft_atod(s[2]);
	if (check_range(1, light->light_brightness_ratio) == ERR)
		error_exit("Wrong 2 argument");
	if (sec_arr_len(s) == 4)
		light->colors = get_arg_color(s[3]);
	light->next = 0;
	ft_light_add(info, light);
}
