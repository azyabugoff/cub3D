/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_free_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:47:01 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 16:50:54 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_scene(t_strct *strct)
{
	strct->mvars.mlx = mlx_init();
	mlx_get_screen_size(strct->mvars.mlx, &(strct->scene.width),
		&(strct->scene.height));
	strct->err_num = NO_ERR;
	strct->scene.n_resols = 0;
	strct->scene.n_north = 0;
	strct->scene.n_south = 0;
	strct->scene.n_west = 0;
	strct->scene.n_east = 0;
	strct->scene.n_sprites = 0;
	strct->scene.n_floors = 0;
	strct->scene.n_ceils = 0;
	strct->scene.flag_found_map = 0;
	strct->config.map_start_flag = 0;
	strct->config.pers_found_flag = 0;
	strct->config.map_end_flag = 0;
	strct->map.n_lines = 0;
	strct->map.n_cols = 0;
	strct->map.cur_line = 0;
	strct->mvars.img.img = NULL;
	strct->mvars.img.addr = NULL;
	strct->mvars.win = NULL;
	strct->map.map_txt = NULL;
	strct->config.line = NULL;
	ft_init1(strct);
}

void	ft_free_splitted(char **map_txt)
{
	int		i;

	i = 0;
	if (map_txt)
	{
		while (map_txt[i])
		{
			free(map_txt[i]);
			++i;
		}
		free(map_txt);
	}
}

static void	ft_free_strct1(t_strct *strct)
{
	if (strct->mvars.mlx)
		free(strct->mvars.mlx);
	if (strct->mvars.img.img)
		free(strct->mvars.img.img);
	if (strct->mvars.win)
		free(strct->mvars.win);
	if (strct->config.line)
		free(strct->config.line);
	if (strct->map.map_txt)
		ft_free_splitted(strct->map.map_txt);
	if (strct->tex.north.tex_path)
		free(strct->tex.north.tex_path);
	if (strct->tex.south.tex_path)
		free(strct->tex.south.tex_path);
	if (strct->tex.west.tex_path)
		free(strct->tex.west.tex_path);
	if (strct->tex.east.tex_path)
		free(strct->tex.east.tex_path);
	if (strct->tex.sprite.tex_path)
		free(strct->tex.sprite.tex_path);
	ft_free_strct2(strct);
}

void	ft_free_strct(t_strct *strct)
{
	ft_free_strct1(strct);
	if (strct->tex.north.fd && strct->tex.north.fd >= 0)
		if (close(strct->tex.north.fd == -1))
			strct->err_num = CLOSE_FILE_ERR;
	if (strct->tex.south.fd && strct->tex.south.fd >= 0)
		if (close(strct->tex.south.fd == -1))
			strct->err_num = CLOSE_FILE_ERR;
	if (strct->tex.east.fd && strct->tex.east.fd >= 0)
		if (close(strct->tex.east.fd == -1))
			strct->err_num = CLOSE_FILE_ERR;
	if (strct->tex.west.fd && strct->tex.west.fd >= 0)
		if (close(strct->tex.west.fd == -1))
			strct->err_num = CLOSE_FILE_ERR;
	if (strct->tex.sprite.fd && strct->tex.sprite.fd >= 0)
		if (close(strct->tex.sprite.fd == -1))
			strct->err_num = CLOSE_FILE_ERR;
	if (strct->config.fd && strct->config.fd >= 0)
		if (close(strct->config.fd) == -1)
			strct->err_num = CLOSE_FILE_ERR;
}
