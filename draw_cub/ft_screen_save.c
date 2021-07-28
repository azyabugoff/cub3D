/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen_save.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:44:01 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 15:40:47 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_fullfill_head(t_strct *strct)
{
	ft_memset(&strct->bmp, 0, sizeof(strct->bmp));
	strct->bmp.filesize = (strct->scene.width * strct->scene.height
			* (strct->mvars.img.bits_per_pixel / 8)) + 54;
	strct->bmp.pix_data_offset = 54;
	strct->bmp.header_size = 40;
	strct->bmp.img_width = strct->scene.width;
	strct->bmp.img_height = strct->scene.height;
	strct->bmp.n_planes = 1;
	strct->bmp.bits_per_pixel = strct->mvars.img.bits_per_pixel;
	strct->bmp.img_size = strct->scene.width * strct->scene.height
		* (strct->mvars.img.bits_per_pixel / 8);
}

static void	ft_write_bmp(t_strct *strct, int fd)
{
	int				x;
	int				y;
	char			*clr;
	unsigned int	color;

	write(fd, "BM", 2);
	write(fd, &strct->bmp, sizeof(strct->bmp));
	y = strct->scene.height;
	x = -1;
	while (--y >= 0)
	{
		x = -1;
		while (++x < strct->scene.width)
		{
			clr = strct->mvars.img.addr + (y * strct->mvars.img.line_length
					+ x * (strct->mvars.img.bits_per_pixel / 8));
			color = *(unsigned int *)clr;
			write(fd, &color, 4);
		}
	}
}

static int	ft_make_screen(t_strct *strct)
{
	int				fd;

	fd = open("saved_screen/screenshot.bmp",
			O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd < 0)
	{
		strct->err_num = OPEN_FILE_ERR;
		return (0);
	}
	ft_fullfill_head(strct);
	ft_write_bmp(strct, fd);
	if (close(fd) == -1)
	{
		strct->err_num = CLOSE_FILE_ERR;
		return (0);
	}
	return (1);
}

int	ft_screen_save(t_strct *strct)
{
	ft_ray_cast(strct->map.map_txt, strct);
	if (!ft_make_screen(strct))
		return (0);
	return (1);
}
