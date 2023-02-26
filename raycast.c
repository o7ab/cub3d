/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:08:25 by oabushar          #+#    #+#             */
/*   Updated: 2023/02/26 16:16:47 by oabushar         ###   ########.fr       */
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

int	ret_color(t_cub *cub, t_rayc *rayc)
{
	int	color;

	color = 0;
	if (rayc->side == 0 && cub->raydirx > 0)
		color = (int)cub->texture[NO][GRID * rayc->texy + rayc->texx];
	if (rayc->side == 0 && cub->raydirx < 0)
		color = (int)cub->texture[SO][GRID * rayc->texy + rayc->texx];
	if (rayc->side == 1 && cub->raydiry > 0)
		color = (int)cub->texture[WE][GRID * rayc->texy + rayc->texx];
	if (rayc->side == 1 && cub->raydiry < 0)
		color = (int)cub->texture[EA][GRID * rayc->texy + rayc->texx];
	if (rayc->side == 1)
		color = (color >> 1) & 8355711;
	return (color);
}

void	get_line_dist(t_cub *cub, t_rayc *rayc, int x)
{
	if (rayc->side == 0)
		rayc->perpwalldist = (rayc->sidedistx - rayc->deltadistx);
	else
		rayc->perpwalldist = (rayc->sidedisty - rayc->deltadisty);
	init_line(cub, rayc);
	while (rayc->y < HEIGHT)
	{
		if (rayc->y >= cub->line_start && rayc->y <= cub->line_end)
		{
			rayc->texy = (int)rayc->texpos & (cub->img_height[0] - 1);
			rayc->texpos += rayc->step;
			cub->buffer[rayc->y][x] = ret_color(cub, rayc);
		}
		rayc->y++;
	}
}

void	init_rayc(t_rayc *rayc)
{
	rayc->sidedistx = 0;
	rayc->sidedisty = 0;
	rayc->deltadistx = 0;
	rayc->deltadisty = 0;
	rayc->perpwalldist = 0;
	rayc->stepx = 0;
	rayc->stepy = 0;
	rayc->wallx = 0;
	rayc->side = 0;
	rayc->y = 0;
	rayc->texx = 0;
	rayc->texy = 0;
	rayc->texpos = 0;
	rayc->step = 0;
}

int	ft_raycast(t_cub *cub)
{
	int		x;
	t_rayc	rayc;

	x = 0;
	while (x < WIDTH)
	{
		init_rayc(&rayc);
		ft_init_var(cub, &rayc, x);
		get_side_dist(cub, &rayc);
		ft_dda(&rayc, cub);
		// printf("test\n");
		get_line_dist(cub, &rayc, x);
		draw_line(cub, x);
		x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->mlx_img, 0, 0);
	return (0);
}
