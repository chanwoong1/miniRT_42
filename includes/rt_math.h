/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:50:24 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/28 14:48:54 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATH_H
# define RT_MATH_H

// #include "minirt.h"
# include <math.h>
# include "structs.h"

/*
* '+', '*', '-' operator of vector
*/

/* vector Generator */
t_vec2		vec2(double x, double y);
t_vec3		vec3(double x, double y, double z);
t_vec4		vec4(double x1, double x2, double x3, double x4);
t_vec4		vec4_input_3d(t_vec3 v, double x);
t_point3	point3(double x, double y, double z);
t_point3	color3(double r, double g, double b);
void	  	vset(t_vec3 *v, double x, double y, double z);

t_vec3		v_sum(t_vec3 v1, t_vec3 v2);
t_vec3		v_sum_double(t_vec3 v, double x, double y, double z);
t_vec3		v_change_minus(t_vec3 v1);
t_vec3		v_minus(t_vec3 v1, t_vec3 v2);
t_vec3		v_minus_double(t_vec3 v, double x, double y, double z);
t_vec3		v_mul(t_vec3 v1, t_vec3 v2);
t_vec3		v_mul_double(t_vec3 v, double t);
t_vec3		v_divide(t_vec3 v, double t);
t_vec3		vmin(t_vec3 vec1, t_vec3 vec2);
t_vec3		vunit(t_vec3 v);
t_vec3		norm_3d_vec(t_vec3 v);

double		min_double(double f1, double f2);
double		max_double(double f1, double f2);

// t_vec2	clamp_2d(t_vec2 v, double min_val, double max_val);
t_vec3		clamp_3d(t_vec3 v, double min_val, double max_val);
// t_vec4	clamp_4d(t_vec4 v, double min_val, double max_val);
// t_vec3	*vec_multiple(t_vec3 *v1, t_vec3 *v2);
// t_vec3	*vec_subtract(t_vec3 *v1, t_vec3 *v2);

double    abs_double(double d);
t_vec3	vscale(t_vec3 v, double s);

/*
* Return a length of vector
*/
double		v_len(t_vec3 v);
/*

* dot and cross product of vector
*/
double		v_dot(t_vec3 v1, t_vec3 v2);
t_vec3		v_cross(t_vec3 v1, t_vec3 v2);

double		degrees_to_radians_double(double degrees);
double		degrees_to_radians_double(double degrees);

#endif
