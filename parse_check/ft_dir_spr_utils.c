/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_spr_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:11:23 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 19:56:14 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_parse_dir_spr1(char **spl_line, t_strct *strct)
{
	int		i;

	i = 0;
	while (spl_line && spl_line[i])
		++i;
	if (i != 2)
	{
		strct->err_num = CONFIG_ERR;
		ft_free_splitted(spl_line);
		return (0);
	}
	if (strct->scene.n_north > 0 || strct->config.map_start_flag > 0)
	{
		strct->err_num = CONFIG_ERR;
		ft_free_splitted(spl_line);
		return (0);
	}
	strct->scene.n_north = 1;
	if (!ft_open_path_check(spl_line, &strct->tex.north.fd,
			&strct->tex.north.tex_path, strct))
		return (0);
	return (1);
}

int	ft_check_parse_dir_spr2(char **spl_line, t_strct *strct)
{
	int		i;

	i = 0;
	while (spl_line && spl_line[i])
		++i;
	if (i != 2)
	{
		strct->err_num = CONFIG_ERR;
		ft_free_splitted(spl_line);
		return (0);
	}
	if (strct->scene.n_south > 0 || strct->config.map_start_flag > 0)
	{
		strct->err_num = CONFIG_ERR;
		ft_free_splitted(spl_line);
		return (0);
	}
	strct->scene.n_south = 1;
	if (!ft_open_path_check(spl_line, &strct->tex.south.fd,
			&strct->tex.south.tex_path, strct))
		return (0);
	return (1);
}

int	ft_check_parse_dir_spr3(char **spl_line, t_strct *strct)
{
	int		i;

	i = 0;
	while (spl_line && spl_line[i])
		++i;
	if (i != 2)
	{
		strct->err_num = CONFIG_ERR;
		ft_free_splitted(spl_line);
		return (0);
	}
	if (strct->scene.n_west > 0 || strct->config.map_start_flag > 0)
	{
		strct->err_num = CONFIG_ERR;
		ft_free_splitted(spl_line);
		return (0);
	}
	strct->scene.n_west = 1;
	if (!ft_open_path_check(spl_line, &strct->tex.west.fd,
			&strct->tex.west.tex_path, strct))
		return (0);
	return (1);
}

int	ft_check_parse_dir_spr4(char **spl_line, t_strct *strct)
{
	int		i;

	i = 0;
	while (spl_line && spl_line[i])
		++i;
	if (i != 2)
	{
		strct->err_num = CONFIG_ERR;
		ft_free_splitted(spl_line);
		return (0);
	}
	if (strct->scene.n_east > 0 || strct->config.map_start_flag > 0)
	{
		strct->err_num = CONFIG_ERR;
		ft_free_splitted(spl_line);
		return (0);
	}
	strct->scene.n_east = 1;
	if (!ft_open_path_check(spl_line, &strct->tex.east.fd,
			&strct->tex.east.tex_path, strct))
		return (0);
	return (1);
}

int	ft_check_parse_dir_spr5(char **spl_line, t_strct *strct)
{
	int		i;

	i = 0;
	while (spl_line && spl_line[i])
		++i;
	if (i != 2)
	{
		strct->err_num = CONFIG_ERR;
		ft_free_splitted(spl_line);
		return (0);
	}
	if (strct->scene.n_sprites > 0 || strct->config.map_start_flag > 0)
	{
		strct->err_num = CONFIG_ERR;
		ft_free_splitted(spl_line);
		return (0);
	}
	strct->scene.n_sprites = 1;
	if (!ft_open_path_check(spl_line, &strct->tex.sprite.fd,
			&strct->tex.sprite.tex_path, strct))
		return (0);
	return (1);
}
