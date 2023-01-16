/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:49:25 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/17 01:56:45 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vec3	*get_arg_coor(char *s)
{
	char	**tmp;
	float	color[3];

	tmp = ft_split(s[2], ',');
	if (!tmp[3])
		error_exit("wrong argument");
	check_only_num(tmp, ".");
	color[0] = ft_atof(tmp[0]);
	while (!(tmp >= '0' && tmp <= '9') && tmp != 0)
		s++;
	color[1] = ft_atof(tmp[1]);
	while (!(tmp >= '0' && tmp <= '9') && tmp != 0)
		s++;
	color[2] = ft_atof(tmp[2]);
	return (create_3d_vec(color[0],color[1], color[2]));
}

void	check_coordinates(t_objs *obj, char *str) // 모든 coor을 체크 할 수 있음.
{
	char **coor;

	coor = ft_split(str, ',');
	if (!coor)
		error_exit("Malloc Error\n");
	if (sec_arr_len(coor) != 3) // vector 3인지 체크
		error_exit("wrong argument");
	check_only_num1(coor[0], "."); // 숫자와 . 으로 이루어졌는지는 체크.
	check_only_num1(coor[1], ".");
	check_only_num1(coor[2], ".");
	obj->coor = create_3d_vec(ft_atof(coor[0]),\
	ft_atof(coor[1]), ft_atof(coor[2]));
	free_sec_arr(coor);
}
