/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:12:07 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 19:56:15 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_check_boundaries(char **arr,
					int i, int j, t_strct *strct)
{
	if (i == 0 || j == 0 || i == strct->map.n_lines - 1
		|| j == strct->map.n_cols - 1)
	{
		if (arr[i][j] != '1' && arr[i][j] != ' ')
		{
			strct->err_num = CONFIG_ERR;
			return (0);
		}
	}
	return (1);
}

static int	ft_check_near_spaces(char **arr,
					int i, int j, t_strct *strct)
{
	if (arr[i][j] == '0' || arr[i][j] == '2' || arr[i][j] == 'N'
		|| arr[i][j] == 'S' || arr[i][j] == 'W' || arr[i][j] == 'E')
	{
		if (!arr[i - 1] || !arr[i + 1] || !arr[i][j - 1] || !arr[i][j + 1]
			|| !arr[i - 1][j - 1] || !arr[i - 1][j + 1] || !arr[i + 1][j - 1]
			|| !arr[i + 1][j + 1]
			|| (arr[i - 1] && arr[i - 1][j] && arr[i - 1][j] == ' ')
			|| (arr[i + 1] && arr[i + 1][j] && arr[i + 1][j] == ' ')
			|| (arr[i] && arr[i][j + 1] && arr[i][j + 1] == ' ')
			|| (arr[i] && arr[i][j - 1] && arr[i][j - 1] == ' ')
			|| (arr[i - 1] && arr[i - 1][j - 1] && arr[i - 1][j - 1] == ' ')
			|| (arr[i - 1] && arr[i - 1][j + 1] && arr[i - 1][j + 1] == ' ')
			|| (arr[i + 1] && arr[i + 1][j - 1] && arr[i + 1][j - 1] == ' ')
			|| (arr[i + 1] && arr[i + 1][j + 1] && arr[i + 1][j + 1] == ' '))
		{
			strct->err_num = CONFIG_ERR;
			return (0);
		}
	}
	return (1);
}

static void	ft_read_player(char **arr,
					int i, int j, t_strct *strct)
{
	if (arr[i][j] == '2')
	{
		++strct->plr.spr_ind;
		strct->plr.sprs[strct->plr.spr_ind].cent_x = j
			* strct->map.bound_x + strct->map.bound_x / 2;
		strct->plr.sprs[strct->plr.spr_ind].cent_y = i
			* strct->map.bound_y + strct->map.bound_y / 2;
	}
	if (arr[i][j] == 'N' || arr[i][j] == 'S'
		|| arr[i][j] == 'W' || arr[i][j] == 'E')
	{
		strct->plr.nswe = arr[i][j];
		strct->plr.x = j;
		strct->plr.y = i;
	}
}

int	ft_check_walls(t_strct *strct)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (strct->map.map_txt[i])
	{
		j = 0;
		while (strct->map.map_txt[i][j])
		{
			if (!ft_check_boundaries(strct->map.map_txt, i, j, strct))
				return (0);
			if (!ft_check_near_spaces(strct->map.map_txt, i, j, strct))
				return (0);
			ft_read_player(strct->map.map_txt, i, j, strct);
			++j;
		}
		++i;
	}
	return (1);
}
