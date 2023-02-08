/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:49:25 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/26 16:32:10 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_math.h"
#include "parse.h"

t_vec3	get_arg_coor(char *s)
{
	char	**tmp;
	float	color[3];

	tmp = ft_split(s, ',');
	if (sec_arr_len(tmp) != 3)
		error_exit("Wrong coor argument num");
	check_only_num(tmp, "-.");
	color[0] = ft_atod(tmp[0]);
	color[1] = ft_atod(tmp[1]);
	color[2] = ft_atod(tmp[2]);
	free_double_array((void **)tmp);
	return (vec3(color[0], color[1], color[2]));
}

/*
* 모든 coordinates를 체크 할 수 있음
* vector가 3인지 체크
* 숫자와 . 으로 이루어졌는지 체크
*/
void	check_coordinates(t_obj *obj, char *str)
{
	char	**coor;

	coor = ft_split(str, ',');
	if (!coor)
		error_exit("Malloc Error");
	if (sec_arr_len(coor) != 3)
		error_exit("Wrong coor argument num");
	check_only_num1(coor[0], ".");
	check_only_num1(coor[1], ".");
	check_only_num1(coor[2], ".");
	obj->coor = vec3(ft_atod(coor[0]), ft_atod(coor[1]), ft_atod(coor[2]));
	free_double_array((void **)coor);
}
