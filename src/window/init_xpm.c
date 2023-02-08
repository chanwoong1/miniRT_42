/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:12:52 by sunhwang          #+#    #+#             */
/*   Updated: 2023/02/06 18:46:36 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "window.h"
#include "structs.h"
#include "error.h"

void	init_image(t_window *w, t_texture *texture, char *f, t_texture_type t)
{
	char	*file_path;
	t_data	*data;

	if (ft_strncmp(f, "checker", 8) == 0)
	{
		texture->type = CHECK;
		return ;
	}
	else if (t == DIFFUSE)
		texture->type = DIFFUSE;
	else if (t == NORMAL)
		texture->type = NORMAL;
	file_path = ft_strjoin("./src/images/", f);
	data = &texture->data;
	data->img = mlx_xpm_file_to_image(w->mlx, file_path, &texture->width, \
		&texture->height);
	if (!data->img)
		error_exit("Invaild texture file");
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
		&data->line_length, &data->endian);
	free(file_path);
}
