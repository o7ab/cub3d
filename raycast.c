/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:08:25 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/22 22:23:30 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_pixel(t_cub *cub, int x, int y, int color)
{
	char *dst;

	dst = cub->address+ (y * cub->line_length + x * (cub->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_dda(t_rayc *rayc, t_cub *cub)
{
	if (rayc->sidedistx < rayc->sidedisty)
	{
		rayc->sidedistx += rayc->deltadistx;
		cub->mapX += stepX;
		side = 0;
	}
	else
	{
		rayc->sidedisty += rayc.deltadisty;
		cub->mapY += stepY;
		side = 1;
	}
	if (ft_strlen(cub->map[cub->mapX]) > (size_t)cub->mapY)
		if (cub->map[cub->mapX][cub->mapY] == '1')
			hit = 1;

}

int	ft_raycast(t_cub *cub)
{
	int		x;
	double	camerax;
	t_rayc	rayc;

	x = 0;
	while (x < WIDTH)
	{
		camerax = 2 * x / (double)(WIDTH) - 1; //x-coordinate in camera space
		cub->raydirx = cub->dirx + cub->planex * camerax;
		cub->raydiry = cub->diry + cub->planey * camerax;
		cub->mapX = (int)(cub->posx);
		cub->mapY = (int)(cub->posy);
		rayc.deltadistx = fabs(1 / cub->raydirx);
		rayc.deltadisty = fabs(1 / cub->raydiry);
		int stepX;
		int stepY;

		int hit = 0;
		if (cub->raydirx < 0)
		{
			stepX = -1;
			rayc.sidedistx = (cub->posx - cub->mapX) * rayc.deltadistx;
		}
		else
		{
			stepX = 1;
			rayc.sidedistx = (cub->mapX + 1.0 - cub->posx) * rayc.deltadistx;
		}
		if (cub->raydiry < 0)
		{
			stepY = -1;
			rayc.sidedisty = (cub->posy - cub->mapY) * rayc.deltadisty;
		}
		else
		{
			stepY = 1;
			rayc.sidedisty = (cub->mapY + 1.0 - cub->posy) * rayc.deltadisty;
		}
		while (hit == 0)
			ft_dda(); 
		if (side == 0)
			rayc.perpwalldist = (rayc.sidedistx - rayc.deltadistx);
		else
			rayc.perpwalldist = (rayc.sidedisty - rayc.deltadisty);
		//Calculate height of line to draw on screen
		int lineHeight = (int)(HEIGHT / rayc.perpwalldist);

		//calculate lowest and highest pixel to fill in current stripe
		cub->line_start = -lineHeight / 2 + HEIGHT / 2;
		if(cub->line_start < 0)cub->line_start = 0;
			cub->line_end = lineHeight / 2 + HEIGHT / 2;
		if(cub->line_end >= HEIGHT)
			cub->line_end = HEIGHT - 1;
		if(cub->line_start >= HEIGHT)
			cub->line_start = 0;
		int y = 0;
    	while (y < HEIGHT)
    	{
			if (y >= cub->line_start && y <= cub->line_end)
			{
				int color = 0x00F9BA84;
				if (side == 1)
					color = (color >> 1) & 8355711;
				cub->buffer[y][x] = color;
			}
			y++;
      	}
		int i = 0;
		while (i < HEIGHT)
		{
			if (i <  HEIGHT / 2)
				ft_put_pixel(cub, x, i, 0x0098FF98);
			else if (i >  HEIGHT / 2)
				ft_put_pixel(cub, x, i, 0x007E0CD6);
			i++;
		}
		i = 0;
		while (i < HEIGHT)
		{
			if (i >= cub->line_start && i <= cub->line_end)
			{
				ft_put_pixel(cub, x, i,	cub->buffer[i][x]);
			}
			i++;
		}
		x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->mlx_img, 0, 0);
	return (0);
}