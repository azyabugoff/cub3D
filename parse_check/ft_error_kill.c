/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_kill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:55:56 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 19:56:12 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_threrr_fl_ceil(char **spl_line, t_strct *strct)
{
	strct->err_num = CONFIG_ERR;
	ft_free_splitted(spl_line);
	return (0);
}

static int	ft_error_kill1(t_strct *strct)
{
	if (strct->err_num == ARGS_NUM_ERR)
	{
		ft_putstr_fd("Error\nWrong number of arguments.\n", 1);
		return (0);
	}
	else if (strct->err_num == ARGS_NAME_ERR)
	{
		ft_putstr_fd("Error\nWrong name of the config or flag.\n", 1);
		return (0);
	}
	else if (strct->err_num == OPEN_FILE_ERR)
	{
		ft_putstr_fd("Error\nCannot open the config.\n", 1);
		return (0);
	}
	else if (strct->err_num == OPEN_TEX_ERR)
	{
		ft_putstr_fd("Error\nCannot open some file with textures.\n", 1);
		return (0);
	}
	return (1);
}

static int	ft_error_kill2(t_strct *strct)
{
	if (strct->err_num == CONFIG_ERR)
	{
		ft_putstr_fd("Error\nWrong configurations.\n", 1);
		return (0);
	}
	else if (strct->err_num == MAP_ERR)
	{
		ft_putstr_fd("Error\nWrong map configuration.\n", 1);
		return (0);
	}
	else if (strct->err_num == MALLOC_ERR)
	{
		ft_putstr_fd("Error\nMalloc error.\n", 1);
		return (0);
	}
	else if (strct->err_num == CLOSE_FILE_ERR)
	{
		ft_putstr_fd("Error\nCannot close some file.\n", 1);
		return (0);
	}
	return (1);
}

int	ft_error_kill(t_strct *strct)
{
	if (!ft_error_kill1(strct) || !ft_error_kill2(strct))
	{
		ft_free_strct(strct);
		return (0);
	}
	if (strct->err_num == ERR_LITTLE_RESOL)
	{
		ft_putstr_fd("Too little resolution width or height.\n", 1);
		ft_free_strct(strct);
		return (0);
	}
	if (strct->err_num == ADDR_DATA_ERR)
	{
		ft_putstr_fd("Error\nCould not get gata addr.\n", 1);
		ft_free_strct(strct);
		return (0);
	}
	ft_free_strct(strct);
	return (1);
}
