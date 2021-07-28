/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parse_dir_spr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:02:29 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 19:56:17 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_open_path_check(char **spl_line,
						int *fd, char **tex_path, t_strct *strct)
{
	*fd = open(spl_line[1], O_RDONLY);
	if (*fd < 0)
	{
		strct->err_num = OPEN_TEX_ERR;
		ft_free_splitted(spl_line);
		return (0);
	}
	*tex_path = ft_strdup(spl_line[1]);
	if (!*tex_path)
	{
		strct->err_num = MALLOC_ERR;
		ft_free_splitted(spl_line);
		return (0);
	}
	return (1);
}

static int	ft_if_cmp(char **spl_line, char *s2,
								t_strct *strct, int flag)
{
	int	len1;
	int	len2;

	len1 = ft_strlen(spl_line[0]);
	len2 = ft_strlen(s2);
	if (ft_strncmp(spl_line[0], s2, (len1 > len2) ? len1 : len2) == 0)
	{
		if (flag == 1)
			if (!ft_check_parse_dir_spr1(spl_line, strct))
				return (0);
		if (flag == 2)
			if (!ft_check_parse_dir_spr2(spl_line, strct))
				return (0);
		if (flag == 3)
			if (!ft_check_parse_dir_spr3(spl_line, strct))
				return (0);
		if (flag == 4)
			if (!ft_check_parse_dir_spr4(spl_line, strct))
				return (0);
		if (flag == 5)
			if (!ft_check_parse_dir_spr5(spl_line, strct))
				return (0);
	}
	return (1);
}

static int	ft_check_parse_dir_spr0(char **spl_line, t_strct *strct)
{
	if (spl_line && spl_line[0])
	{
		if (!ft_if_cmp(spl_line, "NO", strct, 1))
			return (0);
		if (!ft_if_cmp(spl_line, "SO", strct, 2))
			return (0);
		if (!ft_if_cmp(spl_line, "WE", strct, 3))
			return (0);
		if (!ft_if_cmp(spl_line, "EA", strct, 4))
			return (0);
		if (!ft_if_cmp(spl_line, "S", strct, 5))
			return (0);
	}
	return (1);
}

int	ft_check_parse_dir_spr(char *line, t_strct *strct)
{
	char	**spl_line;

	spl_line = ft_split(line, ' ');
	if (!spl_line)
	{
		strct->err_num = MALLOC_ERR;
		return (0);
	}
	if (!ft_check_parse_dir_spr0(spl_line, strct))
		return (0);
	ft_free_splitted(spl_line);
	return (1);
}
