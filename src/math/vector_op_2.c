/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 23:07:54 by yje               #+#    #+#             */
/*   Updated: 2023/01/21 23:25:23 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_math.h"

t_vec2	vec2(double x, double y)
{
	t_vec2	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

t_vec4	vec4(double x1, double x2, double x3, double x4)
{
	t_vec4	vec;

	vec.x1 = x1;
	vec.x2 = x2;
	vec.x3 = x3;
	vec.x4 = x4;
	return (vec);
}

t_vec4	vec4_input_3d(t_vec3 v, double x)
{
	t_vec4	v1;

	v1.x1 = v.x;
	v1.x2 = v.y;
	v1.x3 = v.z;
	v1.x4 = x;
	return (v1);
}

void	copy_vector_value(t_vec3 *dst, t_vec3 src)
{
	dst->x = src.x;
	dst->y = src.y;
	dst->z = src.z;
}
