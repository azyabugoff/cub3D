/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:30:36 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 15:42:14 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	key_escape(int key, t_strct *strct)
{
	if (key == 53)
	{
		mlx_destroy_window(strct->mvars.mlx, strct->mvars.win);
		strct->mvars.img.addr = NULL;
		strct->mvars.win = NULL;
		ft_free_strct(strct);
		exit(0);
	}
	return (0);
}

int	red_cross_hook(t_strct *strct)
{
	strct->mvars.img.addr = NULL;
	strct->mvars.win = NULL;
	ft_free_strct(strct);
	exit(0);
}

static int	key_space(int key, t_strct *strct)
{
	if (key == 49)
	{
		if (strct->map.map_txt && strct->map.map_txt[
				(int)(strct->plr.y / strct->map.bound_y)] &&
				strct->map.map_txt[(int)(strct->plr.y / strct->map.bound_y)]
				[(int)(strct->plr.x / strct->map.bound_x)] &&
				strct->map.map_txt[(int)(strct->plr.y / strct->map.bound_y)]
				[(int)(strct->plr.x / strct->map.bound_x)] == '2')
		{
			strct->map.map_txt[(int)(strct->plr.y / strct->map.bound_y)]
			[(int)(strct->plr.x / strct->map.bound_x)] = '0';
			--strct->scene.n_sprs;
		}
	}
	return (0);
}

int	key_hook(int key, t_strct *strct)
{
	key_escape(key, strct);
	key_space(key, strct);
	if (key == 13)
		strct->plr.mvflags += FL_UP;
	if (key == 1)
		strct->plr.mvflags += FL_DOWN;
	if (key == 0)
		strct->plr.mvflags += FL_LEFT;
	if (key == 2)
		strct->plr.mvflags += FL_RIGHT;
	if (key == 123)
		strct->plr.mvflags += FL_ROT_LEFT;
	if (key == 124)
		strct->plr.mvflags += FL_ROT_RIGHT;
	return (0);
}

int	key_release(int key, t_strct *strct)
{
	if (key == 13)
		strct->plr.mvflags -= FL_UP;
	if (key == 1)
		strct->plr.mvflags -= FL_DOWN;
	if (key == 0)
		strct->plr.mvflags -= FL_LEFT;
	if (key == 2)
		strct->plr.mvflags -= FL_RIGHT;
	if (key == 123)
		strct->plr.mvflags -= FL_ROT_LEFT;
	if (key == 124)
		strct->plr.mvflags -= FL_ROT_RIGHT;
	return (0);
}
