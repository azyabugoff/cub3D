/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:41:02 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 19:56:55 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int argc, char *argv[])
{
	t_strct	strct;

	ft_memset(&strct, 0, sizeof(t_strct));
	ft_init_scene(&strct);
	if (!ft_check_args(argc, argv, &strct))
		return (ft_error_kill(&strct));
	if (!ft_check_parse_config(argv, &strct))
		return (ft_error_kill(&strct));
	if (!ft_draw_cub(argc, &strct))
		return (ft_error_kill(&strct));
	ft_free_strct(&strct);
	return (0);
}
