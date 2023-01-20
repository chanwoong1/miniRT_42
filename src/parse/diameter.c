/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diameter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:50:22 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/20 16:38:50 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_diameter(t_objs *obj, float dia)
{
	if (dia <= 0)
		error_exit("Wrong diameter range");
	obj->diameter = dia;
}
