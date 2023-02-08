/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:59:02 by sunhwang          #+#    #+#             */
/*   Updated: 2023/02/07 14:01:12 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "raytracer.h"
#include "rt_math.h"
#include "window.h"

#define BLACK 0

t_vec3	uv_pattern_at(t_vec2 checkers, t_vec2 uv)
{
	const double	u2 = floor(uv.x * checkers.x);
	const double	v2 = floor(uv.y * checkers.y);
	int				i;

	i = u2 + v2;
	if (i % 2 == BLACK)
		return (black_v3());
	else
		return (white_v3());
}

t_vec2	spherical_map(t_vec3 p)
{
	const double	theta = atan2(p.x, p.z);
	const t_vec3	vec = vec3(p.x, p.y, p.z);
	const double	radius = v_len(vec);
	t_vec2			uv;

	uv.x = 1.0 - ((theta / (2 * PI)) + 0.5);
	uv.y = 1.0 - (acos(p.y / radius)) / PI;
	return (uv);
}

void	checker(t_obj *sphere, const t_hit hit)
{
	const t_vec2	checkers = vec2(12, 12);
	const t_vec2	uv = spherical_map(hit.normal);

	sphere->colors = uv_pattern_at(checkers, uv);
}

/// @brief object의 color를 texture color로 바꿀 수 있다..
/// @param obj 바꾸고 싶은 object
/// @param hit obj에 부딪힌 hit
/// @return
void	get_texture_color(t_obj *obj, const t_ray ray, t_hit *hit)
{
	const t_vec2	uv = spherical_map(hit->normal);

	obj->colors = get_texture_image_color(&obj->texture, uv);
	if (obj->texture_normal.type == NORMAL)
		hit->normal = sample_normal_map(&obj->texture_normal, uv, hit, \
		v_cross(ray.normal, hit->normal));
}
