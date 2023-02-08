/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:48:21 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/27 14:13:26 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "info.h"

void	get_ambient(t_info *info, char **s)
{
	if (sec_arr_len(s) != 3)
		error_exit("Wrong ambient argument");
	check_only_num1(s[1], ".");
	info->amb.amb_light_ratio = ft_atod(s[1]);
	if (check_range(1, info->amb.amb_light_ratio) == ERR)
		error_exit("Wrong argument:A:amb_L");
	info->amb.colors = get_arg_color(s[2]);
}
