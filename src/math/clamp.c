/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:40:45 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/02/02 05:10:59 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_math.h"

int	clamp_int(int val, int min, int max)
{
	return (min_int(max_int(val, min), max));
}

double	clamp_double(double val, double min, double max)
{
	return (min_double(max_double(val, min), max));
}

t_vec3	clamp_3d(t_vec3 v, double min_val, double max_val)
{
	const double	x = clamp_double(v.x, min_val, max_val);
	const double	y = clamp_double(v.y, min_val, max_val);
	const double	z = clamp_double(v.z, min_val, max_val);

	return (vec3(x, y, z));
}
