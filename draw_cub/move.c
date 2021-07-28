/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:30:36 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 15:44:06 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_w_move(t_strct *strct)
{
	t_player	ray;

	ray = strct->plr;
	ray.x += cos(strct->plr.pov) * strct->plr.step;
	ray.y += sin(strct->plr.pov) * strct->plr.step;
	if (!ft_is_bar_dist(strct, ray, -cos(strct->plr.pov) * strct->plr.step,
			-sin(strct->plr.pov) * strct->plr.step))
		return ;
	strct->plr.x += cos(strct->plr.pov) * strct->plr.step;
	strct->plr.y += sin(strct->plr.pov) * strct->plr.step;
}

static void	ft_a_move(t_strct *strct)
{
	t_player	ray;

	ray = strct->plr;
	ray.x += cos(strct->plr.pov - (M_PI / 2)) * strct->plr.step;
	ray.y += sin(strct->plr.pov - (M_PI / 2)) * strct->plr.step;
	if (!ft_is_bar_dist(strct, ray, -cos(strct->plr.pov - (M_PI / 2))
			* strct->plr.step, -sin(strct->plr.pov - (M_PI / 2))
			* strct->plr.step))
		return ;
	strct->plr.x += cos(strct->plr.pov - (M_PI / 2)) * strct->plr.step;
	strct->plr.y += sin(strct->plr.pov - (M_PI / 2)) * strct->plr.step;
}

static void	ft_s_move(t_strct *strct)
{
	t_player	ray;

	ray = strct->plr;
	ray.x -= cos(strct->plr.pov) * strct->plr.step;
	ray.y -= sin(strct->plr.pov) * strct->plr.step;
	if (!ft_is_bar_dist(strct, ray, cos(strct->plr.pov)
			* strct->plr.step, sin(strct->plr.pov)
			* strct->plr.step))
		return ;
	strct->plr.x -= cos(strct->plr.pov) * strct->plr.step;
	strct->plr.y -= sin(strct->plr.pov) * strct->plr.step;
}

static void	ft_d_move(t_strct *strct)
{
	t_player	ray;

	ray = strct->plr;
	ray.x += cos(strct->plr.pov + (M_PI / 2)) * strct->plr.step;
	ray.y += sin(strct->plr.pov + (M_PI / 2)) * strct->plr.step;
	if (!ft_is_bar_dist(strct, ray, -cos(strct->plr.pov + (M_PI / 2))
			* strct->plr.step, -sin(strct->plr.pov + (M_PI / 2))
			* strct->plr.step))
		return ;
	strct->plr.x += cos(strct->plr.pov + (M_PI / 2)) * strct->plr.step;
	strct->plr.y += sin(strct->plr.pov + (M_PI / 2)) * strct->plr.step;
}

int	ft_move(t_strct *strct)
{
	if (strct->plr.mvflags & FL_UP)
		ft_w_move(strct);
	if (strct->plr.mvflags & FL_LEFT)
		ft_a_move(strct);
	if (strct->plr.mvflags & FL_DOWN)
		ft_s_move(strct);
	if (strct->plr.mvflags & FL_RIGHT)
		ft_d_move(strct);
	if (strct->plr.mvflags & FL_ROT_LEFT)
		ft_rot_left(strct);
	if (strct->plr.mvflags & FL_ROT_RIGHT)
		ft_rot_right(strct);
	return (0);
}
