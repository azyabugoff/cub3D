/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:19:31 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/09 19:09:08 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_mlx_pixel_put(t_strct *strct, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= strct->scene.width || y < 0 || y >= strct->scene.height)
		return ;
	dst = strct->mvars.img.addr + (y * strct->mvars.img.line_length
			+ x * (strct->mvars.img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
**									2D
**
**void				ft_draw_card_el(t_strct *strct,
**							int color, double x, double y)
**{
**	double		st_x_val;
**	double		st_y_val;
**
**	st_x_val = x;
**	st_y_val = y;
**	while (x < st_x_val + strct->map.bound_x)
**	{
**		y = st_y_val;
**		while (y < st_y_val + strct->map.bound_y)
**		{
**			ft_mlx_pixel_put(&strct->mvars.img, x, y, color);
**			++y;
**		}
**		++x;
**	}
**}
**
**void				ft_draw_card(char **arr, t_strct *strct)
**{
**	int		i;
**	int		j;
**
**	i = 0;
**	j = 0;
**	while (arr[i])
**	{
**		j = 0;
**		while (arr[i][j])
**		{
**			if (arr[i][j] == '1')
**				ft_draw_card_el(strct, 0xFFFFFF, j * strct->map.bound_x,
**												i * strct->map.bound_y);
**			if (arr[i][j] == '2')
**				ft_draw_card_el(strct, 0xFF0000, j * strct->map.bound_x,
**												i * strct->map.bound_y);
**			++j;
**		}
**		++i;
**	}
**	ft_ray_cast(arr, strct);
**	mlx_put_image_to_window(strct->mvars.mlx, strct->mvars.win,
**								strct->mvars.img.img, 0, 0);
**}
**
**											3D
** //2 * tan(M_PI / 6)//
*/

static void	ft_draw_floor_ceil(t_player ray, t_strct *strct)
{
	int		y;

	y = 0;
	while (y <= strct->scene.height / 2)
	{
		if (ray.x < 0 || ray.x >= strct->scene.width)
			continue ;
		ft_mlx_pixel_put(strct, ray.x,
			y, strct->tex.ceil.rgb.rgb_int);
		++y;
	}
	while (y > strct->scene.height / 2 && y < strct->scene.height)
	{
		if (ray.x < 0 || ray.x >= strct->scene.width)
			continue ;
		ft_mlx_pixel_put(strct, ray.x,
			y, strct->tex.floor.rgb.rgb_int);
		++y;
	}
}

void	ft_draw_column(int dist, t_player ray, t_strct *strct)
{
	int			i;
	int			y_pos;

	i = -1;
	y_pos = ft_calc_plr_view(dist, &ray, strct);
	ft_draw_floor_ceil(ray, strct);
	while (++i < ray.wall_height)
	{
		ray.y = y_pos + i;
		if (ray.x >= strct->scene.width || ray.x < 0
			|| ray.y >= strct->scene.height || ray.y < 0)
			continue ;
		ft_set_tex_column(ray, strct);
		ft_set_tex_row(ray, strct, i);
		ft_draw_nswe(ray, strct);
	}
}

int	ft_draw_card(t_strct *strct)
{
	mlx_clear_window(strct->mvars.mlx, strct->mvars.win);
	ft_init_window(strct);
	ft_ray_cast(strct->map.map_txt, strct);
	mlx_put_image_to_window(strct->mvars.mlx, strct->mvars.win,
		strct->mvars.img.img, 0, 0);
	return (1);
}
