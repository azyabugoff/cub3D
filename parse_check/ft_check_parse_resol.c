/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parse_resol.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:48:18 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 19:56:16 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_number(char *spl_line_i)
{
	int	i;

	i = 0;
	if (!spl_line_i)
		return (0);
	while (spl_line_i[i])
	{
		if (spl_line_i[i] < '0' || spl_line_i[i] > '9')
			return (0);
		++i;
	}
	return (1);
}

static int	ft_read_resol(char **spl_line, t_strct *strct)
{
	int		width;
	int		height;

	width = ft_atoi(spl_line[1]);
	height = ft_atoi(spl_line[2]);
	if (width == 0 || height == 0)
	{
		strct->err_num = CONFIG_ERR;
		ft_free_splitted(spl_line);
		return (0);
	}
	if (width > 0 && width < strct->scene.width)
		strct->scene.width = width;
	if (height > 0 && height < strct->scene.height)
		strct->scene.height = height;
	return (1);
}

static int	ft_check_parse_resol2(char **spl_line, t_strct *strct)
{
	if (strct->scene.n_resols > 0 || strct->config.map_start_flag > 0)
	{
		strct->err_num = CONFIG_ERR;
		ft_free_splitted(spl_line);
		return (0);
	}
	strct->scene.n_resols = 1;
	if (!ft_check_number(spl_line[1])
		|| !ft_check_number(spl_line[2]))
	{
		strct->err_num = CONFIG_ERR;
		ft_free_splitted(spl_line);
		return (0);
	}
	return (1);
}

static int	ft_check_parse_resol1(char **spl_line, t_strct *strct)
{
	int		i;

	i = 0;
	if (spl_line && spl_line[0])
	{
		if (ft_strncmp(spl_line[0], "R", (ft_strlen(spl_line[0]) > 1)
				? ft_strlen(spl_line[0]) : 1) == 0)
		{
			while (spl_line && spl_line[i])
				++i;
			if (i != 3)
			{
				strct->err_num = CONFIG_ERR;
				ft_free_splitted(spl_line);
				return (0);
			}
			if (!ft_check_parse_resol2(spl_line, strct))
				return (0);
			if (!ft_read_resol(spl_line, strct))
				return (0);
		}
	}
	return (1);
}

int	ft_check_parse_resol(char *line, t_strct *strct)
{
	char	**spl_line;

	spl_line = ft_split(line, ' ');
	if (!spl_line)
	{
		strct->err_num = MALLOC_ERR;
		return (0);
	}
	if (!ft_check_parse_resol1(spl_line, strct))
		return (0);
	ft_free_splitted(spl_line);
	return (1);
}
