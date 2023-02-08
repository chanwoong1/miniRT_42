/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_file_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/31 18:21:09 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "parse.h"
#include "structs.h"
#include "rt_math.h"

void	check_file_name(char *file_name)
{
	int	name_len;

	name_len = ft_strlen(file_name);
	if (name_len < 3 || \
		file_name[name_len - 3] != '.' || \
		file_name[name_len - 2] != 'r' || \
		file_name[name_len - 1] != 't')
		error_exit("Invalid file type");
}

int	check_range(int type, float ret)
{
	if ((type == 255 && (ret >= 0 && ret <= 255)) || \
		(type == -1 && (ret >= -1 && ret <= 1)) || \
		(type == 1 && (ret >= 0 && ret <= 1)) || \
		(type == 180 && (ret >= 0.0 && ret <= 180.0)))
		return (SUCCESS);
	return (ERR);
}

void	edit_info(t_info *info, char *s, t_num_ele *check_count)
{
	char	**options;

	options = ft_split_is_space(s);
	if (!options)
		error_exit("Malloc error");
	if (ft_strncmp(options[0], "#", 2) == 0)
		return (free_double_array((void **)options));
	check_option_count_bonus(options[0], check_count);
	if (sec_arr_len(options) < 3)
		error_exit("Wrong identifier");
	if (ft_strncmp(options[0], "A", 2) == 0)
		get_ambient(info, options);
	else if (ft_strncmp(options[0], "C", 2) == 0)
		get_camera(info, options);
	else if (ft_strncmp(options[0], "L", 2) == 0)
		get_light(info, options);
	else if (ft_strncmp(options[0], "pl", 3) == 0)
		get_obj(info, options, PL);
	else if (ft_strncmp(options[0], "sp", 3) == 0)
		get_obj(info, options, SP);
	else if (ft_strncmp(options[0], "cy", 3) == 0)
		get_obj(info, options, CY);
	else
		error_exit("Wrong identifier");
	free_double_array((void **)options);
}

bool	read_file(t_info *info, int fd, t_num_ele *check_count)
{
	char	*tmp;

	tmp = get_next_line(fd);
	if (!tmp)
	{
		close(fd);
		return (false);
	}
	else if (ft_strncmp(tmp, "\n", 2) == 0)
		return (free(tmp), true);
	edit_info(info, tmp, check_count);
	return (free(tmp), true);
}

void	parse_rt_file(t_info *info, char *file_name)
{
	int			fd;
	t_num_ele	check_count;

	check_file_name(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_exit("File open failed");
	init_info(info);
	while (1)
	{
		if (!read_file(info, fd, &check_count))
			break ;
	}
}
