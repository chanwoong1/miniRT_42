/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:46:53 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/28 14:48:54 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_math.h"
#include "parse.h"

t_vec3	get_arg_normal(char *s)
{
	char	**tmp;
	float	normal[3];
	t_vec3	v3;

	tmp = ft_split(s, ',');
	if (sec_arr_len(tmp) != 3)
		error_exit("Wrong normal argument num");
	check_only_num(tmp, ".");
	normal[0] = ft_atod(tmp[0]);
	if (check_range(-1, normal[0]) == ERR)
		error_exit("Wrong argument");
	normal[1] = ft_atod(tmp[1]);
	if (check_range(-1, normal[1]) == ERR)
		error_exit("Wrong argument");
	normal[2] = ft_atod(tmp[2]);
	if (check_range(-1, normal[2]) == ERR)
		error_exit("Wrong argument");
	free_double_array((void **)tmp);
	v3 = vunit(vec3(normal[0], normal[1], normal[2]));
	return (v3);
}
