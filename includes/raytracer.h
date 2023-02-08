/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:39:59 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/02/08 14:44:27 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include <stdio.h>
# include "structs.h"

t_ray		get_ray(const t_vec3 start, const t_vec3 dir);
t_point3	ray_at(const t_ray ray, const double t);
t_hit		get_hit(double d, t_vec3 point, t_vec3 normal);
t_hit		check_ray_collision_sphere(t_ray ray, t_obj *sphere);
t_hit		check_ray_collision_plane(t_ray ray, t_obj *plane);
t_hit		check_ray_collision_cone(t_ray ray, t_obj *cone);
void		hit_cylinder_cap(t_ray ray, t_obj *cy, t_hit *hit, double hei);
t_hit		check_ray_collision_cone(t_ray ray, t_obj *cone);

//check_ray_collision_cylinder
t_hit		check_ray_collision_cylinder(t_ray ray, t_obj *cylinder);

//raytracer
int			calculate_pixel_color(t_info *info, int x, int y);
void		get_closest_hit_obj(t_list *objs, t_ray ray, \
t_hit *closest_hit, t_obj *closest_obj);

//phong
t_color3	point_light_get(t_info *info, const t_l *light, \
const t_hit closest_hit, const t_obj closest_obj);

// checker
void		checker(t_obj *sphere, const t_hit hit);
void		get_texture_color(t_obj *obj, const t_ray ray, t_hit *hit);
t_vec3		uv_pattern_at(t_vec2 checkers, t_vec2 uv);

#endif
