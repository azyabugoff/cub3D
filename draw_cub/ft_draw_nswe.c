/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_nswe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:03:16 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 15:29:10 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_draw_north_tex(t_player ray, t_strct *strct)
{
	if (strct->tex.north.tex_coord.x < strct->tex.north.width
		&& strct->tex.north.tex_coord.x >= 0)
	{
		strct->tex.north.color = strct->tex.north.addr[(int)(
				((int)strct->tex.north.tex_coord.y * strct->tex.north.width)
				+ strct->tex.north.tex_coord.x)];
		ft_mlx_pixel_put(strct, ray.x,
			ray.y, strct->tex.north.color);
	}
}

static void	ft_draw_south_tex(t_player ray, t_strct *strct)
{
	if (strct->tex.south.tex_coord.x < strct->tex.south.width
		&& strct->tex.south.tex_coord.x >= 0)
	{
		strct->tex.south.color = strct->tex.south.addr[(int)(
				((int)strct->tex.south.tex_coord.y * strct->tex.south.width)
				+ strct->tex.south.tex_coord.x)];
		ft_mlx_pixel_put(strct, ray.x,
			ray.y, strct->tex.south.color);
	}
}

static void	ft_draw_west_tex(t_player ray, t_strct *strct)
{
	if (strct->tex.west.tex_coord.x < strct->tex.west.width
		&& strct->tex.west.tex_coord.x >= 0)
	{
		strct->tex.west.color = strct->tex.west.addr[(int)(
				((int)strct->tex.west.tex_coord.y * strct->tex.west.width)
				+ strct->tex.west.tex_coord.x)];
		ft_mlx_pixel_put(strct, ray.x,
			ray.y, strct->tex.west.color);
	}
}

static void	ft_draw_east_tex(t_player ray, t_strct *strct)
{
	if (strct->tex.east.tex_coord.x < strct->tex.east.width
		&& strct->tex.east.tex_coord.x >= 0)
	{
		strct->tex.east.color = strct->tex.east.addr[(int)(
				((int)strct->tex.east.tex_coord.y * strct->tex.east.width)
				+ strct->tex.east.tex_coord.x)];
		ft_mlx_pixel_put(strct, ray.x,
			ray.y, strct->tex.east.color);
	}
}

void	ft_draw_nswe(t_player ray, t_strct *strct)
{
	if (ray.tex_ind == 1)
		ft_draw_north_tex(ray, strct);
	else if (ray.tex_ind == 2)
		ft_draw_south_tex(ray, strct);
	else if (ray.tex_ind == 3)
		ft_draw_west_tex(ray, strct);
	else if (ray.tex_ind == 4)
		ft_draw_east_tex(ray, strct);
}
