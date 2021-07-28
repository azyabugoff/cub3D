/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bar_dist_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:56:58 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/09 19:04:45 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	bar_case1(t_strct *strct, t_player ray)
{
	if (!strct->map.map_txt
		|| !strct->map.map_txt[(int)(ray.y / strct->map.bound_y)]
		|| !strct->map.map_txt[(int)(ray.y / strct->map.bound_y)]
		[(int)(ray.x / strct->map.bound_x)]
		|| strct->map.map_txt[(int)(ray.y / strct->map.bound_y)]
		[(int)(ray.x / strct->map.bound_x)] == '1'
		|| strct->map.map_txt[(int)((ray.y + 5) / strct->map.bound_y)]
		[(int)(ray.x / strct->map.bound_x)] == '1'
		|| strct->map.map_txt[(int)((ray.y - 5) / strct->map.bound_y)]
		[(int)(ray.x / strct->map.bound_x)] == '1'
		|| strct->map.map_txt[(int)(ray.y / strct->map.bound_y)]
		[(int)((ray.x + 5) / strct->map.bound_x)] == '1'
		|| strct->map.map_txt[(int)(ray.y / strct->map.bound_y)]
		[(int)((ray.x - 5) / strct->map.bound_x)] == '1')
		return (0);
	return (1);
}

static int	bar_case2(t_strct *strct, t_player ray,
								double shiftx, double shifty)
{
	if (!strct->map.map_txt[(int)((ray.y - 5) / strct->map.bound_y)]
		|| !strct->map.map_txt[(int)((ray.y - 5) / strct->map.bound_y)]
		[(int)((ray.x - 5) / strct->map.bound_x)]
		|| strct->map.map_txt[(int)((ray.y - 5) / strct->map.bound_y)]
		[(int)((ray.x - 5) / strct->map.bound_x)] == '1'
		|| !strct->map.map_txt[(int)((ray.y + 5) / strct->map.bound_y)]
		|| !strct->map.map_txt[(int)((ray.y + 5) / strct->map.bound_y)]
		[(int)((ray.x + 5) / strct->map.bound_x)]
		|| strct->map.map_txt[(int)((ray.y + 5) / strct->map.bound_y)]
		[(int)((ray.x + 5) / strct->map.bound_x)] == '1'
		|| strct->map.map_txt[(int)((ray.y + shifty) / strct->map.bound_y)]
		[(int)(ray.x / strct->map.bound_x)] == '1'
		|| strct->map.map_txt[(int)(ray.y / strct->map.bound_y)]
		[(int)((ray.x + shiftx) / strct->map.bound_x)] == '1')
		return (0);
	return (1);
}

int	ft_is_bar_dist(t_strct *strct, t_player ray, double shiftx,
									double shifty)
{
	if (!bar_case1(strct, ray) || !bar_case2(strct, ray, shiftx, shifty))
		return (0);
	return (1);
}
