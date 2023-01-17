/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:49:00 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/17 18:22:27 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	sec_arr_len(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

float	ft_atof(char *s)
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

/*
* 
*/
int	check_only_num1(char *opt, char *oper)
{
	while (*opt)
	{
		if (*opt >= '0' && *opt <= '9')
			opt++;
		else if (check_oper(*opt, oper) == SUCCESS)
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
