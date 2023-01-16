/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:50:10 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/17 02:08:40 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
#define PARSE_H

#include "minirt.h"

// ambient
void	get_ambient(t_info *info, char **s);

// camera
void	get_camera(t_info *info, char **s);

// colors
t_vec3	*get_arg_color(char *s);

// coordinate
t_vec3	*get_arg_coor(char *s);

// diameter
void	check_diameter(t_objs *obj, float dia);

// light
void	get_light(t_info *info, char **s);

// normal
t_vec3	*get_arg_normal(char *s);
void	check_normal_vector(t_objs *obj, char *str);

// objects
void	check_obj(t_objs *obj, char **opt, t_type type);
void	get_obj(t_info *info, char **opt, t_type type);

// parse_rt_file
void	check_file_name(char *file_name);
int		check_range(int type, float ret);
void	edit_info(t_info *info, char *s);
char	*read_file(t_info *info, char *file_name);
char	*parse_rt_file(t_info *info, char *file_name);

//plane
void	set_pl(t_objs *obj, char **opt);

//sphere
void	set_sp(t_objs *obj, char **opt);

// utils
int		sec_arr_len(char **arr);
void	free_sec_arr(char *arr);
float	ft_atof(char *s);
int		check_only_num1(char *opt, char *oper);
int		check_only_num(char **opt, char *oper);

// utils2
int		check_oper(char c, char *s);

#endif
