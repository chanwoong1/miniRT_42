/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/26 15:11:03 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "error.h"
#include "parse.h"
#include "window.h"
#include "thread.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 2)
		error_exit("Invalid number of arguments. Check it!");
	parse_rt_file(&info, av[1]);
	init_window(&info.win);
	camera_setting(&info);
	binding_events(&info.win);
	start_drawing(&info);
	mlx_loop(info.win.mlx);
	// print_all_info(&info); // info 내용 프린트
	// while
	// int	color = calculate_pixel_color(&info, 300, 300);
	// system("leaks miniRT");
	return (0);
}
