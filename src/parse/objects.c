/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:52:00 by seokchoi          #+#    #+#             */
/*   Updated: 2023/02/06 21:22:42 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "info.h"
#include "parse.h"

static void	check_obj(t_info *info, t_obj *obj, char **opt, t_type type)
{
	obj->type = type;
	if (type == PL)
		set_pl(info, obj, opt);
	if (type == SP)
		set_sp(info, obj, opt);
	if (type == CY)
		set_cy(info, obj, opt);
	if (type == CN)
		set_cn(info, obj, opt);
}

void	get_obj(t_info *info, char **opt, char *t)
{
	t_obj	*obj;
	t_list	*new;
	t_type	type;

	type = NO_OBJS;
	if (ft_strncmp(t, "pl", 3) == 0)
		type = PL;
	else if (ft_strncmp(t, "sp", 3) == 0)
		type = SP;
	else if (ft_strncmp(t, "cy", 3) == 0)
		type = CY;
	else if (ft_strncmp(t, "cn", 3) == 0)
		type = CN;
	obj = ft_malloc(sizeof(t_obj));
	check_obj(info, obj, opt, type);
	new = ft_lstnew(obj);
	ft_lstadd_back(&(info->objs), new);
}
