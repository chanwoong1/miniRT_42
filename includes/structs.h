/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwo <chanwo@student.42seoul.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:52:37 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/25 14:06:19 by chanwo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>
# include "libft.h"

typedef struct s_vec2	t_vec2;
typedef struct s_vec2	t_point2;
typedef struct s_vec2	t_color2;

typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_point3;
typedef struct s_vec3	t_color3;

typedef struct s_vec4	t_vec4;
typedef struct s_vec4	t_point4;
typedef struct s_vec4	t_color4;

struct s_vec2
{
	double	x;
	double	y;
};

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

struct s_vec4
{
	double	x1;
	double	x2;
	double	x3;
	double	x4;
};

typedef struct s_ray
{
	t_vec3	orig;
	t_vec3	normal;
}	t_ray;

typedef struct s_hit
{
	double	d;
	t_vec3	point;
	t_vec3	normal;
}	t_hit;

typedef struct s_cy_settings
{
	t_vec3			u;
	t_vec3			o;
	t_vec3			delta_p;
	double			a;
	double			half_b;
	double			c;
	double			r;
	double			discriminant;
	double			sqrtd;
	double			root;
	double			hit_height;
}	t_cy_settings;

/*
* Ambient lightning:
* identifier: A
* ambient lighting ratio in range [0.0,1.0]: 0.2
* R,G,B colors in range [0-255]: 255, 255, 255
*/
typedef struct s_a
{
	double			amb_light_ratio;
	struct s_vec3	colors;
}	t_a;

/*
* Camera:
* identifier: C
* x,y,z coordinates of the view point: 0.0,0.0,20.6
* 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
* FOV : Horizontal field of view in degrees in range [0,180]
* length : Distance from camera to monitor
*/
typedef struct s_c
{
	struct s_vec3	coor;
	struct s_vec3	normal;
	int				fov;
	double			length;
}	t_c;

/*
* Light:
* identifier: L
* x,y,z coordinates of the light point: 0.0,0.0,20.6
* the light brightness ratio in range [0.0,1.0]: 0.6
* (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255
*/
typedef struct s_l
{
	t_vec3		coor;
	double		light_brightness_ratio;
	/* unsued in mand part */
	t_vec3		colors;
	struct s_l	*next;
	struct s_l	*prev;
}	t_l;

/*
* PL : Plane
* SP : Sphere
* CY : Cylinder
*/
typedef enum e_type
{
	NO_OBJS,
	PL,
	SP,
	CY,
}	t_type;

/*
* Objs:
* identifier : objs type
* x,y,z coordinates: 50.0,0.0,20.6
* 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
* the cylinder diameter: 14.2
* the cylinder height: 21.42
* R,G,B colors in range [0,255]: 10, 0, 255
*/
typedef struct s_obj
{
	enum e_type		type;
	t_vec3			coor;
	t_vec3			normal;
	double			diameter;
	double			cy_hei;
	t_vec3			colors;
	struct s_obj	*next;
	struct s_obj	*prev;
}	t_obj;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_terminal
{
	bool	prompt;
	bool	cam_on;
	bool	light_on;
	bool	light_select;
	int		curr_light;
}	t_terminal;

typedef struct s_window
{
	void		*mlx;
	void		*mlx_win;
	int			width;
	int			height;
	t_terminal	terminal;
}	t_window;

typedef struct s_num_ele
{
	int	a_count;
	int	c_count;
	int	l_count;
	int	cy_count;
	int	sp_count;
	int	pl_count;
}	t_num_ele;

/*
* info
*/
typedef struct s_info
{
	t_a				amb;
	t_c				cam;
	t_l				*lights;
	t_list			*objs;
	t_window		win;

	// tmp
	t_hit			*hit;
	t_vec3			color;
	t_vec3			phong_color;
	double			diff;
	double			specular;
	t_num_ele		num_ele;

	t_ray			ray;
}	t_info;

/*
* check_flag
* explaination : check number of flags in '.rt file'
*/

typedef struct s_drawer
{
	int			i;
	int			width;
	int			height;
	int			size;
	pthread_t	thread;
	t_data		data;
	t_info		*info;
}	t_drawer;

#endif
