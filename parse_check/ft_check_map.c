/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:06:43 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 19:56:20 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_check_map_symbols(char *line, t_strct *strct)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1'
			&& line[i] != '2' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'W' && line[i] != 'E')
		{
			strct->err_num = CONFIG_ERR;
			return (0);
		}
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'E')
		{
			if (strct->config.pers_found_flag == 1)
			{
				strct->err_num = CONFIG_ERR;
				return (0);
			}
			strct->config.pers_found_flag = 1;
		}
		++i;
	}
	return (1);
}

static int	ft_cases(char *line, char **spl_line, t_strct *strct)
{
	if (*line && strct->config.map_end_flag == 0
		&& spl_line[0] && spl_line[0][0] == '1')
	{
		if (strct->config.map_start_flag == 0)
			strct->config.map_start_flag = 1;
		if (strct->config.map_start_flag == 1)
		{
			if (!ft_check_map_symbols(line, strct))
			{
				ft_free_splitted(spl_line);
				return (0);
			}
		}
	}
	if (!(*line) && strct->config.map_start_flag == 1)
		strct->config.map_end_flag = 1;
	if ((*line) && strct->config.map_end_flag == 1
		&& spl_line[0] && spl_line[0][0] == '1')
	{
		ft_free_splitted(spl_line);
		strct->err_num = CONFIG_ERR;
		return (0);
	}
	return (1);
}

int	ft_check_map(char *line, t_strct *strct)
{
	char	**spl_line;

	spl_line = ft_split(line, ' ');
	if (!spl_line)
	{
		strct->err_num = MALLOC_ERR;
		return (0);
	}
	if (!ft_cases(line, spl_line, strct))
		return (0);
	ft_free_splitted(spl_line);
	return (1);
}
