/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:04:48 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/02/02 14:38:49 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "structs.h"
#include "info.h"
#include "thread.h"
#include "rt_math.h"
#include <stdio.h>

void	rotation_controler(char *input)
{
	const char	*orange = "\033[38;5;208m";

	printf("%s╔═══════════════════════════════════════════╗\n", orange);
	printf("║         %s rotation controler         ║\n", input);
	printf("╠═══════╦═══════════════════════════════════╣\n");
	printf("║ PRESS ║              CONTROL              ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   ↑   ║           ROTATE Y AXIS           ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   ↓   ║           ROTATE -Y AXIS          ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   ←   ║           ROTATE -X AXIS          ║\n");
	printf("╠═══════╬═══════════════════════════════════╣\n");
	printf("║   →   ║           ROTATE X AXIS           ║\n");
	printf("╚═══════╩═══════════════════════════════════╝\n");
}

void	key_hook_camera(t_window *win)
{
	if (win->terminal.cam_on == false)
	{
		printf("╔═══════════════════════════════════════════╗\n");
		printf("║             CAMERA : TURN ON              ║\n");
		printf("╚═══════════════════════════════════════════╝\n");
		win->terminal.cam_on = true;
		remote_controler("CAMERA");
		rotation_controler("CAMERA");
		printf("To exit the camera controler, PRESS the 1 key\n");
	}
	else
	{
		print_turn_off("CAMERA");
		win->terminal.cam_on = false;
		terminal_prompt();
	}
}

static void	move_camera_xyz(t_info *info, t_vec3 move)
{
	t_list	*objs;
	t_l		*light;
	int		idx;

	idx = -1;
	objs = info->objs;
	while (++idx < info->num_ele.objs_count)
	{
		((t_obj *)(objs->content))->coor.x += move.x;
		((t_obj *)(objs->content))->coor.y += move.y;
		((t_obj *)(objs->content))->coor.z += move.z;
		objs = objs->next;
	}
	idx = -1;
	light = info->lights;
	while (++idx < info->num_ele.l_count)
	{
		light->coor.x += move.x;
		light->coor.y += move.y;
		light->coor.z += move.z;
		light = light->next;
	}
}

void	move_camera(int key, t_info *info)
{
	if (key == KEY_Q)
		move_camera_xyz(info, vec3(-1, 0, 0));
	else if (key == KEY_W)
		move_camera_xyz(info, vec3(1, 0, 0));
	else if (key == KEY_A)
		move_camera_xyz(info, vec3(0, -1, 0));
	else if (key == KEY_S)
		move_camera_xyz(info, vec3(0, 1, 0));
	else if (key == KEY_Z)
		move_camera_xyz(info, vec3(0, 0, -1));
	else if (key == KEY_X)
		move_camera_xyz(info, vec3(0, 0, 1));
	start_drawing(info);
}
