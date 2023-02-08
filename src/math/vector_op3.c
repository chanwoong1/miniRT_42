/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 23:08:59 by yje               #+#    #+#             */
/*   Updated: 2023/01/27 15:47:23 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_math.h"

t_vec3	v_mul(t_vec3 v1, t_vec3 v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	return (v1);
}

t_vec3	v_mul_double(t_vec3 v, double t)
{
	v.x *= t;
	v.y *= t;
	v.z *= t;
	return (v);
}

t_vec3	v_divide(t_vec3 v, double t)
{
	v.x *= 1 / t;
	v.y *= 1 / t;
	v.z *= 1 / t;
	return (v);
}

double	v_len(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vec3	vmin(t_vec3 vec1, t_vec3 vec2)
{
	if (vec1.x > vec2.x)
		vec1.x = vec2.x;
	if (vec1.y > vec2.y)
		vec1.y = vec2.y;
	if (vec1.z > vec2.z)
		vec1.z = vec2.z;
	return (vec1);
}
