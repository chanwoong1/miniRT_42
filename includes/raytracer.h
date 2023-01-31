/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:39:59 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/31 18:30:00 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include <stdio.h>
# include "structs.h"

t_ray		get_ray(t_vec3 start, t_vec3 dir);
t_point3	ray_at(t_ray ray, double t);
t_hit		get_hit(double d, t_vec3 point, t_vec3 normal);
t_hit		check_ray_collision_sphere(t_ray ray, t_obj *sphere);
t_hit		check_ray_collision_plane(t_ray ray, t_obj *plane);
t_hit	check_ray_collision_cone(t_ray ray, t_obj *cone);
void	hit_cylinder_cap(t_ray ray, t_obj *cy, t_hit *hit, double hei);
t_hit	check_ray_collision_cone(t_ray ray, t_obj *cone);
void	check_ray_collision_cone_side(t_ray ray, t_obj *cone, t_hit *hit);

//check_ray_collision_cylinder
t_hit		check_ray_collision_cylinder(t_ray ray, t_obj *cylinder);

//raytracer
int			calculate_pixel_color(t_info *info, int x, int y);
void		get_closest_hit_obj(t_list *objs, t_hit *closest_hit, t_ray ray, \
t_obj **closest_obj);

//phong
bool		in_shadow(t_list *objs, t_ray light_ray);
t_color3	get_specular(t_info *info, t_hit *hit, t_l *light, \
t_vec3 light_dir);
t_color3	point_light_get(t_info *info, t_hit *hit, t_l *light, \
t_obj *closest_obj);
#endif
