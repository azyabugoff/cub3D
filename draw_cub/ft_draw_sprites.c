/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:03:38 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 15:32:00 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_draw_pix(t_strct *strct, t_sprs *sprs, int i, int j)
{
	strct->tex.sprite.color = strct->tex.sprite.addr[(int)(
			strct->tex.sprite.height * (j * strct->tex.sprite.height
				/ sprs->spr_size)
			+ (i * strct->tex.sprite.width / sprs->spr_size))];
	if (strct->tex.sprite.color && strct->tex.sprite.color != -16777216
		&& strct->tex.sprite.color & 0xFFFFFFFF)
		ft_mlx_pixel_put(strct, sprs->x_of + i,
			sprs->y_of + j, strct->tex.sprite.color);
}

static void	ft_draw_spr_cicles(t_strct *strct, t_sprs *sprs)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < sprs->spr_size)
	{
		if (sprs->x_of + i < 0 || sprs->x_of + i >= strct->scene.width)
			continue ;
		if (strct->plr.ray_dists[(int)(sprs->x_of + i)] < sprs->dist)
			continue ;
		j = -1;
		while (++j < sprs->spr_size)
		{
			if (sprs->y_of + j < 0 || sprs->y_of + j >= strct->scene.height)
				continue ;
			ft_draw_pix(strct, sprs, i, j);
		}
	}
}

void	ft_draw_sprites(t_strct *strct)
{
	int		i;

	i = 0;
	while (i < strct->scene.n_sprs)
	{
		strct->plr.sprs[i].vec_x = strct->plr.sprs[i].cent_x - strct->plr.x;
		strct->plr.sprs[i].vec_y = strct->plr.sprs[i].cent_y - strct->plr.y;
		strct->plr.sprs[i].dist = sqrt(pow(strct->plr.sprs[i].vec_x, 2)
				+ pow(strct->plr.sprs[i].vec_y, 2));
		++i;
	}
	i = 0;
	ft_sort_sprites(strct);
	while (i < strct->scene.n_sprs)
	{
		ft_init_sprite_vals(strct, &strct->plr.sprs[i]);
		ft_draw_spr_cicles(strct, &strct->plr.sprs[i]);
		++i;
	}
}
