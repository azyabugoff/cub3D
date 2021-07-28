/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_check_walls.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 13:14:42 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 19:56:10 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_alloc_map_arr(t_strct *strct)
{
	int		i;

	strct->map.map_txt = (char **)malloc(sizeof(char *)
			* (strct->map.n_lines + 1));
	if (!strct->map.map_txt)
	{
		strct->err_num = MALLOC_ERR;
		return (0);
	}
	strct->map.map_txt[strct->map.n_lines] = NULL;
	i = 0;
	while (i < strct->map.n_lines)
	{
		strct->map.map_txt[i] = (char *)malloc(sizeof(char)
				* (strct->map.n_cols + 1));
		if (!strct->map.map_txt[i])
		{
			strct->err_num = MALLOC_ERR;
			return (0);
		}
		++i;
	}
	return (1);
}

static void	ft_fullfill_by_zeros(t_strct *strct)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (strct->map.map_txt[i])
	{
		j = 0;
		while (j < strct->map.n_cols)
		{
			strct->map.map_txt[i][j] = '\0';
			++j;
		}
		strct->map.map_txt[i][j] = '\0';
		++i;
	}
}

static int	ft_gnl_cicle(t_strct *strct)
{
	if (!ft_fullfill_map(strct->config.line, strct))
		return (0);
	free(strct->config.line);
	strct->config.line = NULL;
	strct->config.ret_gnl = get_next_line(strct->config.fd,
			&strct->config.line);
	return (1);
}

int	ft_parse_map_check_walls(char *argv[], t_strct *strct)
{
	if (!ft_check_open_config(argv, strct))
		return (0);
	if (!ft_alloc_map_arr(strct))
		return (0);
	ft_fullfill_by_zeros(strct);
	strct->config.ret_gnl = get_next_line(strct->config.fd,
			&strct->config.line);
	while (strct->config.ret_gnl > 0)
		if (!ft_gnl_cicle(strct))
			return (0);
	if (!ft_fullfill_map(strct->config.line, strct))
		return (0);
	free(strct->config.line);
	strct->config.line = NULL;
	if (!ft_alloc_spr_arr(strct))
		return (0);
	strct->config.line = NULL;
	if (!ft_check_walls(strct))
		return (0);
	return (1);
}
