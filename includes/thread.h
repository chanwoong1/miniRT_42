/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:14:00 by sunhwang          #+#    #+#             */
/*   Updated: 2023/01/25 14:15:47 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include <unistd.h>
# include <pthread.h>
# include "info.h"
# include "mlx.h"

void	start_drawing(t_info *info);

#endif
