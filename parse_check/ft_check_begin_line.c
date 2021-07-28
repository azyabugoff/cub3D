/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_begin_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:48:18 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 19:56:20 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_is_declaration1(char **spl_line, int len)
{
	int		flag;

	flag = 0;
	if (ft_strncmp(spl_line[0], "R", (len > 1) ? len : 1) == 0)
		flag = 1;
	else if (ft_strncmp(spl_line[0], "NO", (len > 2) ? len : 2) == 0)
		flag = 1;
	else if (ft_strncmp(spl_line[0], "SO", (len > 2) ? len : 2) == 0)
		flag = 1;
	else if (ft_strncmp(spl_line[0], "WE", (len > 2) ? len : 2) == 0)
		flag = 1;
	else if (ft_strncmp(spl_line[0], "EA", (len > 2) ? len : 2) == 0)
		flag = 1;
	else if (ft_strncmp(spl_line[0], "S", (len > 1) ? len : 1) == 0)
		flag = 1;
	else if (ft_strncmp(spl_line[0], "F", (len > 1) ? len : 1) == 0)
		flag = 1;
	if (flag == 0)
		return (0);
	return (1);
}

static int	ft_is_declaration2(char **spl_line, int len,
										char *line, t_strct *strct)
{
	int		flag;

	flag = 0;
	if (ft_strncmp(spl_line[0], "C", (len > 1) ? len : 1) == 0)
		flag = 1;
	else if (spl_line[0][0] == '1')
	{
		++(strct->map.n_lines);
		strct->map.n_cols = ft_tern_i(((int)ft_strlen(line)
					> strct->map.n_cols),
				(int)ft_strlen(line), strct->map.n_cols);
		flag = 1;
	}
	if (flag == 0)
		return (0);
	return (1);
}

static int	ft_decl_help(char **spl_line, int len, char *line, t_strct *strct)
{
	if (!ft_is_declaration1(spl_line, len)
		&& !ft_is_declaration2(spl_line, len, line, strct))
		return (0);
	return (1);
}

int	ft_check_begin_line(char *line, t_strct *strct)
{
	int		len;
	char	**spl_line;

	spl_line = NULL;
	len = ft_strlen(line);
	if (line)
	{
		spl_line = ft_split(line, ' ');
		if (!spl_line)
		{
			strct->err_num = MALLOC_ERR;
			return (0);
		}
		if (spl_line && spl_line[0])
		{
			if (!ft_decl_help(spl_line, len, line, strct))
			{
				ft_free_splitted(spl_line);
				strct->err_num = CONFIG_ERR;
				return (0);
			}
		}
	}
	ft_free_splitted(spl_line);
	return (1);
}
