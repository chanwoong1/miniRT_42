/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:54:05 by seokchoi          #+#    #+#             */
/*   Updated: 2023/02/02 14:40:52 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "info.h"

int	check_oper(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (SUCCESS);
		i++;
	}
	return (ERR);
}
