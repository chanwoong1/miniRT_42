/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:49:00 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/26 20:03:52 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	sec_arr_len(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

float	ft_atod(char *s)
{
	double	ret;
	double	i;
	int		sign;

	ret = 0;
	sign = 1;
	i = 0.1;
	if (*s == 0)
		return (-1);
	if (*s == '-')
	{
		sign = -1;
		(s)++;
	}
	ret = (double)ft_atoi_stream(&s);
	if (*s != 0 && *s == '.')
		(s)++;
	while (*s != 0 && (*s >= '0' && *s <= '9'))
	{
		ret = ret + ((*s - '0') * i);
		i *= 0.1;
		(s)++;
	}
	return ((float)(sign * ret));
}

int	check_only_num1(char *opt, char *oper)
{
	while (*opt)
	{
		if (*opt == '-')
			opt++;
		if ((*opt >= '0' && *opt <= '9') || check_oper(*opt, oper) == SUCCESS)
			opt++;
		else
			error_exit("Wrong argument");
	}
	return (SUCCESS);
}

int	check_only_num(char **opt, char *oper)
{
	int	i;

	i = 0;
	while (opt[i])
	{
		check_only_num1(opt[i], oper);
		i++;
	}
	return (SUCCESS);
}
