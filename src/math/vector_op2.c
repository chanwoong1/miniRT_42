/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:29:43 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/21 23:25:23 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_math.h"

t_vec3	v_sum(t_vec3 v1, t_vec3 v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

t_vec3	v_sum_double(t_vec3 v, double x, double y, double z)
{
	v.x += x;
	v.y += y;
	v.z += z;
	return (v);
}

t_vec3	v_minus(t_vec3 v1, t_vec3 v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

t_vec3	v_change_minus(t_vec3 v1)
{
	t_vec3	v;

	v.x = -v1.x;
	v.y = -v1.y;
	v.z = -v1.z;
	return (v);
}

t_vec3	v_minus_double(t_vec3 v, double x, double y, double z)
{
	v.x -= x;
	v.y -= y;
	v.z -= z;
	return (v);
}
