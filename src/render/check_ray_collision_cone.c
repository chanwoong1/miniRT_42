/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ray_collision_cone.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:15:54 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/02/06 21:25:07 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "raytracer.h"
#include "rt_math.h"
#include "window.h"

static void	init_cone(t_ray r, t_obj *c, t_cone_setting *s)
{
	s->t = v_sum(c->coor, v_mul_double(c->normal, c->cy_hei));
	s->h = v_minus(c->coor, s->t);
	s->uh = vunit(s->h);
	s->m = pow(c->diameter / 2, 2) / pow(v_len(s->h), 2);
	s->w = v_minus(r.orig, s->t);
	s->a = v_dot(r.normal, r.normal) - (s->m * pow(v_dot(r.normal, s->uh), 2)) \
		- pow(v_dot(r.normal, s->uh), 2);
	s->b = 2 * (v_dot(r.normal, s->w) - (s->m * v_dot(r.normal, s->uh) * \
		v_dot(s->w, s->uh)) - v_dot(r.normal, s->uh) * v_dot(s->w, s->uh));
	s->c = v_dot(s->w, s->w) - (s->m * pow(v_dot(s->w, s->uh), 2)) - \
		pow(v_dot(s->w, s->uh), 2);
	s->d = s->b * s->b - (4 * s->a * s->c);
}

static void	check_ray_collision_cone_side(t_ray r, t_obj *c, t_hit *h)
{
	t_cone_setting	s;

	init_cone(r, c, &s);
	if (v_len(v_minus(c->coor, v_sum(r.orig, v_mul_double(r.normal, \
		min_double((-s.b - sqrt(s.d)), (-s.b + sqrt(s.d))) / \
		(2 * s.a))))) > c->cy_hei)
		return ;
	s.s = v_len(v_minus(s.t, v_sum(r.orig, v_mul_double(r.normal, \
		min_double((-s.b - sqrt(s.d)), (-s.b + sqrt(s.d))) / (2 * s.a)))));
	if (s.d >= 0 && \
		sqrt(pow(c->diameter / 2, 2) + pow(v_len(s.h), 2)) >= s.s)
	{
		h->d = min_double((-s.b - sqrt(s.d)), (-s.b + sqrt(s.d))) / (2 * s.a);
		h->point = v_sum(r.orig, v_mul_double(r.normal, h->d));
		h->normal = norm_3d_vec(v_minus(h->point, c->coor));
	}
}

t_hit	check_ray_collision_cone(t_ray ray, t_obj *cone)
{
	t_hit			hit;

	hit = get_hit(-1.0, vec3(0.0, 0.0, 0.0), vec3(0.0, 0.0, 0.0));
	hit_cylinder_cap(ray, cone, &hit, 0);
	check_ray_collision_cone_side(ray, cone, &hit);
	return (hit);
}
