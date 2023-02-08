/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:10:51 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/02/02 02:56:23 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_math.h"
#include "error.h"

t_vec3	norm_3d_vec(t_vec3 v)
{
	return (vec3(v.x / v_len(v), v.y / v_len(v), v.z / v_len(v)));
}

t_vec3	vunit(t_vec3 v)
{
	double	len;

	len = v_len(v);
	if (len == 0)
	{
		printf("[%f, %f, %f]\n", v.x, v.y, v.z);
		error_exit("11 Invalid number of arguments. Check it!");
	}
	v.x /= len;
	v.y /= len;
	v.z /= len;
	return (v);
}

t_vec3	vscale(t_vec3 v, double s)
{
	return (vec3((v.x * s), (v.y * s), (v.z * s)));
}
