/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:53:48 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 15:38:00 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
**										2D
**
**void				ft_ray_cast(char **arr, t_strct *strct)
**{
**	t_player	ray;
**	double		shift;
**
**	ray = strct->plr;
**	shift = strct->plr.fov / ((strct->scene.width > strct->scene.height)
**									? strct->scene.width : strct->scene.height);
**	while (ray.st_v < ray.end_v)
**	{
**		ray.x = strct->plr.x;
**		ray.y = strct->plr.y;
**		while (arr[(int)(ray.y / strct->map.bound_y)]
**			[(int)(ray.x / strct->map.bound_x)] != '1' &&
**		arr[(int)(ray.y / strct->map.bound_y)]
**			[(int)(ray.x / strct->map.bound_x)] != '2')
**		{
**			ray.x += cos(ray.st_v);
**			ray.y += sin(ray.st_v);
**			ft_mlx_pixel_put(&strct->mvars.img, ray.x, ray.y, 0xFFFE18);
**		}
**		ray.st_v += shift;
**	}
**}
**
**									3D
*/

static void	ft_find_block(char **arr, t_player *ray, t_strct *strct)
{
	ray->x = strct->plr.x;
	ray->y = strct->plr.y;
	while (arr && arr[(int)(ray->y / strct->map.bound_y)] &&
		arr[(int)(ray->y / strct->map.bound_y)]
		[(int)(ray->x / strct->map.bound_x)] != '1')
	{
		ray->x += 0.4 * cos(ray->st_v);
		ray->y += 0.4 * sin(ray->st_v);
	}
}

void	ft_get_needed_tex_nswe(t_player *ray, t_strct *strct)
{
	if ((int)ray->x % (int)strct->map.bound_x == 0
		&& ft_is_nswe0(strct->map.map_txt[(int)((ray->y) / strct->map.bound_y)]
		[(int)((ray->x - cos(ray->st_v)) / strct->map.bound_x)]))
		ray->tex_ind = 4;
	else if (((int)ray->x + 1) % (int)strct->map.bound_x == 0
		&& ft_is_nswe0(strct->map.map_txt[(int)((ray->y) / strct->map.bound_y)]
		[(int)((ray->x + 2) / strct->map.bound_x)]))
	{
		if ((int)ray->y % (int)strct->map.bound_y == 0
			&& ft_is_nswe0(strct->map.map_txt[(int)((ray->y - sin(ray->st_v))
					/ strct->map.bound_y)][(int)((ray->x)
			/ strct->map.bound_x)]))
			ray->tex_ind = 2;
		else if (((int)ray->y + 1) % (int)strct->map.bound_y == 0
			&& ft_is_nswe0(strct->map.map_txt[(int)((ray->y - sin(ray->st_v))
					/ strct->map.bound_y)][(int)((ray->x)
			/ strct->map.bound_x)]))
			ray->tex_ind = 1;
		else
			ray->tex_ind = 3;
	}
	else if ((int)ray->y % (int)strct->map.bound_y == 0)
		ray->tex_ind = 2;
	else if (((int)ray->y + 1) % (int)strct->map.bound_y == 0)
		ray->tex_ind = 1;
}

int	ft_calc_plr_view(int dist, t_player *ray, t_strct *strct)
{
	int		y_pos;

	ray->wall_height = (strct->map.bound_y * strct->scene.height)
		/ (cos(ray->st_v - strct->plr.pov) * dist);
	y_pos = (strct->scene.height / 2 - ray->wall_height / 2);
	return (y_pos);
}

int	ft_ray_cast(char **arr, t_strct *strct)
{
	t_player	ray;
	int			i;

	i = 0;
	ray = strct->plr;
	while (i < strct->scene.width)
	{
		ft_find_block(arr, &ray, strct);
		ft_get_needed_tex_nswe(&ray, strct);
		ray.dist = sqrt(pow(ray.x - strct->plr.x, 2)
				+ pow(ray.y - strct->plr.y, 2));
		strct->plr.ray_dists[i] = ray.dist;
		ray.x = i;
		ft_draw_column(ray.dist, ray, strct);
		ray.st_v += strct->plr.shift;
		++i;
	}
	ft_draw_sprites(strct);
	ft_move(strct);
	return (1);
}
