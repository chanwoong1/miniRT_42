/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:17:44 by sunhwang          #+#    #+#             */
/*   Updated: 2023/02/07 13:47:24 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "rt_math.h"

/// @brief 모니터 좌표 start와 dir로 향하는 방향을 갖는 구조체
/// @param start start position of the ray
/// @param dir direction of the ray
/// @return
t_ray	get_ray(const t_vec3 start, const t_vec3 dir)
{
	t_ray	ray;

	ray.orig = start;
	ray.normal = dir;
	return (ray);
}

t_point3	ray_at(const t_ray ray, const double t)
{
	t_point3	at;

	at = v_sum(ray.orig, v_mul_double(ray.normal, t));
	return (at);
}
