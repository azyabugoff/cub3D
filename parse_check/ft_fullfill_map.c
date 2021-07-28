/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fullfill_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:36:09 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 19:56:11 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_fullfill_line(char *line, t_strct *strct)
{
	int		len_line;
	int		i;

	len_line = ft_strlen(line);
	i = 0;
	while (i < len_line)
	{
		strct->map.map_txt[strct->map.cur_line][i] = line[i];
		if (line[i] == '2')
			++strct->scene.n_sprs;
		++i;
	}
	if (len_line < strct->map.n_cols)
	{
		while (i < strct->map.n_cols)
		{
			strct->map.map_txt[strct->map.cur_line][i] = ' ';
			++i;
		}
	}
}

int	ft_fullfill_map(char *line, t_strct *strct)
{
	char	**spl_line;

	spl_line = ft_split(line, ' ');
	if (!spl_line)
	{
		strct->err_num = MALLOC_ERR;
		return (0);
	}
	if (spl_line[0] && spl_line[0][0] == '1')
	{
		ft_fullfill_line(line, strct);
		++strct->map.cur_line;
	}
	ft_free_splitted(spl_line);
	return (1);
}
