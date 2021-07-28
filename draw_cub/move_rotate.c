/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:56:54 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 15:43:20 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_rot_left(t_strct *strct)
{
	strct->plr.st_v -= M_PI / 36;
	strct->plr.end_v -= M_PI / 36;
	strct->plr.pov = (strct->plr.end_v + strct->plr.st_v) / 2;
}

void	ft_rot_right(t_strct *strct)
{
	strct->plr.st_v += M_PI / 36;
	strct->plr.end_v += M_PI / 36;
	strct->plr.pov = (strct->plr.end_v + strct->plr.st_v) / 2;
}
