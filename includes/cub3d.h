/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:37:45 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/04/14 19:56:46 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx_mms/mlx.h"
# include "../libft/libft.h"
# include "../GNL/get_next_line.h"
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

# define NO_ERR 0
# define ARGS_NUM_ERR 1
# define ARGS_NAME_ERR 2
# define OPEN_FILE_ERR 3
# define CONFIG_ERR 4
# define MAP_ERR 5
# define MALLOC_ERR 6
# define CLOSE_FILE_ERR 7
# define OPEN_TEX_ERR 8
# define ERR_LITTLE_RESOL 9
# define ADDR_DATA_ERR 10
# define FL_UP 0x00000001
# define FL_DOWN 0x00000010
# define FL_LEFT 0x00000100
# define FL_RIGHT 0x00001000
# define FL_ROT_LEFT 0x00010000
# define FL_ROT_RIGHT 0x00100000

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx_vars
{
	void			*mlx;
	void			*win;
	t_data			img;
}	t_mlx_vars;

typedef struct s_scene
{
	int	width;
	int	height;
	int	n_resols;
	int	n_north;
	int	n_south;
	int	n_west;
	int	n_east;
	int	n_sprites;
	int	n_floors;
	int	n_ceils;
	int	flag_found_map;
	int	n_sprs;
}	t_scene;

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int	rgb_int;
}	t_rgb;

typedef struct s_nswe_spr
{
	int				fd;
	char			*tex_path;
	void			*img;
	unsigned int	*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
	int				color;
	t_coord			tex_coord;
}					t_nswe_spr;

typedef struct s_floor
{
	t_rgb			rgb;
	int				col_height;
}	t_floor;

typedef struct s_ceiling
{
	t_rgb			rgb;
	int				col_height;
}	t_ceiling;

typedef struct s_textures
{
	t_nswe_spr		north;
	t_nswe_spr		south;
	t_nswe_spr		west;
	t_nswe_spr		east;
	t_nswe_spr		sprite;
	t_floor			floor;
	t_ceiling		ceil;
}	t_textures;

typedef struct s_map
{
	char			**map_txt;
	int				n_lines;
	int				n_cols;
	int				cur_line;
	double			bound_x;
	double			bound_y;
}	t_map;

typedef struct s_config
{
	char			*line;
	int				ret_gnl;
	int				fd;
	int				map_start_flag;
	int				map_end_flag;
	int				pers_found_flag;
}	t_config;

typedef struct s_sprs
{
	double			dist;
	double			cent_x;
	double			cent_y;
	double			vec_x;
	double			vec_y;
	double			spr_ang;
	int				n_spr_col;
	int				x_of;
	int				y_of;
	int				spr_size;
}	t_sprs;

typedef struct s_player
{
	double			x;
	double			y;
	double			st_v;
	double			end_v;
	double			pov;
	double			fov;
	char			nswe;
	double			step;
	int				tex_ind;
	double			shift;
	int				wall_height;
	double			dist;
	t_sprs			*sprs;
	int				spr_ind;
	double			*ray_dists;
	unsigned int	mvflags;
}	t_player;

typedef struct s_bmp
{
	unsigned int	filesize;
	unsigned short	reserved1;
	unsigned short	reserved2;
	unsigned int	pix_data_offset;
	unsigned int	header_size;
	unsigned int	img_width;
	unsigned int	img_height;
	unsigned short	n_planes;
	unsigned short	bits_per_pixel;
	unsigned int	compression;
	unsigned int	img_size;
	unsigned int	xpix_per_meter;
	unsigned int	y_pix_per_meter;
	unsigned int	total_colors;
	unsigned int	important_colors;
}	t_bmp;

typedef struct s_strct
{
	t_mlx_vars		mvars;
	t_scene			scene;
	t_textures		tex;
	t_map			map;
	t_config		config;
	t_player		plr;
	t_bmp			bmp;
	int				err_num;
}	t_strct;

void	ft_init_scene(t_strct *strct);
void	ft_init1(t_strct *strct);
void	ft_init2(t_strct *strct);
void	ft_free_strct2(t_strct *strct);
int		ft_conv_rgb_to_hex(int r, int g, int b);
void	ft_free_splitted(char **map_txt);
void	ft_free_strct(t_strct *strct);
int		ft_check_args(int argc, char *argv[], t_strct *strct);
int		ft_error_kill(t_strct *strct);
int		ft_check_parse_config(char *argv[], t_strct *strct);
int		ft_check_parse_resol(char *line, t_strct *strct);
int		ft_check_number(char *spl_line_i);
int		ft_check_parse_dir_spr(char *line, t_strct *strct);
int		ft_open_path_check(char **spl_line,
			int *fd, char **tex_path, t_strct *strct);
int		ft_check_parse_dir_spr1(char **spl_line, t_strct *strct);
int		ft_check_parse_dir_spr2(char **spl_line, t_strct *strct);
int		ft_check_parse_dir_spr3(char **spl_line, t_strct *strct);
int		ft_check_parse_dir_spr4(char **spl_line, t_strct *strct);
int		ft_check_parse_dir_spr5(char **spl_line, t_strct *strct);
int		ft_rgb_in_range(int r, int g, int b);
int		ft_check_parse_floor_ceil(char *line, t_strct *strct);
int		ft_check_begin_line(char *line, t_strct *strct);
int		ft_threrr_fl_ceil(char **spl_line, t_strct *strct);
int		ft_check_map(char *line, t_strct *strct);
int		ft_check_open_config(char *argv[], t_strct *strct);
int		ft_parse_map_check_walls(char *argv[], t_strct *strct);
int		ft_fullfill_map(char *line, t_strct *strct);
int		ft_check_walls(t_strct *strct);
void	ft_init_window(t_strct *strct);
int		ft_init_dir_spr(t_strct *strct);
int		ft_draw_cub(int argc, t_strct *strct);
void	ft_mlx_pixel_put(t_strct *strct, int x, int y, int color);
void	ft_draw_card_el(t_strct *strct, int color,
			double x, double y);
int		ft_draw_card(t_strct *strct);
int		key_hook0(int key, t_strct *strct);
int		key_hook(int key, t_strct *strct);
int		key_release(int key, t_strct *strct);
void	ft_rot_left(t_strct *strct);
void	ft_rot_right(t_strct *strct);
int		ft_move(t_strct *strct);
int		red_cross_hook(t_strct *strct);
int		ft_ray_cast(char **arr, t_strct *strct);
int		ft_barrier_distance(int key, t_strct *strct);
int		ft_is_bar_dist(t_strct *strct, t_player ray, double shiftx,
			double shifty);
void	ft_draw_column(int dist, t_player ray, t_strct *strct);
void	ft_get_needed_tex_nswe(t_player *ray, t_strct *strct);
void	ft_draw_nswe(t_player ray, t_strct *strct);
void	ft_nswe_spr_pixel_put(t_nswe_spr *data,
			int x, int y, int color);
int		ft_calc_plr_view(int dist, t_player *ray, t_strct *strct);
void	ft_set_tex_column(t_player ray, t_strct *strct);
void	ft_set_tex_row(t_player ray, t_strct *strct, int i);
void	ft_mirror_val(double *val, int mirror, t_nswe_spr nswe);
int		ft_is_nswe0(char c);
int		ft_alloc_spr_arr(t_strct *strct);
void	ft_draw_sprites(t_strct *strct);
void	ft_sort_sprites(t_strct *strct);
void	ft_init_sprite_vals(t_strct *strct, t_sprs *sprs);
int		ft_screen_save(t_strct *strct);

#endif
