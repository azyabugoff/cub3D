/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parse_config.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:01:36 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 19:56:19 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_open_config(char *argv[], t_strct *strct)
{
	int	test_fd;

	test_fd = -1;
	strct->config.ret_gnl = 0;
	strct->config.line = NULL;
	test_fd = open(argv[1], O_WRONLY);
	if (test_fd < 0)
	{
		if (errno == EISDIR)
		{
			strct->err_num = OPEN_FILE_ERR;
			return (0);
		}
	}
	if (test_fd >= 0)
		close(test_fd);
	strct->config.fd = open(argv[1], O_RDONLY);
	if (strct->config.fd < 0)
	{
		strct->err_num = OPEN_FILE_ERR;
		return (0);
	}
	return (1);
}

static int	ft_close_config_ch_flags(int *fd, t_strct *strct)
{
	if (*fd && *fd >= 0)
	{
		if (close(*fd) == -1)
		{
			strct->err_num = CLOSE_FILE_ERR;
			return (0);
		}
	}
	if (strct->config.pers_found_flag == 0 || strct->config.map_start_flag == 0)
	{
		strct->err_num = CONFIG_ERR;
		return (0);
	}
	return (1);
}

static int	ft_all_checks(char *line, t_strct *strct)
{
	if (!ft_check_begin_line(line, strct))
		return (0);
	if (!ft_check_parse_resol(line, strct))
		return (0);
	if (!ft_check_parse_dir_spr(line, strct))
		return (0);
	if (!ft_check_parse_floor_ceil(line, strct))
		return (0);
	if (!ft_check_map(line, strct))
		return (0);
	return (1);
}

static int	ft_check_all_idis(t_strct *strct)
{
	if (!strct->scene.n_resols || !strct->scene.n_north
		|| !strct->scene.n_south || !strct->scene.n_west
		|| !strct->scene.n_east || !strct->scene.n_sprites
		|| !strct->scene.n_floors || !strct->scene.n_ceils)
	{
		strct->err_num = CONFIG_ERR;
		return (0);
	}
	return (1);
}

int	ft_check_parse_config(char *argv[], t_strct *strct)
{
	if (!ft_check_open_config(argv, strct))
		return (0);
	strct->config.ret_gnl = get_next_line(strct->config.fd,
			&strct->config.line);
	while (strct->config.ret_gnl > 0)
	{
		if (!ft_all_checks(strct->config.line, strct))
			return (0);
		free(strct->config.line);
		strct->config.line = NULL;
		strct->config.ret_gnl = get_next_line(strct->config.fd,
				&strct->config.line);
	}
	if (!ft_all_checks(strct->config.line, strct))
		return (0);
	free(strct->config.line);
	strct->config.line = NULL;
	if (!ft_close_config_ch_flags(&strct->config.fd, strct))
		return (0);
	if (!ft_parse_map_check_walls(argv, strct))
		return (0);
	return (ft_check_all_idis(strct));
}
