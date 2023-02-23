/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:08:25 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/23 14:39:24 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_cub *cub, int x)
{
	int	i;

	i = 0;
	while (i < HEIGHT)
	{
		if (i < HEIGHT / 2)
			ft_put_pixel(cub, x, i, 0x0098FF98);
		else if (i > HEIGHT / 2)
			ft_put_pixel(cub, x, i, 0x007E0CD6);
		i++;
	}
	i = 0;
	while (i < HEIGHT)
	{
		if (i >= cub->line_start && i <= cub->line_end)
		{
			ft_put_pixel(cub, x, i, cub->buffer[i][x]);
		}
		i++;
	}
}

void	ft_dda(t_rayc *rayc, t_cub *cub)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (rayc->sidedistx < rayc->sidedisty)
		{
			rayc->sidedistx += rayc->deltadistx;
			cub->mapx += rayc->stepx;
			rayc->side = 0;
		}
		else
		{
			rayc->sidedisty += rayc->deltadisty;
			cub->mapy += rayc->stepy;
			rayc->side = 1;
		}
		if (ft_strlen(cub->map[cub->mapx]) > (size_t)cub->mapy)
			if (cub->map[cub->mapx][cub->mapy] == '1')
				hit = 1;
	}
}

void	get_side_dist(t_cub *cub, t_rayc *rayc)
{
	if (cub->raydiry < 0)
	{
		rayc->stepy = -1;
		rayc->sidedisty = (cub->posy - cub->mapy) * rayc->deltadisty;
	}
	else
	{
		rayc->stepy = 1;
		rayc->sidedisty = (cub->mapy + 1.0 - cub->posy) * rayc->deltadisty;
	}
	if (cub->raydirx < 0)
	{
		rayc->stepx = -1;
		rayc->sidedistx = (cub->posx - cub->mapx) * rayc->deltadistx;
	}
	else
	{
		rayc->stepx = 1;
		rayc->sidedistx = (cub->mapx + 1.0 - cub->posx) * rayc->deltadistx;
	}
}

void	get_line_dist(t_cub *cub, t_rayc *rayc, int x)
{
	int	y;
	int	color;

	y = 0;
	color = 0;
	if (rayc->side == 0)
		rayc->perpwalldist = (rayc->sidedistx - rayc->deltadistx);
	else
		rayc->perpwalldist = (rayc->sidedisty - rayc->deltadisty);
	init_line(cub, rayc);
	while (y < HEIGHT)
	{
		if (y >= cub->line_start && y <= cub->line_end)
		{
			color = 0x00F9BA84;
			if (rayc->side == 1)
				color = (color >> 1) & 8355711;
			cub->buffer[y][x] = color;
		}
		y++;
	}
}

int	ft_raycast(t_cub *cub)
{
	int		x;
	t_rayc	rayc;

	x = 0;
	while (x < WIDTH)
	{
		ft_init_var(cub, &rayc, x);
		get_side_dist(cub, &rayc);
		ft_dda(&rayc, cub);
		get_line_dist(cub, &rayc, x);
		draw_line(cub, x);
		x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->mlx_img, 0, 0);
	return (0);
}
