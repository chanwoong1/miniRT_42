/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:50:10 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/02/02 14:38:49 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# include "structs.h"

void	init_info(t_info *info);

//rotate
void	rotate(t_info *rotate, t_info *info);

//rotate init
void	init_rotate_from_info_other(t_info *rotate, t_info *info);
void	init_rotate_from_info_win(t_info *rotate, t_info *info);
void	init_rotate_light(t_info *rotate, t_info *info);
void	init_rotate_from_tmp(t_obj *tmp_obj, t_obj *obj);
void	init_rotate_texture_normal(t_obj *tmp_obj, t_obj *obj);

//parallel_move
void	init_parallel_movement(t_info *rotate, t_info *info);

//rotate_minus
void	rotation_minus(t_info *rotate);

#endif
