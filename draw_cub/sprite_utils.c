/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:03:58 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 15:47:40 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_alloc_spr_arr(t_strct *strct)
{
	strct->plr.sprs = (t_sprs *)malloc(sizeof(t_sprs)
			* (strct->scene.n_sprs));
	if (!strct->plr.sprs)
	{
		strct->err_num = MALLOC_ERR;
		return (0);
	}
	return (1);
}

static void	ft_init_sprite_vals2(t_strct *strct, t_sprs *sprs)
{
	while (strct->plr.pov > M_PI)
		strct->plr.pov -= 2 * M_PI;
	while (strct->plr.pov < -M_PI)
		strct->plr.pov += 2 * M_PI;
	while (sprs->spr_ang > M_PI)
		sprs->spr_ang -= 2 * M_PI;
	while (sprs->spr_ang < -M_PI)
		sprs->spr_ang += 2 * M_PI;
	while (sprs->spr_ang - strct->plr.pov > M_PI)
		sprs->spr_ang -= 2 * M_PI;
	while (sprs->spr_ang - strct->plr.pov < -M_PI)
		sprs->spr_ang += 2 * M_PI;
}

void	ft_init_sprite_vals(t_strct *strct, t_sprs *sprs)
{
	sprs->spr_ang = atan2(sprs->cent_y
			- strct->plr.y, sprs->cent_x - strct->plr.x);
	ft_init_sprite_vals2(strct, sprs);
	if (strct->scene.width > strct->scene.height)
		sprs->spr_size = (strct->scene.width / 5)
			/ sprs->dist * strct->map.bound_x;
	else
		sprs->spr_size = (strct->scene.height / 5)
			/ sprs->dist * strct->map.bound_y;
	sprs->x_of = (sprs->spr_ang - strct->plr.pov) * strct->scene.width
		/ strct->plr.fov + (strct->scene.width / 2 - sprs->spr_size / 2);
	sprs->y_of = strct->scene.height / 2 - sprs->spr_size / 2;
}

void	ft_sort_sprites(t_strct *strct)
{
	int		i;
	int		j;
	t_sprs	tmp;

	j = 0;
	i = 0;
	while (i < strct->scene.n_sprs)
	{
		j = i;
		while (j < strct->scene.n_sprs)
		{
			if (strct->plr.sprs[i].dist < strct->plr.sprs[j].dist)
			{
				tmp = strct->plr.sprs[i];
				strct->plr.sprs[i] = strct->plr.sprs[j];
				strct->plr.sprs[j] = tmp;
			}
			++j;
		}
		++i;
	}
}
