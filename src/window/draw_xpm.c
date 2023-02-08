/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:33:26 by sunhwang          #+#    #+#             */
/*   Updated: 2023/02/06 20:39:55 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "structs.h"
#include "rt_math.h"
#include "window.h"
#include <stdio.h>

t_vec3	get_texture_image_color(t_texture *texture, const t_vec2 uv)
{
	const double	v = 1 - uv.y;
	const double	x = uv.x * (texture->width - 1);
	const double	y = v * (texture->height - 1);
	t_vec4			color;

	color = get_v_color(*(int *)get_pixel(&texture->data, round(x), round(y)));
	return (vec3(color.x2, color.x3, color.x4));
}

t_vec3	sample_normal_map(t_texture *texture_normal, const t_vec2 uv, \
t_hit *hit, t_vec3 tangent)
{
	const t_vec3	rgb = get_texture_image_color(texture_normal, uv);
	t_vec3			derivative;
	t_vec3			r_tangent_result;
	t_vec3			g_bitangent_result;
	t_vec3			b_normal_result;

	derivative.x = rgb.x / 255.0 * 2.0 - 1.0;
	derivative.y = rgb.y / 255.0 * 2.0 - 1.0;
	derivative.z = rgb.z / 255.0 * 2.0 - 1.0;
	r_tangent_result = v_mul_double(tangent, derivative.x);
	g_bitangent_result = v_mul_double(v_cross(hit->normal, tangent), \
	derivative.y);
	b_normal_result = v_mul_double(hit->normal, derivative.z);
	return (vunit(v_sum(v_sum(b_normal_result, g_bitangent_result), \
	r_tangent_result)));
}
