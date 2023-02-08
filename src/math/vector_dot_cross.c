/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_dot_cross.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:14:35 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/20 16:29:23 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_math.h"

double	v_dot(t_vec3 v1, t_vec3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec3	v_cross(t_vec3 v1, t_vec3 v2)
{
	t_vec3	ret_vector;

	ret_vector.x = v1.y * v2.z - v1.z * v2.y;
	ret_vector.y = v1.z * v2.x - v1.x * v2.z;
	ret_vector.z = v1.x * v2.y - v1.y * v2.x;
	return (ret_vector);
}
