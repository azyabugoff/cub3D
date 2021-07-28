/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:36:37 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 20:02:38 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_if_not_ret_er(char **spl_conf, t_strct *strct)
{
	if (!spl_conf)
	{
		strct->err_num = MALLOC_ERR;
		return (0);
	}
	return (1);
}

static int	ft_check_config_name(char *argv[], t_strct *strct)
{
	int		i;
	char	**spl_conf;

	i = 0;
	spl_conf = ft_split(argv[1], '.');
	if (!ft_if_not_ret_er(spl_conf, strct))
		return (0);
	while (spl_conf[i])
		++i;
	if (i == 1)
	{
		ft_free_splitted(spl_conf);
		return (0);
	}
	if (ft_strncmp(spl_conf[i - 1], "cub",
			ft_tern_i((ft_strlen(spl_conf[i - 1]) > 3),
				ft_strlen(spl_conf[i - 1]), 3)) != 0)
	{
		ft_free_splitted(spl_conf);
		return (0);
	}
	i = 0;
	ft_free_splitted(spl_conf);
	return (1);
}

static int	ft_check_save_name(char *argv[])
{
	int		save_len;

	save_len = ft_strlen(argv[2]);
	if (ft_strncmp(argv[2], "--save", (save_len > 6) ? save_len : 6) != 0)
		return (0);
	return (1);
}

int	ft_check_args(int argc, char *argv[], t_strct *strct)
{
	if (argc == 2 || argc == 3)
	{
		if (!ft_check_config_name(argv, strct))
		{
			if (!(strct->err_num))
				strct->err_num = ARGS_NAME_ERR;
			return (0);
		}
		if (argc == 3)
		{
			if (!ft_check_save_name(argv))
			{
				strct->err_num = ARGS_NAME_ERR;
				return (0);
			}
		}
	}
	else
	{
		strct->err_num = ARGS_NUM_ERR;
		return (0);
	}
	return (1);
}
