/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:20:12 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/25 19:30:10 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "mlx/mlx.h"
#include <sys/errno.h>
# include "fcntl.h"
# include "get_next_line/get_next_line.h"



# define WIDTH 1048
# define MAPWIDTH 12
# define MAPHEIGHT 12
# define HEIGHT 800
# define PI 3.14159265359
# define GRID 64

typedef struct s_cub{
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	int				c_color;
	int				f_color;
	int				map_width;
	int				map_height;
	int				config_fd;
	double			start_angle;
	int				index;
	int				c_color_count;
	int				f_color_count;
	char			**map;
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	int		line_height;
	int		line_length;
	int		endian;
	int		line_start;
	int		line_end;
	int		bits_per_pixel;
	char	*address;
	int		*textures[4];
	int		buffer[HEIGHT][WIDTH];
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	raydirx;
	double	raydiry;
	double	move_speed;
	double	rotate;
	// char	**map;
	int		mapx;
	int		mapy;
}	t_cub;

typedef struct s_rayc{
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		side;
	int		stepx;
	int		stepy;
}	t_rayc;

int		cub_key_press(int keycode, t_cub *cub);
int		ft_raycast(t_cub *cub);
char	**init_map(t_cub *cub);
void	ft_put_pixel(t_cub *cub, int x, int y, int color);
void	init_line(t_cub *cub, t_rayc *rayc);
void	ft_init_var(t_cub *cub, t_rayc *rayc, int x);
int		cub_mouse_press(int keycode, t_cub *cub);
int		parse_map(t_cub *data, int argc, char **argv);
void	check_chars(t_cub *data);
void	resize_width(t_cub *cub);
int		check_if_no_more_map(t_cub *data);
void	check_elements(t_cub *data);
void	check_spaces_from_all_dir(t_cub *data);
void	check_if_closed_by_walls(t_cub *data);
void	print_error(t_cub *data, char *msg);
void	parse_map_contents(t_cub *data);
void	check_player_pos(t_cub *data, char c, int *x);
void	free_2d(char ***str);
int	color_atoi(const char *str);
int	ft_strlen_2d(char **str);
void	calc_map_width_height(t_cub *cub);
void	free_all(t_cub *data);

#endif