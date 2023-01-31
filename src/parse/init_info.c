/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:48:40 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/27 14:14:54 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"

void	init_info(t_info *info)
{
	info->lights = 0;
	info->objs = 0;
	info->num_ele.a_count = 0;
	info->num_ele.c_count = 0;
	info->num_ele.l_count = 0;
	info->num_ele.cy_count = 0;
	info->num_ele.pl_count = 0;
	info->num_ele.sp_count = 0;
	info->num_ele.objs_count = 0;
}
