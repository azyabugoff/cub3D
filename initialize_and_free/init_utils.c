/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:47:01 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 16:51:21 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init2(t_strct *strct)
{
	strct->scene.n_sprs = 0;
	strct->plr.sprs = NULL;
	strct->plr.ray_dists = NULL;
	strct->plr.spr_ind = -1;
	strct->plr.mvflags = 0x00000000;
	strct->map.bound_x = 64;
	strct->map.bound_y = 64;
}

void	ft_init1(t_strct *strct)
{
	strct->tex.north.tex_path = NULL;
	strct->tex.north.img = NULL;
	strct->tex.north.addr = NULL;
	strct->tex.south.tex_path = NULL;
	strct->tex.south.img = NULL;
	strct->tex.south.addr = NULL;
	strct->tex.west.tex_path = NULL;
	strct->tex.west.img = NULL;
	strct->tex.west.addr = NULL;
	strct->tex.east.tex_path = NULL;
	strct->tex.east.img = NULL;
	strct->tex.east.addr = NULL;
	strct->tex.sprite.tex_path = NULL;
	strct->tex.sprite.img = NULL;
	strct->tex.sprite.addr = NULL;
	strct->tex.north.tex_coord.x = 0;
	strct->tex.north.tex_coord.y = 0;
	strct->tex.south.tex_coord.x = 0;
	strct->tex.south.tex_coord.y = 0;
	strct->tex.west.tex_coord.x = 0;
	strct->tex.west.tex_coord.y = 0;
	strct->tex.east.tex_coord.x = 0;
	strct->tex.east.tex_coord.y = 0;
	ft_init2(strct);
}

void	ft_free_strct2(t_strct *strct)
{
	if (strct->tex.north.img)
		free(strct->tex.north.img);
	if (strct->tex.south.img)
		free(strct->tex.south.img);
	if (strct->tex.west.img)
		free(strct->tex.west.img);
	if (strct->tex.east.img)
		free(strct->tex.east.img);
	if (strct->tex.sprite.img)
		free(strct->tex.sprite.img);
	if (strct->plr.sprs)
		free(strct->plr.sprs);
	if (strct->plr.ray_dists)
		free(strct->plr.ray_dists);
}
