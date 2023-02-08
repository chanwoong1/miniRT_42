/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:56:12 by sunhwang          #+#    #+#             */
/*   Updated: 2023/02/07 18:15:01 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "mlx.h"
# include "structs.h"
# define TITLE "Hello miniRT!"

// Size
# define MAX_WIDTH 2560
# define MAX_HEIGHT 1400

// Keys
# define KEY_ESC 53
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_RIGHT 124
# define KEY_ARROW_DOWN 125
# define KEY_ARROW_UP 126
# define KEY_1		18
# define KEY_2		19
# define KEY_3		20
# define KEY_Q		12
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_Z		6
# define KEY_X		7
# define KEY_B		11
# define KEY_N		45
# define KEY_O		31

void		init_window(t_window *win);
void		binding_events(t_info *info);
int			binding_key_events(int key, t_info *info);
int			binding_mouse_events(int button, int x, int y, t_window *win);
int			exit_event(t_window *win);
char		*get_pixel(t_data *data, int x, int y);
void		put_pixel(t_data *data, int x, int y, int color);
int			get_color(t_vec3 vec);
t_vec4		get_v_color(int color);
t_color3	white_v3(void);
t_color3	black_v3(void);
void		terminal_prompt(void);
void		remote_controler(char *input);
void		move_coordinate(t_vec3 *coor, int key);
void		key_hook_camera(t_window *win);
void		rotation_controler(char *input);
void		move_camera(int key, t_info *info);
void		move_camera_rotation(int key, t_info *info);
void		key_hook_light(t_window *win, t_info *info);
void		key_hook_light_off(t_window *win, t_info *info, t_l *light);
void		convert_color_light(t_l *light, int curr);
void		convert_color_object(t_list *objs, int curr);
void		select_light(int key, t_info *info);
void		move_light(int key, t_info *info);
void		light_selector(void);
void		obj_selector(void);
void		move_objs(int key, t_info *info);
void		key_hook_obj(t_window *win, t_info *info);
void		key_hook_object_off(t_window *win, t_info *info, t_list *obj);
void		select_obj(int key, t_info *info);
void		move_object_rotation(int key, t_info *info);
void		print_turn_off(char *input);
void		rotation_objs(t_info *rotate, t_c cam);
void		init_image(t_window *win, t_texture *texture, char *file, \
	t_texture_type type);
t_vec4		sample_point(t_texture *texture, const t_vec2 uv, int is_raw);
t_vec3		sample_linear(t_texture *texture, const t_vec2 uv, int is_raw);
t_vec3		get_texture_image_color(t_texture *texture, const t_vec2 uv);
t_vec3		sample_normal_map(t_texture *texture_normal, const t_vec2 uv, \
	t_hit *hit, t_vec3 tangent);

#endif
