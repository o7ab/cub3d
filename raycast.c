/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:08:25 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/20 21:18:48 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_pixel(t_cub *cub, int x, int y, int color)
{
	char *dst;

	dst = cub->address+ (y * cub->line_length + x * (cub->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// temp function
void	draw_line(t_cub *cub, int x, int start, int end, int color)
{	
	int	i;
	i = start;
	while (i <= end)
	{
		ft_put_pixel(cub, x, i, color);
		// mlx_pixel_put(cub->mlx, cub->mlx_win, x, i, color);
		i++;
	}
}

int	ft_raycast(t_cub *cub)
// void	ft_raycast(t_cub *cub)
{
	double camerax = 0;
	double sidedistx = 0;
	double sidedisty = 0;
	double deltadistx = 0;
	double deltadisty = 0;
	double perp_wall_dist = 0;
	// double wall_x;
	// double move_speed = 1.5;
	int stepx = 0;
	int stepy = 0;
	int hit = 0;
	int side = 0;
	int i = 0;
	int w = WIDTH;
	// if (!cub_check_args(argc, argv))
	// 	return (0);
	int mapx = (int)cub->posx;
	int mapy = (int)cub->posy;
	while (i < w)
	{
		camerax = 2 * i / (double)w - 1;
		cub->raydirx = (cub->dirx + cub->planex * camerax);
		cub->raydiry = (cub->diry + cub->planey * camerax);
		deltadistx = fabs(1 / cub->raydirx);
		deltadisty = fabs(1 / cub->raydiry);
		if (cub->raydirx < 0)
		{
			stepx = -1;
			sidedistx = (cub->posx - mapx) * deltadistx;
		}
		else
		{
			stepx = 1;
			sidedistx = (mapx + 1.0 - cub->posx) * deltadistx;
		}
		if (cub->raydiry < 0)
		{
			stepy = -1;
			sidedisty = (cub->posy - mapy) * deltadisty;
		}
		else
		{
			stepy = 1;
			sidedisty = (mapy + 1.0 - cub->posy) * deltadisty;
		}
		while (hit == 0)
		{
			if (sidedistx < sidedisty)
			{
				sidedistx += deltadistx;
				mapx += stepx;
				side = 0;
			}
			else
			{
				sidedisty += deltadisty;
				mapy += stepy;
				side = 1;
			}
			if (ft_strlen(cub->map[mapx]) > (size_t) mapy)
			{
				if (cub->map[mapx][mapy] == '1')
					hit = 1;

			}
		}
		if (side == 0)
			perp_wall_dist = (sidedistx - deltadistx);
		else
			perp_wall_dist = (sidedisty - deltadisty);
		cub->line_height = (int) (HEIGHT / perp_wall_dist);
		cub->line_start = -cub->line_height / 2 + HEIGHT / 2;
		// if (cub->line_start < 0 || cub->line_start >= cub->line_height)
		if (cub->line_start < 0)
			cub->line_start = 0;
		cub->line_end = cub->line_height / 2 + HEIGHT / 2;
		if (cub->line_end >= HEIGHT)
			cub->line_end = HEIGHT - 1;
		// if (side == 0)
		// 	wall_x = cub->posx + perp_wall_dist * cub->raydirx;
		// else
		// 	wall_x = cub->posy + perp_wall_dist * cub->raydiry;
		// wall_x -= floor(wall_x);
		// int tex_x = (int)(wall_x * (double)64);
		// if (side == 0 && cub->raydirx > 0)
		// 	tex_x = 64 - tex_x - 1;
		// if (side == 1 && cub->raydiry < 0)
		// 	tex_x = 64 - tex_x - 1;
		// double step = 1.0 * 64 / cub->line_height;
		// double tex_pos = (cub->line_start - HEIGHT / 2 + cub->line_height / 2) * step;
		// int y = 0;
		// while (y < HEIGHT)
		// {
		// 	if (y >= cub->line_start && y <= cub->line_end)
		// 	{
		// 		// int tex_y = (int)tex_pos & (64 - 1);
		// 		// tex_pos += step;
		// 		int color;
		// 	// printf("the testtttt is here \n, %d", worldMap[mapx][mapy]);
		// 		if (side == 0 && cub->raydirx > 0)
		// 			color = 0x00FF0000;
		// 		else if (side == 0 && cub->raydirx < 0)
		// 			color = 0x0FFF0000;
		// 		else if (side == 1 && cub->raydiry > 0)
		// 			color = 0x000F00FF;
		// 		else
		// 			color = 0x000000FF;
		// 		// if (side == 1)
		// 		// 	color = (color >> 1) & 8355711;
		// 		cub->buffer[y][i] = color;
		// 	}
		// 	y++;
		// }
		// int j = cub->line_start;
		// // while (j < HEIGHT)
		// while (j < cub->line_end - cub->line_start)
		// {
		// 	// while (j )
		// 	// if (j < cub->line_start)
		// 	// if (j < HEIGHT / 2)
		// 		// ft_put_pixel(cub, i, j, 0x00000000);
		// 	// else if (j > cub->line_end)
		// 	// else if (j > HEIGHT / 2)
		// 		ft_put_pixel(cub, i, j, 0x00FFFFFF);
		// 	j++;
		// }
		// j = 0;

		int	color = 0xFFFF00;
		// if (side)
		// 	color /= 2;

		draw_line(cub, i, cub->line_start, cub->line_end, color);
		// while (j < HEIGHT)
		// {
		// 	if (j >= cub->line_start && j <= cub->line_end)
		// 		ft_put_pixel(cub, i, j, cub->buffer[j][i]);
		// 	j++;
		// }
		i++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->mlx_img, 0, 0);
	return 0;
}