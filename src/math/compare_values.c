/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:43:16 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/20 16:29:27 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_math.h"

double	max_double(double f1, double f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

double	min_double(double f1, double f2)
{
	if (f1 > f2)
		return (f2);
	return (f1);
}

int	max_int(int i1, int i2)
{
	if (i1 > i2)
		return (i1);
	return (i2);
}

int	min_int(int i1, int i2)
{
	if (i1 > i2)
		return (i2);
	return (i1);
}
