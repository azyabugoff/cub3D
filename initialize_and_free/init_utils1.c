/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:36:19 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 16:56:58 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_init_south(t_strct *strct)
{
	strct->tex.south.img = mlx_xpm_file_to_image(strct->mvars.mlx,
			strct->tex.south.tex_path, &strct->tex.south.width,
			&strct->tex.south.height);
	if (!strct->tex.south.img)
	{
		strct->err_num = OPEN_FILE_ERR;
		return (0);
	}
	strct->tex.south.addr = (unsigned int *)mlx_get_data_addr(
			strct->tex.south.img, &strct->tex.south.bits_per_pixel,
			&strct->tex.south.line_length, &strct->tex.south.endian);
	if (!strct->tex.south.addr)
	{
		strct->err_num = ADDR_DATA_ERR;
		return (0);
	}
	return (1);
}

static int	ft_init_west(t_strct *strct)
{
	strct->tex.west.img = mlx_xpm_file_to_image(strct->mvars.mlx,
			strct->tex.west.tex_path, &strct->tex.west.width,
			&strct->tex.west.height);
	if (!strct->tex.west.img)
	{
		strct->err_num = OPEN_FILE_ERR;
		return (0);
	}
	strct->tex.west.addr = (unsigned int *)mlx_get_data_addr(
			strct->tex.west.img, &strct->tex.west.bits_per_pixel,
			&strct->tex.west.line_length, &strct->tex.west.endian);
	if (!strct->tex.west.addr)
	{
		strct->err_num = ADDR_DATA_ERR;
		return (0);
	}
	return (1);
}

static int	ft_init_east(t_strct *strct)
{
	strct->tex.east.img = mlx_xpm_file_to_image(strct->mvars.mlx,
			strct->tex.east.tex_path, &strct->tex.east.width,
			&strct->tex.east.height);
	if (!strct->tex.east.img)
	{
		strct->err_num = OPEN_FILE_ERR;
		return (0);
	}
	strct->tex.east.addr = (unsigned int *)mlx_get_data_addr(
			strct->tex.east.img, &strct->tex.east.bits_per_pixel,
			&strct->tex.east.line_length, &strct->tex.east.endian);
	if (!strct->tex.east.addr)
	{
		strct->err_num = ADDR_DATA_ERR;
		return (0);
	}
	return (1);
}

static int	ft_init_sprite(t_strct *strct)
{
	strct->tex.sprite.img = mlx_xpm_file_to_image(strct->mvars.mlx,
			strct->tex.sprite.tex_path, &strct->tex.sprite.width,
			&strct->tex.sprite.height);
	if (!strct->tex.sprite.img)
	{
		strct->err_num = OPEN_FILE_ERR;
		return (0);
	}
	strct->tex.sprite.addr = (unsigned int *)mlx_get_data_addr(
			strct->tex.sprite.img, &strct->tex.sprite.bits_per_pixel,
			&strct->tex.sprite.line_length, &strct->tex.sprite.endian);
	if (!strct->tex.sprite.addr)
	{
		strct->err_num = ADDR_DATA_ERR;
		return (0);
	}
	return (1);
}

int	ft_init_dir_spr(t_strct *strct)
{
	strct->tex.north.img = mlx_xpm_file_to_image(strct->mvars.mlx,
			strct->tex.north.tex_path, &strct->tex.north.width,
			&strct->tex.north.height);
	if (!strct->tex.north.img)
	{
		strct->err_num = OPEN_FILE_ERR;
		return (0);
	}
	strct->tex.north.addr = (unsigned int *)mlx_get_data_addr(
			strct->tex.north.img, &strct->tex.north.bits_per_pixel,
			&strct->tex.north.line_length, &strct->tex.north.endian);
	if (!strct->tex.north.addr)
	{
		strct->err_num = ADDR_DATA_ERR;
		return (0);
	}
	if (!ft_init_south(strct))
		return (0);
	if (!ft_init_west(strct))
		return (0);
	if (!ft_init_east(strct))
		return (0);
	if (!ft_init_sprite(strct))
		return (0);
	return (1);
}
