/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:01:30 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 19:56:57 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_window(t_strct *strct)
{
	strct->mvars.img.img = mlx_new_image(strct->mvars.mlx, strct->scene.width,
			strct->scene.height);
	strct->mvars.img.addr = mlx_get_data_addr(strct->mvars.img.img,
			&strct->mvars.img.bits_per_pixel,
			&strct->mvars.img.line_length, &strct->mvars.img.endian);
}

static int	ft_init_for_raycast(t_strct *strct)
{
	strct->plr.x = (strct->plr.x * strct->map.bound_x) + strct->map.bound_x / 2;
	strct->plr.y = (strct->plr.y * strct->map.bound_y) + strct->map.bound_y / 2;
	strct->plr.shift = strct->plr.fov / strct->scene.width;
	strct->plr.ray_dists = (double *)malloc(
			sizeof(double) * strct->scene.width);
	if (!strct->plr.ray_dists)
	{
		strct->err_num = MALLOC_ERR;
		return (0);
	}
	return (1);
}

static int	ft_init_view(t_strct *strct)
{
	if (strct->map.bound_x == 0 || strct->map.bound_y == 0)
	{
		strct->err_num = ERR_LITTLE_RESOL;
		return (0);
	}
	strct->tex.floor.rgb.rgb_int = ft_conv_rgb_to_hex(strct->tex.floor.rgb.r,
			strct->tex.floor.rgb.g, strct->tex.floor.rgb.b);
	strct->tex.ceil.rgb.rgb_int = ft_conv_rgb_to_hex(strct->tex.ceil.rgb.r,
			strct->tex.ceil.rgb.g, strct->tex.ceil.rgb.b);
	if (strct->plr.nswe == 'S')
		strct->plr.pov = M_PI / 2;
	else if (strct->plr.nswe == 'N')
		strct->plr.pov = 3 * M_PI / 2;
	else if (strct->plr.nswe == 'W')
		strct->plr.pov = M_PI;
	else if (strct->plr.nswe == 'E')
		strct->plr.pov = 0;
	strct->plr.fov = M_PI / 3;
	strct->plr.st_v = strct->plr.pov - strct->plr.fov / 2;
	strct->plr.end_v = strct->plr.pov + strct->plr.fov / 2;
	strct->plr.step = ft_tern_d((strct->map.bound_x > strct->map.bound_y),
			0.15 * strct->map.bound_x, 0.15 * strct->map.bound_y);
	if (!ft_init_for_raycast(strct))
		return (0);
	return (1);
}

int	ft_draw_cub(int argc, t_strct *strct)
{
	if (!ft_init_view(strct))
		return (0);
	if (!ft_init_dir_spr(strct))
		return (0);
	ft_init_window(strct);
	if (argc == 3)
	{
		if (!ft_screen_save(strct))
			return (0);
	}
	else
	{
		strct->mvars.win = mlx_new_window(strct->mvars.mlx, strct->scene.width,
				strct->scene.height, "cub3D");
		ft_draw_card(strct);
		mlx_do_key_autorepeatoff(strct->mvars.mlx);
		mlx_hook(strct->mvars.win, 2, 1L << 0, key_hook, strct);
		mlx_hook(strct->mvars.win, 3, 1L << 1, key_release, strct);
		mlx_hook(strct->mvars.win, 17, 0L, red_cross_hook, strct);
		mlx_loop_hook(strct->mvars.mlx, ft_draw_card, strct);
		mlx_loop(strct->mvars.mlx);
	}
	return (1);
}
