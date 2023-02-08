/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:12:52 by sunhwang          #+#    #+#             */
/*   Updated: 2023/02/02 18:54:25 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "rt_math.h"

static int	get_offset(t_data *data, int x, int y)
{
	const int	line_length = data->line_length;
	const int	bits_per_pixel = data->bits_per_pixel;

	return (y * line_length + x * (bits_per_pixel / 8));
}

char	*get_pixel(t_data *data, int x, int y)
{
	return (data->addr + get_offset(data, x, y));
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = get_pixel(data, x, y);
	*(unsigned int *)dst = color;
}

void	convert_color_light(t_l *light, int curr)
{
	int	idx;

	idx = 0;
	while (idx < curr)
	{
		light = light->next;
		idx++;
	}
	light->colors.x = 255.0 - light->colors.x;
	light->colors.y = 255.0 - light->colors.y;
	light->colors.z = 255.0 - light->colors.z;
}

void	convert_color_object(t_list *objs, int curr)
{
	int		idx;
	t_obj	*obj;

	idx = 0;
	while (idx < curr)
	{
		objs = objs->next;
		idx++;
	}
	obj = (t_obj *)objs->content;
	obj->colors.x = 255.0 - obj->colors.x;
	obj->colors.y = 255.0 - obj->colors.y;
	obj->colors.z = 255.0 - obj->colors.z;
}
