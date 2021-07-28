/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parse_floor_ceil.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:02:29 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 19:56:16 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_check_rgb(char **spl_rgb, char **spl_line,
									t_strct *strct, t_rgb *rgb)
{
	int		i;

	i = 0;
	while (spl_rgb && spl_rgb[i])
		++i;
	if (i != 3)
	{
		ft_free_splitted(spl_rgb);
		ft_free_splitted(spl_line);
		strct->err_num = CONFIG_ERR;
		return (0);
	}
	if (!ft_check_number(spl_rgb[0]) || !ft_check_number(spl_rgb[1])
		|| !ft_check_number(spl_rgb[2]) || !ft_rgb_in_range(ft_atoi(spl_rgb[0]),
			ft_atoi(spl_rgb[1]), ft_atoi(spl_rgb[2])))
	{
		ft_free_splitted(spl_rgb);
		ft_free_splitted(spl_line);
		strct->err_num = CONFIG_ERR;
		return (0);
	}
	rgb->r = ft_atoi(spl_rgb[0]);
	rgb->g = ft_atoi(spl_rgb[1]);
	rgb->b = ft_atoi(spl_rgb[2]);
	return (1);
}

static int	ft_check_parse_floor_ceil1(char **spl_line, t_strct *strct)
{
	int		i;
	char	**spl_rgb;

	i = 0;
	while (spl_line && spl_line[i])
		++i;
	if (i != 2)
		return (ft_threrr_fl_ceil(spl_line, strct));
	if (strct->scene.n_floors > 0 || strct->config.map_start_flag > 0)
		return (ft_threrr_fl_ceil(spl_line, strct));
	strct->scene.n_floors = 1;
	spl_rgb = ft_split(spl_line[1], ',');
	if (!spl_rgb)
	{
		ft_free_splitted(spl_line);
		strct->err_num = MALLOC_ERR;
		return (0);
	}
	if (!ft_check_rgb(spl_rgb, spl_line, strct, &strct->tex.floor.rgb))
		return (0);
	ft_free_splitted(spl_rgb);
	return (1);
}

static int	ft_check_parse_floor_ceil2(char **spl_line, t_strct *strct)
{
	int		i;
	char	**spl_rgb;

	i = 0;
	while (spl_line && spl_line[i])
		++i;
	if (i != 2)
		return (ft_threrr_fl_ceil(spl_line, strct));
	if (strct->scene.n_ceils > 0 || strct->config.map_start_flag > 0)
		return (ft_threrr_fl_ceil(spl_line, strct));
	strct->scene.n_ceils = 1;
	spl_rgb = ft_split(spl_line[1], ',');
	if (!spl_rgb)
	{
		ft_free_splitted(spl_line);
		strct->err_num = MALLOC_ERR;
		return (0);
	}
	if (!ft_check_rgb(spl_rgb, spl_line, strct, &strct->tex.ceil.rgb))
		return (0);
	ft_free_splitted(spl_rgb);
	return (1);
}

static int	ft_check_parse_floor_ceil0(char **spl_line, t_strct *strct)
{
	int		len;

	len = 0;
	if (spl_line && spl_line[0])
	{
		len = ft_strlen(spl_line[0]);
		if (ft_strncmp(spl_line[0], "F", (len > 1) ? len : 1) == 0)
			if (!ft_check_parse_floor_ceil1(spl_line, strct))
				return (0);
		if (ft_strncmp(spl_line[0], "C", (len > 1) ? len : 1) == 0)
			if (!ft_check_parse_floor_ceil2(spl_line, strct))
				return (0);
	}
	return (1);
}

int	ft_check_parse_floor_ceil(char *line, t_strct *strct)
{
	char	**spl_line;

	spl_line = ft_split(line, ' ');
	if (!spl_line)
	{
		strct->err_num = MALLOC_ERR;
		return (0);
	}
	if (!ft_check_parse_floor_ceil0(spl_line, strct))
		return (0);
	ft_free_splitted(spl_line);
	return (1);
}
