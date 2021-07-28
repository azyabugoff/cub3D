/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:00:06 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 15:50:15 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_is_nswe0(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '2')
		return (1);
	return (0);
}

void	ft_mirror_val(double *val, int mirror, t_nswe_spr nswe)
{
	int		tmp;

	tmp = 0;
	if (mirror == *val)
		return ;
	else if (*val == nswe.width - 1)
		*val = 0;
	else if (*val == 0)
		*val = nswe.width - 1;
	else if (mirror < *val)
	{
		tmp = *val - mirror;
		*val = mirror - tmp;
	}
	else if (mirror > *val)
	{
		tmp = mirror - *val;
		*val = mirror + tmp;
	}
}

void	ft_set_tex_column(t_player ray, t_strct *strct)
{
	if (ray.tex_ind == 1)
		strct->tex.north.tex_coord.x = (((int)(strct->plr.x + ray.dist
						* cos(ray.st_v)) % (int)strct->map.bound_x)
				/ strct->map.bound_x) * strct->tex.north.width;
	else if (ray.tex_ind == 2)
	{
		strct->tex.south.tex_coord.x = (((int)(strct->plr.x + ray.dist
						* cos(ray.st_v)) % (int)strct->map.bound_x)
				/ strct->map.bound_x) * strct->tex.south.width;
		ft_mirror_val(&strct->tex.south.tex_coord.x,
			(strct->tex.south.width + 1) / 2, strct->tex.south);
	}
	else if (ray.tex_ind == 3)
	{
		strct->tex.west.tex_coord.x = (((int)(strct->plr.y + ray.dist
						* sin(ray.st_v)) % (int)strct->map.bound_y)
				/ strct->map.bound_y) * strct->tex.west.width;
		ft_mirror_val(&strct->tex.west.tex_coord.x,
			(strct->tex.west.width + 1) / 2, strct->tex.west);
	}
	else if (ray.tex_ind == 4)
		strct->tex.east.tex_coord.x = (((int)(strct->plr.y + ray.dist
						* sin(ray.st_v)) % (int)strct->map.bound_y)
				/ strct->map.bound_y) * strct->tex.east.width;
}

void	ft_set_tex_row(t_player ray, t_strct *strct, int i)
{
	if (ray.tex_ind == 1)
		strct->tex.north.tex_coord.y = (
				strct->map.bound_x / ray.wall_height) * i;
	else if (ray.tex_ind == 2)
		strct->tex.south.tex_coord.y = (
				strct->map.bound_x / ray.wall_height) * i;
	else if (ray.tex_ind == 3)
		strct->tex.west.tex_coord.y = (
				strct->map.bound_x / ray.wall_height) * i;
	else if (ray.tex_ind == 4)
		strct->tex.east.tex_coord.y = (
				strct->map.bound_x / ray.wall_height) * i;
}
