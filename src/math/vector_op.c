/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:46:29 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/28 18:45:07 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_math.h"

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_point3	point3(double x, double y, double z)
{
	t_point3	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_point3	color3(double r, double g, double b)
{
	t_color3	color3;

	color3.x = r;
	color3.y = g;
	color3.z = b;
	return (color3);
}

void	vset(t_vec3 *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

double	v_element_sum(t_vec3 v)
{
	return (v.x + v.y + v.z);
}
