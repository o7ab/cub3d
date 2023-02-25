/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:20:12 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/25 13:57:59 by oabushar         ###   ########.fr       */
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

# define WIDTH 1048
# define MAPWIDTH 12
# define MAPHEIGHT 12
# define HEIGHT 800
# define PI 3.14159265359
# define GRID 64

typedef struct s_cub{
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
	char	**map;
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

#endif