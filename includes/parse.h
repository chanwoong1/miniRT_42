/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:50:10 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/02/02 14:48:08 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>
# include "error.h"
# include "info.h"

# define SUCCESS 0
# define ERR	 1

// ambient
void	get_ambient(t_info *info, char **s);

// camera
void	get_camera(t_info *info, char **s);
void	camera_setting(t_info *info);

// colors
t_vec3	get_arg_color(char *s);

// coordinate
t_vec3	get_arg_coor(char *s);
void	check_coordinates(t_obj *obj, char *str);

// cylinder
void	set_cy(t_info *info, t_obj *obj, char **opt);

// diameter
void	check_diameter(t_obj *obj, float dia);

// light
void	get_light(t_info *info, char **s);
void	ft_light_add(t_info *info, t_l *light);

// normal
t_vec3	get_arg_normal(char *s);

// objects
void	get_obj(t_info *info, char **opt, char *t);

// parse_rt_file
void	check_file_name(char *file_name);
int		check_range(int type, float ret);
void	edit_info(t_info *info, char *s, t_num_ele *check_count);
bool	read_file(t_info *info, int fd, t_num_ele *check_count);
void	parse_rt_file(t_info *info, char *file_name);

//plane
void	set_pl(t_info *info, t_obj *obj, char **opt);
//sphere
void	set_sp(t_info *info, t_obj *obj, char **opt);
//cone
void	set_cn(t_info *info, t_obj *obj, char **opt);

// utils
int		sec_arr_len(char **arr);
float	ft_atod(char *s);
int		check_only_num1(char *opt, char *oper);
int		check_only_num(char **opt, char *oper);

// utils2
int		check_oper(char c, char *s);

// check_option_count.c
void	check_option_count(char *s, t_num_ele *check_count);

#endif
