/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:10:51 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/21 21:03:00 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "rt_math.h"

t_vec3	norm_3d_vec(t_vec3 v)
{
	return (vec3(v.x / v_len(v), v.y / v_len(v), v.z / v_len(v)));
}

t_vec3	vunit(t_vec3 v)
{
	double	len;

	len = v_len(v);
	if (len == 0)
		error_exit("Invalid number of arguments. Check it!");
	v.x /= len;
	v.y /= len;
	v.z /= len;
	return (v);
}
